<#
Read-only Echohearts inventory for Windows PowerShell 5.1+.
Example:
  .\ReadOnly-EchoheartsInventory.ps1 -Roots 'D:\boot\Owens\AppData\Local\Microsoft\VisualStudio\BackupFiles\Echohearts','E:\ECHOHEARTS_REBEARTH_PROJECT' -ReportDir 'C:\EchoheartsAuditReports' -HashFiles
No rename, move, delete, write into scan roots, or Git mutation.
#>
param(
  [Parameter(Mandatory=$true)][string[]]$Roots,
  [Parameter(Mandatory=$true)][string]$ReportDir,
  [switch]$HashFiles
)
$ErrorActionPreference = 'Stop'
$resolvedRoots = @()
foreach ($root in $Roots) {
  if (-not (Test-Path -LiteralPath $root -PathType Container)) { throw "Missing scan root: $root" }
  $resolvedRoots += [System.IO.Path]::GetFullPath($root).TrimEnd('\')
}
$out = [System.IO.Path]::GetFullPath($ReportDir).TrimEnd('\')
foreach ($root in $resolvedRoots) {
  if ($out -eq $root -or $out.StartsWith($root + '\',[System.StringComparison]::OrdinalIgnoreCase)) {
    throw 'ReportDir must be outside every scan root.'
  }
}
New-Item -ItemType Directory -Force -Path $out | Out-Null
$records = New-Object System.Collections.Generic.List[object]
$errors = New-Object System.Collections.Generic.List[object]
$skip = @('.git','node_modules','Intermediate','DerivedDataCache','Binaries','.vs')
foreach ($root in $resolvedRoots) {
  $pending = New-Object 'System.Collections.Generic.Stack[string]'
  $pending.Push($root)
  while ($pending.Count -gt 0) {
    $dir = $pending.Pop()
    try {
      foreach ($entry in [System.IO.Directory]::EnumerateFileSystemEntries($dir)) {
        try {
          $attrs = [System.IO.File]::GetAttributes($entry)
          if (($attrs -band [System.IO.FileAttributes]::ReparsePoint) -ne 0) { continue }
          if (($attrs -band [System.IO.FileAttributes]::Directory) -ne 0) {
            if ($skip -notcontains [System.IO.Path]::GetFileName($entry)) { $pending.Push($entry) }
          } else {
            $item = Get-Item -LiteralPath $entry
            $digest = ''
            if ($HashFiles) { $digest = (Get-FileHash -LiteralPath $entry -Algorithm SHA256).Hash }
            $records.Add([pscustomobject]@{
              Root=$root; Path=$item.FullName; SizeBytes=$item.Length
              ModifiedUtc=$item.LastWriteTimeUtc.ToString('o')
              Extension=$item.Extension; SHA256=$digest
            })
          }
        } catch { $errors.Add([pscustomobject]@{Path=$entry; Error=$_.Exception.Message}) }
      }
    } catch { $errors.Add([pscustomobject]@{Path=$dir; Error=$_.Exception.Message}) }
  }
}
$records | Export-Csv -LiteralPath (Join-Path $out 'inventory.csv') -NoTypeInformation -Encoding UTF8
$duplicateGroups = @()
if ($HashFiles) {
  $duplicateGroups = @($records | Where-Object { $_.SHA256 } | Group-Object SHA256,SizeBytes | Where-Object { $_.Count -gt 1 } | ForEach-Object { @($_.Group.Path) })
}
[pscustomobject]@{
  ScannedRoots=$resolvedRoots; FileCount=$records.Count; Hashing=$HashFiles.IsPresent
  PotentialDuplicateGroups=$duplicateGroups; Errors=@($errors)
  Note='No files moved or deleted. Duplicate groups require manual approval.'
} | ConvertTo-Json -Depth 8 | Set-Content -LiteralPath (Join-Path $out 'summary.json') -Encoding UTF8
Write-Output "Audit complete: $($records.Count) files; reports in $out"
