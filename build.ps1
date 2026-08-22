# Builds every example and the unit tests with g++, then runs the tests.
# Usage: .\build.ps1            (default: C++20)
#        .\build.ps1 -Std c++17
param(
    [string]$Std = "c++20"
)

$ErrorActionPreference = "Stop"

# Locate g++
$gpp = Get-Command g++ -ErrorAction SilentlyContinue
if ($gpp) {
    $compiler = $gpp.Source
} elseif (Test-Path "C:\msys64\ucrt64\bin\g++.exe") {
    $compiler = "C:\msys64\ucrt64\bin\g++.exe"
} else {
    throw "g++ not found. Install MSYS2/MinGW-w64 or add it to PATH."
}
Write-Host "Compiler: $compiler"

New-Item -ItemType Directory -Force -Path build\bin | Out-Null

# 1) Unit tests: all test .cpp files into one runner
Write-Host "`n== Building unit tests ==" -ForegroundColor Cyan
$testSources = Get-ChildItem tests -Filter *.cpp | ForEach-Object { $_.FullName }
& $compiler "-std=$Std" -Wall -Wextra -Iinclude $testSources -o build\bin\unit_tests.exe
if ($LASTEXITCODE -ne 0) { throw "Unit test build failed." }

# 2) Examples: one executable per .cpp under basic/ and features/
Write-Host "== Building examples ==" -ForegroundColor Cyan
$examples = Get-ChildItem -Recurse -Filter *.cpp |
    Where-Object { $_.FullName -notmatch '\\tests\\' }
foreach ($src in $examples) {
    $name = [IO.Path]::GetFileNameWithoutExtension($src.Name)
    & $compiler "-std=$Std" -Wall -Iinclude $src.FullName -o "build\bin\$name.exe"
    if ($LASTEXITCODE -ne 0) { throw "Build failed for $($src.FullName)." }
    Write-Host "  built $name.exe"
}

# 3) Run unit tests
Write-Host "`n== Running unit tests ==" -ForegroundColor Cyan
& build\bin\unit_tests.exe
exit $LASTEXITCODE
