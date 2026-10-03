param(
    [string]$EngineRoot = "C:\Program Files\Epic Games\UE_5.8",
    [string]$ProjectPath = "$PSScriptRoot\EchoheartsRebearth.uproject",
    [string]$Configuration = "Development",
    [string]$OutputDirectory = "$PSScriptRoot\PackagedOutput"
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

if (-not (Test-Path $EngineRoot)) {
    throw "UE 5.8 engine root not found: $EngineRoot"
}

$BuildBat = Join-Path $EngineRoot "Engine\Build\BatchFiles\Build.bat"
$UatBat = Join-Path $EngineRoot "Engine\Build\BatchFiles\RunUAT.bat"
$UbtExe = Join-Path $EngineRoot "Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe"
$EditorExe = Join-Path $EngineRoot "Engine\Binaries\Win64\UE4Editor.exe"

if (-not (Test-Path $ProjectPath)) {
    throw "Project file not found: $ProjectPath"
}

if (-not (Test-Path $BuildBat)) {
    throw "Build.bat not found: $BuildBat"
}

if (-not (Test-Path $UatBat)) {
    throw "RunUAT.bat not found: $UatBat"
}

if (-not (Test-Path $UbtExe)) {
    throw "UnrealBuildTool.exe not found: $UbtExe"
}

if (-not (Test-Path $EditorExe)) {
    throw "UE4Editor.exe not found: $EditorExe"
}

Write-Host "UE 5.8 engine and project validated."
Write-Host "EngineRoot: $EngineRoot"
Write-Host "ProjectPath: $ProjectPath"
Write-Host "Configuration: $Configuration"
Write-Host "OutputDirectory: $OutputDirectory"

New-Item -ItemType Directory -Force -Path $OutputDirectory | Out-Null

& $BuildBat -Project="$ProjectPath" -Target="EchoheartsEditor" -Platform="Win64" -Configuration="$Configuration"

& $UatBat BuildCookRun `
    -project="$ProjectPath" `
    -noP4 `
    -platform=Win64 `
    -clientconfig=$Configuration `
    -serverconfig=$Configuration `
    -cook `
    -allmaps `
    -build `
    -stage `
    -pak `
    -archive `
    -archivedirectory="$OutputDirectory"

Write-Host "Unreal packaging sequence completed."
