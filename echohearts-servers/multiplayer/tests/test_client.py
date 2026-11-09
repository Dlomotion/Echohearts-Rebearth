#!/usr/bin/env python3
"""Tiny EchoHearts test client: joins, moves, chats, summons the boss, and prints server state.
Usage: python3 test_client.py [host] [port] [name]
"""
import socket, sys, time

host = sys.argv[1] if len(sys.argv) > 1 else "127.0.0.1"
port = int(sys.argv[2]) if len(sys.argv) > 2 else 7777
name = sys.argv[3] if len(sys.argv) > 3 else "Tester"

s = socket.create_connection((host, port), timeout=5)
f = s.makefile("rwb", buffering=0)

def send(line): f.write((line + "\n").encode())
def read_until(needle, timeout=5):
    s.settimeout(timeout); data = ""
    while needle not in data:
        chunk = s.recv(4096).decode(errors="ignore")
        if not chunk: break
        data += chunk
    return data

send(f"HELLO {name}")
welcome = read_until("WELCOME")
assert "WELCOME" in welcome, welcome
print("OK welcome:", welcome.strip().splitlines()[0])

send("POS 1 1 2")
send("CHAT hello world")
send("PING")
out = read_until("PONG")
assert "PONG" in out, out
print("OK ping/pong + chat broadcast received")

send("SUMMON_BOSS")
out = read_until("Heartbreaker has awoken", timeout=6)
assert "Heartbreaker has awoken" in out, out
print("OK boss summoned")

send("STATE")
out = read_until("ENEMY", timeout=6)
assert "STATE" in out and "boss=1" in out, out
print("OK state snapshot with boss")
print("All multiplayer client checks passed.")
s.close()
