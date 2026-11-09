# Hosting EchoHearts so friends can join

The servers are two processes: **web on port 8080** (the game in a browser) and **multiplayer on port 7777** (the shared world). Pick either path — both are prepared.

## Path 1 — Your own PC (free, online only while your PC is on)

1. Clone the repo and start the servers:
   - Windows: run `echohearts-servers\start-servers.bat`
   - Linux/macOS: `./echohearts-servers/start-servers.sh`
2. Allow the ports through your PC firewall when Windows asks (or add inbound rules for TCP 8080 and 7777).
3. **Port forwarding on your router** (this is the step that lets the internet reach your PC):
   - Log in to your router (often http://192.168.0.1 or http://192.168.1.1).
   - Find **Port Forwarding / Virtual Server / NAT**.
   - Add two rules, both pointing to your PC's local IP (find it with `ipconfig` on Windows — e.g. 192.168.1.50). Tip: give your PC a DHCP reservation/static IP so the rules keep working.
     - External 8080 → 192.168.x.x : 8080 (TCP)
     - External 7777 → 192.168.x.x : 7777 (TCP)
4. Find your public IP at https://whatismyipaddress.com — friends use:
   - Game in browser: `http://<your-public-ip>:8080`
   - Multiplayer join: `<your-public-ip>:7777`
5. Notes: many ISPs use CGNAT — if port forwarding "doesn't work" and your router's WAN IP starts with 100.64–100.127, ask your ISP for a public IP or use Path 2. Home upload speed is shared by everyone who joins.

## Path 2 — VPS / cloud host (always online, ~$5/mo class machine is plenty)

Works on any Ubuntu/Debian VPS (Hetzner, DigitalOcean, Linode, AWS Lightsail, etc.):

```bash
git clone https://github.com/Dlomotion/Echohearts-Rebearth.git
cd Echohearts-Rebearth/echohearts-servers
sudo bash deploy/setup-vps.sh        # installs g++/python, opens 8080+7777 in ufw, installs the systemd service
```

Then:
- Friends open `http://<vps-ip>:8080` and join multiplayer at `<vps-ip>:7777`.
- Also open 8080/7777 in the provider's own firewall panel if it has one (Lightsail and some others do).
- Manage it: `systemctl status echohearts` · `journalctl -u echohearts -f` · update with `git pull` then `systemctl restart echohearts`.
- Prefer containers? `docker compose up --build -d` from `echohearts-servers/` works instead of the systemd path (fixed in commit a762d2e — the web build context is the repo root).

## Which should I pick?
- Just playing with friends tonight → **Path 1**.
- A world that's up whenever, without your PC → **Path 2**.
