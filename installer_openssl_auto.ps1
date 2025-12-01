# Script PowerShell pour télécharger et installer OpenSSL automatiquement

Write-Host "====================================================" -ForegroundColor Cyan
Write-Host "  INSTALLATION AUTOMATIQUE D'OPENSSL POUR QT" -ForegroundColor Cyan
Write-Host "====================================================" -ForegroundColor Cyan
Write-Host ""

# URL de téléchargement OpenSSL 1.1.1w Light (64-bit)
$openSslUrl = "https://slproweb.com/download/Win64OpenSSL_Light-1_1_1w.msi"
$installerPath = "$env:TEMP\Win64OpenSSL_Light.msi"

Write-Host "Téléchargement d'OpenSSL..." -ForegroundColor Yellow
try {
    # Télécharger OpenSSL
    $ProgressPreference = 'SilentlyContinue'
    Invoke-WebRequest -Uri $openSslUrl -OutFile $installerPath -UseBasicParsing
    Write-Host "[OK] Téléchargement terminé" -ForegroundColor Green
} catch {
    Write-Host "[ERREUR] Impossible de télécharger OpenSSL" -ForegroundColor Red
    Write-Host "Erreur: $_" -ForegroundColor Red
    Write-Host ""
    Write-Host "Veuillez télécharger manuellement depuis:" -ForegroundColor Yellow
    Write-Host "https://slproweb.com/products/Win32OpenSSL.html" -ForegroundColor Cyan
    pause
    exit
}

Write-Host ""
Write-Host "Installation d'OpenSSL..." -ForegroundColor Yellow
Write-Host "IMPORTANT: Acceptez les paramètres par défaut dans l'installateur" -ForegroundColor Cyan

# Installer OpenSSL silencieusement
Start-Process msiexec.exe -ArgumentList "/i `"$installerPath`" /qb" -Wait

Write-Host "[OK] Installation terminée" -ForegroundColor Green
Write-Host ""

# Vérifier l'installation
$openSslBinPath = "C:\Program Files\OpenSSL-Win64\bin"
if (Test-Path "$openSslBinPath\libssl-1_1-x64.dll") {
    Write-Host "[OK] OpenSSL installé avec succès" -ForegroundColor Green
} else {
    Write-Host "[ERREUR] OpenSSL n'a pas été installé correctement" -ForegroundColor Red
    pause
    exit
}

Write-Host ""
Write-Host "Copie des DLL vers le dossier de l'application..." -ForegroundColor Yellow

# Chemins source et destination
$sourceDir = "C:\Program Files\OpenSSL-Win64\bin"
$destDir = "C:\Users\Raouf\Desktop\projetqt\build\Desktop_Qt_6_10_1_MinGW_64_bit-Debug\debug"

# Créer le dossier de destination s'il n'existe pas
if (!(Test-Path $destDir)) {
    New-Item -ItemType Directory -Path $destDir -Force | Out-Null
    Write-Host "[OK] Dossier de destination créé" -ForegroundColor Green
}

# Copier les DLL
$dllFiles = @("libssl-1_1-x64.dll", "libcrypto-1_1-x64.dll")

foreach ($dll in $dllFiles) {
    $sourcePath = Join-Path $sourceDir $dll
    $destPath = Join-Path $destDir $dll
    
    if (Test-Path $sourcePath) {
        Copy-Item -Path $sourcePath -Destination $destPath -Force
        Write-Host "[OK] $dll copié" -ForegroundColor Green
    } else {
        Write-Host "[ERREUR] $dll introuvable" -ForegroundColor Red
    }
}

Write-Host ""
Write-Host "====================================================" -ForegroundColor Cyan
Write-Host "  INSTALLATION TERMINÉE AVEC SUCCÈS!" -ForegroundColor Green
Write-Host "====================================================" -ForegroundColor Cyan
Write-Host ""
Write-Host "Vous pouvez maintenant relancer votre application Qt." -ForegroundColor Yellow
Write-Host "L'envoi d'emails devrait maintenant fonctionner." -ForegroundColor Yellow
Write-Host ""

# Nettoyer le fichier temporaire
Remove-Item $installerPath -Force -ErrorAction SilentlyContinue

pause
