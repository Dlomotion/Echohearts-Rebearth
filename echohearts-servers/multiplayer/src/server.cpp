// EchoHearts Rebirth — dedicated multiplayer server (C++17, no dependencies).
// Terraria-style dedicated server: one authoritative world, up to 8 players,
// day/night cycle, monsters + mischievous imps, and the Heartbreaker boss.
// The server owns enemy HP, contact damage, boss state, score and time —
// clients only send inputs/positions and render what the server broadcasts.
//
// Protocol is line-based text (see PROTOCOL.md) so anyone can debug it with
// netcat or a small script:  HELLO <name> / POS <x> <y> <z> / HIT <enemyId> <dmg> /
// CHAT <text> / SUMMON_BOSS / PING  ->  WELCOME / STATE / EVENT / CHAT / PONG
//
// Build:  g++ -std=c++17 -pthread -I ../../echohearts-rebirth-3d/src src/server.cpp -o echohearts-server
// Run:    ./echohearts-server [port]        (default 7777, Terraria's classic port)
#include <algorithm>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

#ifdef _WIN32
  #include <winsock2.h>
  #include <ws2tcpip.h>
  #pragma comment(lib, "Ws2_32.lib")
  using Socket = SOCKET;
  static const Socket kBad = INVALID_SOCKET;
#else
  #include <arpa/inet.h>
  #include <netinet/in.h>
  #include <sys/socket.h>
  #include <unistd.h>
  using Socket = int;
  static const Socket kBad = -1;
#endif

struct Player { int id; std::string name; Socket sock; float x=0,y=1,z=6; int hp=100; int score=0; bool active=true; };
struct Enemy { int id; std::string kind; float x,z; float hp, maxHp; int damage; bool enraged=false; };

static std::recursive_mutex g_mu;
static std::map<int, Player> g_players;
static std::map<int, Enemy> g_enemies;
static int g_nextPlayer = 1, g_nextEnemy = 1;
static int g_timeOfDay = 0; // 0..3599 frames, 1800+ = night
static bool g_bossAlive = false;
static std::atomic<bool> g_running{true};

static bool isNight() { return g_timeOfDay >= 1800; }
static void closeSocket(Socket s) {
#ifdef _WIN32
    closesocket(s);
#else
    if (s != kBad) ::close(s);
#endif
}
static bool sendLine(Socket s, const std::string& line) {
    std::string out = line + "\n";
    return ::send(s, out.c_str(), (int)out.size(), 0) >= 0;
}
static void broadcast(const std::string& line, int exceptId = -1) {
    std::lock_guard<std::recursive_mutex> lk(g_mu);
    for (auto& [id, p] : g_players) if (p.active && id != exceptId) sendLine(p.sock, line);
}
static std::string stateSnapshot() {
    std::ostringstream ss;
    ss << "STATE time=" << g_timeOfDay << (isNight() ? " night=1" : " night=0")
       << " players=" << g_players.size() << " enemies=" << g_enemies.size() << " boss=" << (g_bossAlive ? 1 : 0);
    for (auto& [id, p] : g_players) ss << "\nPLAYER id=" << id << " name=" << p.name << " x=" << p.x << " y=" << p.y << " z=" << p.z << " hp=" << p.hp << " score=" << p.score;
    for (auto& [id, e] : g_enemies) ss << "\nENEMY id=" << id << " kind=" << e.kind << " x=" << e.x << " z=" << e.z << " hp=" << (int)e.hp << " maxHp=" << (int)e.maxHp << (e.enraged ? " enraged=1" : "");
    return ss.str();
}
static void spawnEnemy(const std::string& kind, float aroundX, float aroundZ) {
    Enemy e; e.id = g_nextEnemy++; e.kind = kind;
    float a = (rand() % 628) / 100.0f; float r = 18.0f;
    e.x = aroundX + std::cos(a) * r; e.z = aroundZ + std::sin(a) * r;
    if (kind == "imp")     { e.hp = e.maxHp = 20;  e.damage = 12; }
    if (kind == "monster") { float s = isNight() ? 1.25f : 1.0f; e.hp = e.maxHp = 60 * s; e.damage = 20; }
    if (kind == "boss")    { e.hp = e.maxHp = 660; e.damage = 35; g_bossAlive = true; }
    g_enemies[e.id] = e;
    if (kind == "boss") broadcast("EVENT Heartbreaker has awoken!");
}

