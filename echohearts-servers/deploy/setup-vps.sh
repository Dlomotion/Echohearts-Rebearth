#!/usr/bin/env bash
# EchoHearts VPS setup (Ubuntu/Debian): deps, firewall, systemd service.
# Run as root from the echohearts-servers/ folder:  sudo bash deploy/setup-vps.sh
set -euo pipefail
SERVERS_DIR="$(cd "$(dirname "$0")/.." && pwd)"
REPO_ROOT="$(cd "$SERVERS_DIR/.." && pwd)"

echo "==> Installing build tools + Python"
apt-get update -qq
apt-get install -y -qq g++ python3 git ufw >/dev/null

echo "==> Building multiplayer server"
g++ -std=c++17 -pthread -O2 "$SERVERS_DIR/multiplayer/src/server.cpp" -o "$SERVERS_DIR/multiplayer/echohearts-server"

echo "==> Opening firewall ports 8080 (web) and 7777 (multiplayer)"
ufw allow 8080/tcp || true
ufw allow 7777/tcp || true
ufw --force enable || true

echo "==> Installing systemd service"
sed -e "s|__REPO_ROOT__|$REPO_ROOT|g" -e "s|__SERVERS_DIR__|$SERVERS_DIR|g" \
  "$SERVERS_DIR/deploy/echohearts.service" > /etc/systemd/system/echohearts.service
systemctl daemon-reload
systemctl enable --now echohearts

echo "==> Done. Status:"
systemctl --no-pager status echohearts || true
IP="$(curl -s ifconfig.me || echo '<server-ip>')"
echo ""
echo "Friends can play at:  http://$IP:8080   (multiplayer join: $IP:7777)"
