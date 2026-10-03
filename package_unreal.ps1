# Requires PowerShell 7 on the authorized Windows UE 5.8 runner.
[CmdletBinding()]
param(
    [string]$EngineRoot = 'C:\Program Files\Epic Games\UE_5.8',
    [ValidatePattern('^/Game/(?:[A-Za-z0-9_]+/)*[A-Za-z0-9_]+$')]
    [Parameter(Mandatory=$true)][string]$MapPackage
)
Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'
if (-not $IsWindows) { throw 'Windows and PowerShell 7 are required.' }
function Invoke-Checked([string]$Program, [string[]]$Arguments) {
    & $Program @Arguments
    if ($LASTEXITCODE -ne 0) { throw "$Program failed: $LASTEXITCODE" }
}
$project = Join-Path $PSScriptRoot 'EchoheartsRebearth.uproject'
$evidence = Join-Path $PSScriptRoot 'BuildEvidence'
$output = Join-Path $PSScriptRoot 'PackagedOutput'
# A clean checkout is required; reject stale evidence instead of accepting a prior run.
foreach ($path in @($evidence, $output)) {
    if (Test-Path $path) { throw "Stale output exists; use a clean checkout: $path" }
}
New-Item -ItemType Directory -Path $evidence | Out-Null
Start-Transcript -Path (Join-Path $evidence 'pipeline.log')
$status = 'FAILED'
try {
    $version = Get-Content (Join-Path $EngineRoot 'Engine/Build/Build.version') -Raw | ConvertFrom-Json
    if ($version.MajorVersion -ne 5 -or $version.MinorVersion -ne 8) { throw 'UE 5.8 required.' }
    $descriptor = Get-Content $project -Raw | ConvertFrom-Json
    if ($descriptor.EngineAssociation -ne '5.8') { throw 'Project must declare UE 5.8.' }
    foreach ($relative in @('Source/EchoheartsRebearthEditor.Target.cs',
        'Source/EchoheartsRebearth.Target.cs',
        'Source/EchoheartsRebearth/EchoheartsRebearth.Build.cs')) {
        if (-not (Test-Path (Join-Path $PSScriptRoot $relative))) { throw "Missing foundation: $relative" }
    }
    $build = Join-Path $EngineRoot 'Engine/Build/BatchFiles/Build.bat'
    $uat = Join-Path $EngineRoot 'Engine/Build/BatchFiles/RunUAT.bat'
    $editor = Join-Path $EngineRoot 'Engine/Binaries/Win64/UnrealEditor-Cmd.exe'
    foreach ($path in @($build, $uat, $editor)) {
        if (-not (Test-Path $path -PathType Leaf)) { throw "Missing engine executable: $path" }
    }
    $mapFile = Join-Path $PSScriptRoot ('Content/' + $MapPackage.Substring(6) + '.umap')
    if (-not (Test-Path $mapFile -PathType Leaf)) { throw "Missing authored map: $mapFile" }
    Invoke-Checked 'git' @('lfs', 'fsck')
    $report = Join-Path $evidence 'Automation'
    Invoke-Checked $build @('EchoheartsRebearthEditor', 'Win64', 'Development', "-Project=$project", '-WaitMutex')
    Invoke-Checked $editor @($project, '-unattended', '-nop4', '-nosplash', '-NullRHI',
        '-ExecCmds=Automation RunTests Echohearts.Partners.CommandBuffer',
        '-TestExit=Automation Test Queue Empty', "-ReportExportPath=$report",
        "-abslog=$evidence/Automation.log")
    $result = Get-Content (Join-Path $report 'index.json') -Raw | ConvertFrom-Json
    if ($result.failed -ne 0 -or $result.notRun -ne 0 -or $result.inProcess -ne 0 -or $result.succeeded -lt 1) {
        throw 'Automation report must contain passing tests and no failed, pending, or skipped tests.'
    }
    $tests = @($result.tests)
    if ($tests.Count -eq 0) { throw 'Empty Automation test report.' }
    foreach ($test in $tests) {
        if ($test.state -ne 'Success' -or $test.fullTestPath -notlike 'Echohearts.Partners.CommandBuffer*') {
            throw 'Unexpected or unsuccessful Automation test result.'
        }
    }
    Invoke-Checked $uat @('BuildCookRun', "-project=$project", '-noP4', '-unattended',
        '-target=EchoheartsRebearth', '-platform=Win64', '-clientconfig=Development',
        "-map=$MapPackage", '-build', '-cook', '-stage', '-pak', '-package', '-archive',
        "-archivedirectory=$output")
    $executables = @(Get-ChildItem $output -Filter '*.exe' -Recurse -File)
    if ($executables.Count -eq 0) { throw 'No packaged executable produced.' }
    $executables | Get-FileHash -Algorithm SHA256 | Export-Csv (Join-Path $evidence 'sha256.csv') -NoTypeInformation
    $commit = (& git rev-parse HEAD).Trim()
    if ($LASTEXITCODE -ne 0) { throw 'Unable to identify source commit.' }
    $buildId = if ($env:GITHUB_RUN_ID) { "$($env:GITHUB_RUN_ID)-$($env:GITHUB_RUN_ATTEMPT)" } else { [guid]::NewGuid().ToString('N') }
    @{
        game_name = 'Echohearts: Rebearth'
        package_code = 'ECO-PKG-WIN64-DEV'
        engine = '5.8'
        configuration = 'Development'
        source_commit = $commit
        build_id = $buildId
        version = 'unversioned'
        created_utc = [DateTime]::UtcNow.ToString('o')
        runtime_status = 'NOT_VERIFIED'
        recovery_status = 'NOT_RUN'
    } | ConvertTo-Json | Set-Content (Join-Path $output 'build-metadata.json')
    $status = 'BUILD_TEST_PACKAGE_PASSED_RUNTIME_UNVERIFIED'
}
finally {
    @("Status: $status", "Commit: $(git rev-parse HEAD)", "UTC: $([DateTime]::UtcNow.ToString('o'))",
      'Recovery at 150/250/350 ms and ECO-API-001 remain separate blocked gates.') |
        Set-Content (Join-Path $evidence 'BuildReport.txt')
    Stop-Transcript
}