static void handleClient(Socket sock, int id) {
    char buf[1024]; std::string pending;
    while (g_running) {
        int n = ::recv(sock, buf, sizeof(buf) - 1, 0);
        if (n <= 0) break;
        buf[n] = 0; pending += buf;
        size_t pos;
        while ((pos = pending.find('\n')) != std::string::npos) {
            std::string line = pending.substr(0, pos); pending.erase(0, pos + 1);
            std::istringstream in(line); std::string cmd; in >> cmd;
            std::lock_guard<std::recursive_mutex> lk(g_mu);
            auto it = g_players.find(id); if (it == g_players.end()) continue;
            Player& me = it->second;
            if (cmd == "HELLO") { in >> me.name; if (me.name.empty()) me.name = "Player"; sendLine(sock, "WELCOME id=" + std::to_string(id) + " world=EchoHearts-Rebearth maxPlayers=8"); broadcast("EVENT " + me.name + " joined the world", id); }
            else if (cmd == "POS") { in >> me.x >> me.y >> me.z; }
            else if (cmd == "CHAT") { std::string msg; std::getline(in, msg); broadcast("CHAT " + me.name + ":" + msg); }
            else if (cmd == "HIT") { int eid; float raw; in >> eid >> raw; auto e = g_enemies.find(eid); if (e != g_enemies.end()) { int def = e->second.kind=="boss"?6:(e->second.kind=="monster"?2:0); float dealt = std::max(1.0f, raw - def); e->second.hp -= dealt; if (e->second.kind=="boss" && !e->second.enraged && e->second.hp < e->second.maxHp*0.25f) { e->second.enraged = true; broadcast("EVENT Heartbreaker ENRAGED!"); } if (e->second.hp <= 0) { me.score += e->second.kind=="boss"?300:(e->second.kind=="monster"?25:15); if (e->second.kind=="boss") { g_bossAlive = false; broadcast("EVENT Boss defeated by " + me.name + "! Rebirth for the world."); } else broadcast("EVENT " + me.name + " defeated a " + e->second.kind); g_enemies.erase(e); } } }
            else if (cmd == "SUMMON_BOSS") { if (!g_bossAlive) spawnEnemy("boss", me.x, me.z); }
            else if (cmd == "PING") { sendLine(sock, "PONG"); }
            else if (cmd == "STATE") { sendLine(sock, stateSnapshot()); }
        }
    }
    { std::lock_guard<std::recursive_mutex> lk(g_mu); auto it = g_players.find(id); if (it != g_players.end()) { broadcast("EVENT " + it->second.name + " left the world", id); g_players.erase(it); } }
    closeSocket(sock);
}

// Authoritative world tick: day/night, enemy chase, spawns, state broadcast.
static void worldTick() {
    int tick = 0;
    while (g_running) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // 10 ticks/sec broadcast
        std::lock_guard<std::recursive_mutex> lk(g_mu);
        g_timeOfDay = (g_timeOfDay + 6) % 3600; tick++; // 6 frames per tick ~= real-time cycle pace
        float cx = 0, cz = 0; int n = 0;
        for (auto& [id, p] : g_players) { cx += p.x; cz += p.z; n++; }
        if (n) { cx /= n; cz /= n; }
        int spawnEvery = isNight() ? 40 : 80; // ticks
        if (n && tick % spawnEvery == 0 && (int)g_enemies.size() < 24) spawnEnemy(rand() % 2 ? "imp" : "monster", cx, cz);
        if (n && !g_bossAlive && tick % 900 == 0) spawnEnemy("boss", cx, cz); // boss returns periodically
        for (auto& [id, e] : g_enemies) {
            // Chase nearest player
            float best = 1e9, tx = cx, tz = cz;
            for (auto& [pid, p] : g_players) { float d = std::hypot(p.x - e.x, p.z - e.z); if (d < best) { best = d; tx = p.x; tz = p.z; } }
            float sp = (e.kind == "boss" ? 0.35f : e.kind == "monster" ? 0.45f : 0.7f) * (e.enraged ? 1.5f : 1.0f);
            if (best > 1.5f) { e.x += (tx - e.x) / (best + 0.001f) * sp; e.z += (tz - e.z) / (best + 0.001f) * sp; }
        }
        if (n) { std::string s = stateSnapshot(); for (auto& [id, p] : g_players) if (p.active) sendLine(p.sock, s); }
    }
}

int main(int argc, char** argv) {
    int port = argc > 1 ? std::stoi(argv[1]) : 7777;
    srand(12345);
#ifdef _WIN32
    WSADATA wsa; WSAStartup(MAKEWORD(2,2), &wsa);
#endif
    Socket listener = ::socket(AF_INET, SOCK_STREAM, 0);
    if (listener == kBad) { std::cerr << "socket failed\n"; return 1; }
    int opt = 1; ::setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, (const char*)&opt, sizeof(opt));
    sockaddr_in addr{}; addr.sin_family = AF_INET; addr.sin_addr.s_addr = INADDR_ANY; addr.sin_port = htons((uint16_t)port);
    if (::bind(listener, (sockaddr*)&addr, sizeof(addr)) != 0) { std::cerr << "bind failed on port " << port << "\n"; return 1; }
    ::listen(listener, 16);
    std::cout << "EchoHearts dedicated server listening on port " << port << " (max 8 players, world: EchoHearts-Rebearth)\n";
    std::thread(worldTick).detach();
    while (g_running) {
        Socket client = ::accept(listener, nullptr, nullptr);
        if (client == kBad) continue;
        int id;
        { std::lock_guard<std::recursive_mutex> lk(g_mu); if ((int)g_players.size() >= 8) { sendLine(client, "FULL server is full (8)"); closeSocket(client); continue; } id = g_nextPlayer++; g_players[id] = Player{id, "Player", client}; }
        std::thread(handleClient, client, id).detach();
    }
    closeSocket(listener);
    return 0;
}
