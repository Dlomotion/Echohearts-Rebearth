// EchoHearts Rebirth 3D — a 3D action game in C++ with raylib.
// Original code. Terraria-style generic rules live in GameLogic.h:
// HP hearts (20 HP each), mana/stars, contact damage + i-frames,
// knockback, crits, defence, drops, day/night, boss awaken + enrage.
//
// Controls:
//   WASD        Move (camera-relative)      Mouse / Arrow Left-Right  Turn camera
//   Space       Jump                        Shift                   Sprint
//   Left Click / F   Echo Pulse (22 dmg)    R                       Echo Burst (55 dmg, 30 mana)
//   B           Summon the Heartbreaker boss (once per level, at night or after 10 hearts)
//   P           Pause                       Esc                     Close
#include "raylib.h"
#include "GameLogic.h"
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace echohearts;

struct Enemy3D {
    EnemyState state;
    Vector3 pos;
    float radius;
    float speed;
    int t = 0;
    Color color;
    Enemy3D(EnemyKind k, Vector3 p, bool night, int level)
        : state(k, night, level), pos(p) {
        auto s = statsFor(k, night, level);
        radius = (k == EnemyKind::Boss) ? 2.2f : (k == EnemyKind::Monster ? 1.1f : 0.8f);
        speed = (k == EnemyKind::Boss) ? 2.2f : (k == EnemyKind::Monster ? 2.6f : 4.2f);
        color = (k == EnemyKind::Boss) ? RED : (k == EnemyKind::Monster ? DARKGREEN : PURPLE);
        (void)s;
    }
};
struct HeartPickup { Vector3 pos; bool isStar; };
struct Projectile { Vector3 pos; Vector3 vel; float damage; float knockback; bool burst; bool fromBoss; int life = 90; };
struct FloatText { Vector3 pos; std::string str; Color color; int life = 50; };
struct Tree { Vector3 pos; };
struct Block { Vector3 pos; Color color; };

static float distXZ(Vector3 a, Vector3 b) { float dx=a.x-b.x, dz=a.z-b.z; return std::sqrt(dx*dx+dz*dz); }

