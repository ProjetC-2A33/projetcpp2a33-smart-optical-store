@echo off
echo ====================================================
echo   INSTALLATION OPENSSL POUR QT
echo ====================================================
echo.

REM Vérifier si OpenSSL est déjà installé
if exist "C:\Program Files\OpenSSL-Win64\bin\libssl-1_1-x64.dll" (
    echo OpenSSL est deja installe!
    goto :COPY_DLL
)

echo OpenSSL n'est pas installe.
echo.
echo Veuillez telecharger et installer OpenSSL depuis:
echo https://slproweb.com/products/Win32OpenSSL.html
echo.
echo Telechargez: Win64 OpenSSL v1.1.1 Light
echo.
pause
exit

:COPY_DLL
echo.
echo Copie des DLL OpenSSL vers le dossier de l'application...
echo.

set "SOURCE_DIR=C:\Program Files\OpenSSL-Win64\bin"
set "DEST_DIR=C:\Users\Raouf\Desktop\projetqt\build\Desktop_Qt_6_10_1_MinGW_64_bit-Debug\debug"

if not exist "%DEST_DIR%" (
    echo Creation du dossier de destination...
    mkdir "%DEST_DIR%"
)

if exist "%SOURCE_DIR%\libssl-1_1-x64.dll" (
    copy /Y "%SOURCE_DIR%\libssl-1_1-x64.dll" "%DEST_DIR%\"
    echo [OK] libssl-1_1-x64.dll copie
) else (
    echo [ERREUR] libssl-1_1-x64.dll introuvable
)

if exist "%SOURCE_DIR%\libcrypto-1_1-x64.dll" (
    copy /Y "%SOURCE_DIR%\libcrypto-1_1-x64.dll" "%DEST_DIR%\"
    echo [OK] libcrypto-1_1-x64.dll copie
) else (
    echo [ERREUR] libcrypto-1_1-x64.dll introuvable
)

echo.
echo ====================================================
echo Installation terminee!
echo Vous pouvez maintenant relancer votre application.
echo ====================================================
pause
