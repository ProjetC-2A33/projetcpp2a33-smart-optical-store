# Téléchargement direct des DLL OpenSSL 3.x pour Qt 6.x

Write-Host "====================================================" -ForegroundColor Cyan
Write-Host "  TÉLÉCHARGEMENT DES DLL OPENSSL 3.x" -ForegroundColor Cyan
Write-Host "====================================================" -ForegroundColor Cyan
Write-Host ""

# URLs des DLL OpenSSL 3.x
$libCryptoUrl = "https://github.com/IndySockets/OpenSSL-Binaries/raw/master/openssl-3.0/x64/libcrypto-3-x64.dll"
$libSslUrl = "https://github.com/IndySockets/OpenSSL-Binaries/raw/master/openssl-3.0/x64/libssl-3-x64.dll"

# Dossiers de destination
$destDirs = @(
    "C:\Users\Raouf\Desktop\projetqt\build\Desktop_Qt_6_10_1_MinGW_64_bit-Debug\debug",
    "C:\Users\Raouf\Desktop\projetqt\build\Desktop_Qt_6_10_1_MinGW_64_bit-Debug"
)

Write-Host "Téléchargement de libcrypto-3-x64.dll..." -ForegroundColor Yellow
$tempCrypto = "$env:TEMP\libcrypto-3-x64.dll"
try {
    $ProgressPreference = 'SilentlyContinue'
    Invoke-WebRequest -Uri $libCryptoUrl -OutFile $tempCrypto -UseBasicParsing
    Write-Host "[OK] libcrypto-3-x64.dll téléchargé" -ForegroundColor Green
} catch {
    Write-Host "[ERREUR] Impossible de télécharger libcrypto-3-x64.dll" -ForegroundColor Red
    Write-Host "Erreur: $_" -ForegroundColor Red
}

Write-Host "Téléchargement de libssl-3-x64.dll..." -ForegroundColor Yellow
$tempSsl = "$env:TEMP\libssl-3-x64.dll"
try {
    Invoke-WebRequest -Uri $libSslUrl -OutFile $tempSsl -UseBasicParsing
    Write-Host "[OK] libssl-3-x64.dll téléchargé" -ForegroundColor Green
} catch {
    Write-Host "[ERREUR] Impossible de télécharger libssl-3-x64.dll" -ForegroundColor Red
    Write-Host "Erreur: $_" -ForegroundColor Red
}

Write-Host ""
Write-Host "Copie des DLL vers les dossiers de l'application..." -ForegroundColor Yellow

foreach ($destDir in $destDirs) {
    if (!(Test-Path $destDir)) {
        New-Item -ItemType Directory -Path $destDir -Force | Out-Null
    }
    
    if (Test-Path $tempCrypto) {
        Copy-Item -Path $tempCrypto -Destination "$destDir\libcrypto-3-x64.dll" -Force
        Write-Host "[OK] libcrypto-3-x64.dll copié vers $destDir" -ForegroundColor Green
    }
    
    if (Test-Path $tempSsl) {
        Copy-Item -Path $tempSsl -Destination "$destDir\libssl-3-x64.dll" -Force
        Write-Host "[OK] libssl-3-x64.dll copié vers $destDir" -ForegroundColor Green
    }
}

Write-Host ""
Write-Host "====================================================" -ForegroundColor Cyan
Write-Host "  TERMINÉ!" -ForegroundColor Green
Write-Host "====================================================" -ForegroundColor Cyan
Write-Host ""
Write-Host "Les DLL OpenSSL 3.x ont été installées." -ForegroundColor Yellow
Write-Host "Relancez votre application Qt maintenant." -ForegroundColor Yellow
Write-Host ""

# Vérification
Write-Host "Vérification des fichiers installés:" -ForegroundColor Cyan
foreach ($destDir in $destDirs) {
    if (Test-Path "$destDir\libcrypto-3-x64.dll") {
        $size = (Get-Item "$destDir\libcrypto-3-x64.dll").Length / 1MB
        Write-Host "  ✓ $destDir\libcrypto-3-x64.dll ($([Math]::Round($size, 2)) MB)" -ForegroundColor Green
    }
    if (Test-Path "$destDir\libssl-3-x64.dll") {
        $size = (Get-Item "$destDir\libssl-3-x64.dll").Length / 1MB
        Write-Host "  ✓ $destDir\libssl-3-x64.dll ($([Math]::Round($size, 2)) MB)" -ForegroundColor Green
    }
}

pause