int main() {
    const int W = 1280, H = 720;
    InitWindow(W, H, "EchoHearts Rebirth 3D");
    SetTargetFPS(60);

    // World: trees + decorative blocks (Terraria-like gathering scenery)
    std::vector<Tree> trees; std::vector<Block> blocks;
    for (int i = 0; i < 40; i++) trees.push_back({{(float)GetRandomValue(-48,48), 0, (float)GetRandomValue(-48,48)}});
    for (int i = 0; i < 24; i++) blocks.push_back({{(float)GetRandomValue(-45,45), 0.5f, (float)GetRandomValue(-45,45)}, BROWN});

    PlayerState player;
    Vector3 pPos{0, 1.0f, 6.0f};
    float pVelY = 0, camYaw = 0;
    int score = 0, heartsCollected = 0, level = 1, kills = 0, frame = 0, timeOfDay = 0;
    int lastShot = -99, lastBurst = -99;
    bool paused = false, gameOver = false, bossAlive = false, bossSpawnedForLevel = false;
    std::string banner; int bannerLife = 0;

    std::vector<Enemy3D> enemies;
    std::vector<HeartPickup> pickups;
    std::vector<Projectile> shots;
    std::vector<FloatText> texts;
    auto spawnPickup = [&](bool star){ pickups.push_back({{(float)GetRandomValue(-40,40), 1.0f, (float)GetRandomValue(-40,40)}, star}); };
    for (int i = 0; i < 6; i++) spawnPickup(false);
    auto spawnEnemy = [&](EnemyKind k){
        float a = (float)GetRandomValue(0, 628) / 100.0f;
        Vector3 p{ pPos.x + std::cos(a)*22.0f, (k==EnemyKind::Boss?2.2f:1.0f), pPos.z + std::sin(a)*22.0f };
        enemies.emplace_back(k, p, isNight(timeOfDay), level);
        if (k == EnemyKind::Boss) { bossAlive = true; banner = "Heartbreaker has awoken!"; bannerLife = 240; }
    };

    Camera3D cam{}; cam.up = {0,1,0}; cam.fovy = 60; cam.projection = CAMERA_PERSPECTIVE;

    while (!WindowShouldClose()) {
        // ---------- Update ----------
        if (IsKeyPressed(KEY_P)) paused = !paused;
        if (!paused && !gameOver) {
            frame++; timeOfDay = (timeOfDay + 1) % 3600;
            if (bannerLife > 0) bannerLife--;

            // Camera turn
            if (IsKeyDown(KEY_LEFT)) camYaw += 0.03f;
            if (IsKeyDown(KEY_RIGHT)) camYaw -= 0.03f;
            camYaw -= GetMouseDelta().x * 0.003f;

            // Movement (camera-relative), with gravity + jump like a platformer
            Vector3 fwd{ std::sin(camYaw), 0, std::cos(camYaw) };
            Vector3 right{ fwd.z, 0, -fwd.x };
            Vector3 move{0,0,0};
            if (IsKeyDown(KEY_W)) { move.x += fwd.x; move.z += fwd.z; }
            if (IsKeyDown(KEY_S)) { move.x -= fwd.x; move.z -= fwd.z; }
            if (IsKeyDown(KEY_A)) { move.x -= right.x; move.z -= right.z; }
            if (IsKeyDown(KEY_D)) { move.x += right.x; move.z += right.z; }
            bool moving = (move.x != 0 || move.z != 0);
            if (moving) { float l = std::sqrt(move.x*move.x + move.z*move.z); float sp = IsKeyDown(KEY_LEFT_SHIFT) ? 10.0f : 6.5f; pPos.x += move.x/l*sp*GetFrameTime(); pPos.z += move.z/l*sp*GetFrameTime(); }
            pPos.x = std::clamp(pPos.x, -49.0f, 49.0f); pPos.z = std::clamp(pPos.z, -49.0f, 49.0f);
            if (IsKeyPressed(KEY_SPACE) && pPos.y <= 1.01f) pVelY = 9.0f;
            pVelY -= 22.0f * GetFrameTime(); pPos.y += pVelY * GetFrameTime();
            if (pPos.y < 1.0f) { pPos.y = 1.0f; pVelY = 0; }
            player.tick(moving);

            // Shooting — aim is camera forward
            auto shoot = [&](bool burst){
                const WeaponStats& w = burst ? kEchoBurst : kEchoPulse;
                int& last = burst ? lastBurst : lastShot;
                if (frame - last < w.useTimeFrames) return;
                if (burst && !player.spendMana(w.manaCost)) { texts.push_back({pPos, "Not enough mana", SKYBLUE, 40}); return; }
                last = frame;
                bool crit = rollCrit(GetRandomValue(0,99), w.critPercent);
                Vector3 dir{ -std::sin(camYaw), 0.15f, -std::cos(camYaw) };
                shots.push_back({ {pPos.x, pPos.y+0.4f, pPos.z}, {dir.x*28, dir.y*28, dir.z*28}, (float)w.damage * (crit?1.0f:1.0f), w.knockback, burst, false });
                shots.back().damage = (float)w.damage; // crit doubled inside takeHit via flag below
                if (crit) shots.back().damage = (float)w.damage; // damageEnemy applies crit flag separately
                shots.back().fromBoss = false;
                // store crit by doubling flag through burst field reuse is avoided: use life marker
                // (simple approach) crit shots are bigger/yellow via damage value check in draw
                if (crit) shots.back().life = 91; // 91 marks a crit shot
            };
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsKeyDown(KEY_F)) shoot(false);
            if (IsKeyPressed(KEY_R)) shoot(true);
            if (IsKeyPressed(KEY_B) && !bossAlive && (isNight(timeOfDay) || heartsCollected >= 10)) { spawnEnemy(EnemyKind::Boss); bossSpawnedForLevel = true; }

            // Spawning (night = faster, Terraria day/night rule)
            if (frame % spawnIntervalFrames(timeOfDay) == 0) spawnEnemy(GetRandomValue(0,1) ? EnemyKind::Imp : EnemyKind::Monster);
            if ((int)pickups.size() < 4 && GetRandomValue(0,100) < 1) spawnPickup(false);
            if (level % 3 == 0 && !bossSpawnedForLevel && !bossAlive && heartsCollected > 0) { spawnEnemy(EnemyKind::Boss); bossSpawnedForLevel = true; }

            // Pickups: hearts heal/collect, stars restore mana
            for (auto& pk : pickups) if (distXZ(pPos, pk.pos) < 1.6f) {
                if (pk.isStar) { player.mana = std::min(player.maxMana, player.mana + 50); texts.push_back({pPos, "+50 Mana", SKYBLUE, 40}); }
                else { heartsCollected++; score += 10; player.heal(5); texts.push_back({pPos, "+ Heart", GOLD, 40});
                       level = heartsCollected/5 + 1; if (level%3!=0) bossSpawnedForLevel=false; }
                pk.pos.x = 9999; // consumed, removed below
            }
            pickups.erase(std::remove_if(pickups.begin(), pickups.end(), [](const HeartPickup& p){ return p.pos.x > 9000; }), pickups.end());

            // Projectiles vs enemies / player
            for (auto& s : shots) {
                s.pos.x += s.vel.x*GetFrameTime(); s.pos.y += s.vel.y*GetFrameTime(); s.pos.z += s.vel.z*GetFrameTime(); s.life--;
                if (s.fromBoss) { if (distXZ(s.pos, pPos) < 1.2f && std::abs(s.pos.y-pPos.y) < 1.6f) { float d = player.takeContactDamage(s.damage); if (d>0) texts.push_back({pPos, "-"+std::to_string((int)d), RED, 40}); s.life = 0; } continue; }
                for (auto& e : enemies) if (e.state.alive() && distXZ(s.pos, e.pos) < e.radius + 0.5f) {
                    bool crit = (s.life == 91);
                    float dealt = e.state.takeHit(s.damage, crit);
                    float a = std::atan2(s.vel.z, s.vel.x); float kb = s.knockback * (1.0f - e.state.kbResist);
                    e.pos.x += std::cos(a)*kb*0.25f; e.pos.z += std::sin(a)*kb*0.25f;
                    texts.push_back({e.pos, std::to_string((int)dealt) + (crit?"!":""), crit?GOLD:WHITE, 45});
                    if (e.state.checkEnrage()) { banner = "Heartbreaker ENRAGED!"; bannerLife = 180; }
                    s.life = 0; break;
                }
            }
            shots.erase(std::remove_if(shots.begin(), shots.end(), [](const Projectile& s){ return s.life<=0 || s.pos.y < 0; }), shots.end());

            // Enemies: chase, contact damage, boss attacks
            for (auto& e : enemies) {
                e.t++;
                float dx = pPos.x - e.pos.x, dz = pPos.z - e.pos.z; float d = std::sqrt(dx*dx+dz*dz)+0.001f;
                float sp = e.speed * (e.state.enraged ? 1.5f : 1.0f);
                if (d > e.radius + 0.8f) { e.pos.x += dx/d*sp*GetFrameTime(); e.pos.z += dz/d*sp*GetFrameTime(); }
                else { float dealt = player.takeContactDamage(statsFor(e.state.kind, isNight(timeOfDay), level).contactDamage); if (dealt>0) texts.push_back({pPos, "-"+std::to_string((int)dealt), RED, 40}); }
                if (e.state.kind == EnemyKind::Boss) {
                    if (e.t % (e.state.enraged ? 55 : 90) == 0) shots.push_back({e.pos, {dx/d*12, 1.0f, dz/d*12}, 15, 0, false, true});
                    if (e.t % 420 == 0) spawnEnemy(EnemyKind::Imp);
                }
                if (!e.state.alive()) {
                    kills++; score += statsFor(e.state.kind, false, level).score;
                    const char* drop = dropForRoll(GetRandomValue(0,99));
                    if (drop == std::string("heart")) pickups.push_back({e.pos, false});
                    else if (drop == std::string("star")) pickups.push_back({e.pos, true});
                    if (e.state.kind == EnemyKind::Boss) { bossAlive = false; score += 100; player.maxHp = std::min(200.0f, player.maxHp+20); player.heal(40); player.defence += 1; banner = "REBIRTH! +20 Max HP, +1 Defence"; bannerLife = 240; level++; }
                }
            }
            enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [](const Enemy3D& e){ return !e.state.alive(); }), enemies.end());
            for (auto& t : texts) { t.pos.y += GetFrameTime()*1.5f; t.life--; }
            texts.erase(std::remove_if(texts.begin(), texts.end(), [](const FloatText& t){ return t.life<=0; }), texts.end());
            if (player.hp <= 0) gameOver = true;
        }

        // Camera follows behind player
        cam.target = pPos;
        cam.position = { pPos.x + std::sin(camYaw)*11.0f, pPos.y + 6.0f, pPos.z + std::cos(camYaw)*11.0f };

        // ---------- Draw ----------
        bool night = isNight(timeOfDay);
        BeginDrawing();
        ClearBackground(night ? Color{10,10,35,255} : Color{110,190,235,255});
        BeginMode3D(cam);
        DrawPlane({0,0,0}, {100,100}, night ? DARKGREEN : GREEN);
        DrawGrid(50, 2.0f);
        for (auto& tr : trees) { DrawCylinder({tr.pos.x,1.5f,tr.pos.z}, 0.3f,0.4f,3.0f,8,BROWN); DrawSphere({tr.pos.x,4.0f,tr.pos.z},1.6f,DARKGREEN); }
        for (auto& b : blocks) DrawCube(b.pos, 1,1,1, b.color);
        for (auto& pk : pickups) { if (pk.isStar) DrawSphere(pk.pos, 0.45f, SKYBLUE); else { DrawSphere(pk.pos, 0.5f, PINK); DrawSphereWires(pk.pos, 0.55f, 6, 6, GOLD); } }
        for (auto& s : shots) DrawSphere(s.pos, s.burst?0.45f:0.28f, s.fromBoss ? VIOLET : (s.life==91 ? GOLD : SKYBLUE));
        for (auto& e : enemies) {
            DrawSphere(e.pos, e.radius, e.color); DrawSphereWires(e.pos, e.radius+0.05f, 8, 8, BLACK);
            if (e.state.kind == EnemyKind::Imp) { DrawCylinder({e.pos.x-0.4f, e.pos.y+e.radius, e.pos.z}, 0.0f, 0.25f, 0.7f, 8, GOLD); DrawCylinder({e.pos.x+0.4f, e.pos.y+e.radius, e.pos.z}, 0.0f, 0.25f, 0.7f, 8, GOLD); }
            if (e.state.kind == EnemyKind::Boss) DrawCube({e.pos.x, e.pos.y+e.radius+0.6f, e.pos.z}, 1.2f,0.5f,1.2f, GOLD);
        }
        // Player: body + heart, blink during i-frames
        if (!(player.iframes > 0 && (frame/4)%2==0)) { DrawCapsule({pPos.x,pPos.y-0.6f,pPos.z},{pPos.x,pPos.y+0.6f,pPos.z},0.7f,8,12,MAROON); DrawSphere({pPos.x,pPos.y+0.35f,pPos.z},0.42f, Color{255,90,138,255}); }
        EndMode3D();

        // HUD — Terraria-style hearts / mana
        DrawText(TextFormat("Score %d   Hearts %d   Level %d   Kills %d", score, heartsCollected, level, kills), 16, 14, 22, WHITE);
        DrawText(TextFormat("HP %d/%d  %s   Mana %d/%d", (int)player.hp, (int)player.maxHp, std::string(player.heartsDisplay(),'@').c_str(), (int)player.mana, (int)player.maxMana), 16, 42, 20, WHITE);
        DrawText(night ? "Night - monsters stronger & more frequent" : "Day", 16, 68, 18, night ? VIOLET : YELLOW);
        DrawText("WASD move | Space jump | Click/F Echo Pulse | R Echo Burst (30 mana) | B summon boss | P pause", 16, H-28, 17, WHITE);
        for (auto& e : enemies) if (e.state.kind == EnemyKind::Boss) { DrawRectangle(240, 92, 800, 20, Color{0,0,0,160}); DrawRectangle(240, 92, (int)(800 * (e.state.hp/e.state.maxHp)), 20, RED); DrawText("HEARTBREAKER BOSS", 240, 70, 20, RED); }
        if (!banner.empty() && bannerLife > 0) DrawText(banner.c_str(), W/2 - MeasureText(banner.c_str(),30)/2, 120, 30, GOLD);
        for (auto& t : texts) { Vector2 sp = GetWorldToScreen(t.pos, cam); DrawText(t.str.c_str(), (int)sp.x, (int)sp.y, 18, t.color); }
        if (paused) DrawText("PAUSED", W/2-60, H/2, 32, WHITE);
        if (gameOver) { DrawRectangle(0,0,W,H, Color{0,0,0,180}); DrawText("You were slain...", W/2-130, H/2-40, 36, RED); DrawText(TextFormat("Score %d - close and rerun to be reborn", score), W/2-190, H/2, 22, WHITE); }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
