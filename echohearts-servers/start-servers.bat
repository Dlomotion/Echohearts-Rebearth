@echo off
echo Building multiplayer server (needs Visual Studio C++ or g++)...
where g++ >nul 2>&1 && g++ -std=c++17 multiplayer\src\server.cpp -o multiplayer\echohearts-server.exe -lws2_32 || echo g++ not found - build multiplayer\ with Visual Studio / CMake instead, then run echohearts-server.exe
start "EchoHearts Multiplayer" multiplayer\echohearts-server.exe 7777
echo Starting web server on http://127.0.0.1:8080
python web\server.py 8080
