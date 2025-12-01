# Script pour installer OpenSSL 3.x pour Qt 6.x

Write-Host "====================================================" -ForegroundColor Cyan
Write-Host "  INSTALLATION D'OPENSSL 3.x POUR QT 6.x" -ForegroundColor Cyan
Write-Host "====================================================" -ForegroundColor Cyan
Write-Host ""

# URL de téléchargement OpenSSL 3.x Light (64-bit)
$openSslUrl = "https://slproweb.com/download/Win64OpenSSL-3_4_0.msi"
$installerPath = "$env:TEMP\Win64OpenSSL3.msi"

Write-Host "Téléchargement d'OpenSSL 3.x..." -ForegroundColor Yellow
try {
    $ProgressPreference = 'SilentlyContinue'
    Invoke-WebRequest -Uri $openSslUrl -OutFile $installerPath -UseBasicParsing
    Write-Host "[OK] Téléchargement terminé" -ForegroundColor Green
} catch {
    Write-Host "[ERREUR] Impossible de télécharger OpenSSL 3.x" -ForegroundColor Red
    Write-Host "Tentative avec une version alternative..." -ForegroundColor Yellow
    
    # Version alternative
    $openSslUrl = "https://slproweb.com/download/Win64OpenSSL_Light-3_1_3.msi"
    try {
        Invoke-WebRequest -Uri $openSslUrl -OutFile $installerPath -UseBasicParsing
        Write-Host "[OK] Téléchargement terminé (version alternative)" -ForegroundColor Green
    } catch {
        Write-Host "[ERREUR] Téléchargement impossible" -ForegroundColor Red
        pause
        exit
    }
}

Write-Host ""
Write-Host "Installation d'OpenSSL 3.x..." -ForegroundColor Yellow
Start-Process msiexec.exe -ArgumentList "/i `"$installerPath`" /qb" -Wait
Write-Host "[OK] Installation terminée" -ForegroundColor Green
Write-Host ""

# Chemins possibles pour OpenSSL 3.x
$possiblePaths = @(
    "C:\Program Files\OpenSSL-Win64\bin",
    "C:\Program Files\OpenSSL\bin"
)

$sourceDir = $null
foreach ($path in $possiblePaths) {
    if (Test-Path $path) {
        $sourceDir = $path
        break
    }
}

if ($sourceDir -eq $null) {
    Write-Host "[ERREUR] OpenSSL n'a pas été trouvé" -ForegroundColor Red
    pause
    exit
}

Write-Host "OpenSSL trouvé dans: $sourceDir" -ForegroundColor Green
Write-Host ""

# Copier les DLL OpenSSL 3.x
$destDirs = @(
    "C:\Users\Raouf\Desktop\projetqt\build\Desktop_Qt_6_10_1_MinGW_64_bit-Debug\debug",
    "C:\Users\Raouf\Desktop\projetqt\build\Desktop_Qt_6_10_1_MinGW_64_bit-Debug"
)

# Noms des DLL pour OpenSSL 3.x
$dllFiles = @("libssl-3-x64.dll", "libcrypto-3-x64.dll")

Write-Host "Copie des DLL OpenSSL 3.x..." -ForegroundColor Yellow

foreach ($destDir in $destDirs) {
    if (!(Test-Path $destDir)) {
        New-Item -ItemType Directory -Path $destDir -Force | Out-Null
    }
    
    foreach ($dll in $dllFiles) {
        $sourcePath = Join-Path $sourceDir $dll
        $destPath = Join-Path $destDir $dll
        
        if (Test-Path $sourcePath) {
            Copy-Item -Path $sourcePath -Destination $destPath -Force
            Write-Host "[OK] $dll copié vers $destDir" -ForegroundColor Green
        } else {
            Write-Host "[ATTENTION] $dll introuvable" -ForegroundColor Yellow
        }
    }
}

Write-Host ""
Write-Host "====================================================" -ForegroundColor Cyan
Write-Host "  INSTALLATION TERMINÉE!" -ForegroundColor Green
Write-Host "====================================================" -ForegroundColor Cyan
Write-Host ""
Write-Host "Relancez votre application Qt maintenant." -ForegroundColor Yellow
Write-Host ""

Remove-Item $installerPath -Force -ErrorAction SilentlyContinue
pause
