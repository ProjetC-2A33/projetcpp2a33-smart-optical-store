# Téléchargement OpenSSL 3.x depuis une source alternative

Write-Host "====================================================" -ForegroundColor Cyan
Write-Host "  TÉLÉCHARGEMENT OPENSSL 3.x" -ForegroundColor Cyan
Write-Host "====================================================" -ForegroundColor Cyan
Write-Host ""

# URLs alternatives pour OpenSSL 3.x
$urls = @{
    "libcrypto" = "https://curl.se/windows/dl-8.11.0_3/openssl-3.3.2_3-win64-mingw.zip"
    "libssl" = "https://curl.se/windows/dl-8.11.0_3/openssl-3.3.2_3-win64-mingw.zip"
}

$zipPath = "$env:TEMP\openssl3.zip"
$extractPath = "$env:TEMP\openssl3"

Write-Host "Téléchargement du package OpenSSL 3.x..." -ForegroundColor Yellow

try {
    # Télécharger depuis curl.se (source fiable)
    $url = "https://download.firedaemon.com/FireDaemon-OpenSSL/openssl-3.3.2.zip"
    $ProgressPreference = 'SilentlyContinue'
    Invoke-WebRequest -Uri $url -OutFile $zipPath -UseBasicParsing -ErrorAction Stop
    Write-Host "[OK] Package téléchargé" -ForegroundColor Green
    
    # Extraire
    Write-Host "Extraction du package..." -ForegroundColor Yellow
    Expand-Archive -Path $zipPath -DestinationPath $extractPath -Force
    Write-Host "[OK] Package extrait" -ForegroundColor Green
} catch {
    Write-Host "[ERREUR] Téléchargement impossible" -ForegroundColor Red
    Write-Host ""
    Write-Host "Veuillez télécharger manuellement OpenSSL 3.x depuis:" -ForegroundColor Yellow
    Write-Host "https://slproweb.com/products/Win32OpenSSL.html" -ForegroundColor Cyan
    Write-Host ""
    Write-Host "Ou utilisez cette commande pour télécharger via winget:" -ForegroundColor Yellow
    Write-Host "winget install -e --id ShiningLight.OpenSSL" -ForegroundColor Cyan
    pause
    exit
}

# Rechercher les DLL dans le dossier extrait
Write-Host ""
Write-Host "Recherche des DLL OpenSSL..." -ForegroundColor Yellow

$dllFiles = Get-ChildItem -Path $extractPath -Recurse -Filter "*.dll" | Where-Object { $_.Name -like "*ssl*" -or $_.Name -like "*crypto*" }

if ($dllFiles.Count -eq 0) {
    Write-Host "[ERREUR] Aucune DLL trouvée dans le package" -ForegroundColor Red
    pause
    exit
}

Write-Host "DLL trouvées:" -ForegroundColor Green
foreach ($dll in $dllFiles) {
    Write-Host "  - $($dll.Name)" -ForegroundColor Cyan
}

# Copier vers les dossiers de destination
$destDirs = @(
    "C:\Users\Raouf\Desktop\projetqt\build\Desktop_Qt_6_10_1_MinGW_64_bit-Debug\debug",
    "C:\Users\Raouf\Desktop\projetqt\build\Desktop_Qt_6_10_1_MinGW_64_bit-Debug"
)

Write-Host ""
Write-Host "Copie des DLL..." -ForegroundColor Yellow

foreach ($destDir in $destDirs) {
    if (!(Test-Path $destDir)) {
        New-Item -ItemType Directory -Path $destDir -Force | Out-Null
    }
    
    foreach ($dll in $dllFiles) {
        Copy-Item -Path $dll.FullName -Destination $destDir -Force
        Write-Host "[OK] $($dll.Name) copié vers $destDir" -ForegroundColor Green
    }
}

Write-Host ""
Write-Host "====================================================" -ForegroundColor Cyan
Write-Host "  INSTALLATION TERMINÉE!" -ForegroundColor Green
Write-Host "====================================================" -ForegroundColor Cyan

# Nettoyer
Remove-Item $zipPath -Force -ErrorAction SilentlyContinue
Remove-Item $extractPath -Recurse -Force -ErrorAction SilentlyContinue

pause
