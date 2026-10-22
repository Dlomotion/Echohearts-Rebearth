# UE5.8 MCP Setup Guide — AI Bridge Into the Editor
**Research only, checked 2026-10-15. No project changes made.** This guide is for the Windows UE 5.8.3 machine, when you're building in-engine.

## What it is
Unreal Engine 5.8 ships an official **Unreal MCP** plugin (identifier `ModelContextProtocol`, under `Engine/Plugins/Experimental`). It runs a Model Context Protocol server *inside the editor process*, so an AI assistant (Claude Code, Cursor, VS Code, Gemini, Codex) can inspect and operate the editor directly — spawning actors, editing materials, working with Blueprints, running automation tests — instead of just describing steps in chat.

> **Status: experimental, not production-safe.** Epic's own docs warn the feature is incomplete in places, APIs and data formats may change, and it is not designed for remote use. Treat it as a power tool for your own machine, not infrastructure.

## Exact version & dates (checked 2026-10-15)
- Introduced in **UE 5.8** (released June 17, 2026, Unreal Fest Chicago). It does **not** exist in 5.7.
- Community-verified working on **5.8.2** (macOS/arm64 build: clean compile, all five plugin modules load, meta-tools register).
- Your target is **5.8.3** — the plugin ships in the same Experimental location; 5.8.3-specific behavior is unverified by me.
- Also available in UEFN since August 20, 2026 (not your path — you're on full UE).

## Setup (on the UE machine)
1. Open your project in the UE 5.8.3 editor.
2. Enable two plugins: **ModelContextProtocol** (off by default) and **All Toolsets** (required dependency; it also pulls in EngineAssetDefinitions and ToolsetRegistry).
3. The editor starts the MCP server on `http://127.0.0.1:8000/mcp` — loopback only, no authentication.
4. Generate your assistant's config from the editor console: `ModelContextProtocol.GenerateClientConfig` with your client (`ClaudeCode`, `Cursor`, `VSCode`, `Gemini`, `Codex`, or `All`).
5. Connect your assistant to that local endpoint.

## Capabilities — verified vs unverified
**Verified** (Epic documentation + independent community reports):
- MCP server embedded in the editor process, loopback HTTP/SSE
- Actor spawning, inspection, and editing via agent tools
- Material instance creation and material-graph tools
- Blueprint tools (creation, node editing)
- Slate widget inspection
- Automation test execution
- Client config generation for the five listed assistants

**Unverified** (not tested by me — confirm on your machine):
- Behavior on exactly 5.8.3 (sources verify 5.8.2)
- Behavior inside *your* Echohearts project specifically
- What, if anything, the plugin's runtime modules do in a packaged build (its modules are Runtime + Editor; nothing in a sample project called into it)

## Safety rules
- **Local only.** No authentication on the loopback server — anyone with access to that machine can drive your editor. Never expose the port beyond localhost.
- **One at a time.** Tool calls execute serially on the game thread; don't fire overlapping calls.
- **You stay the approver.** The agent proposes and executes editor actions; review diffs and asset changes before saving, especially anything touching canon content.
- **Keep it out of packaged builds** until Epic declares it production-ready. Editor tooling only.

## Community alternative (noted, not recommended)
`versatile-unreal-mcp` (open-source fork): native plugin + separate Python MCP server, validated on UE 5.7, targets 5.5+. Adds UMG editing and input-mapping tools. Prefer Epic's official plugin — it's the one that will track the engine.

## When to turn this on
Once your project opens in UE 5.8.3 on Windows and you've done a first successful editor launch. Not before — there's no editor here to connect to yet, and that's fine.
