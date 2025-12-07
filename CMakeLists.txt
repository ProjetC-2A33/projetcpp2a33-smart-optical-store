cmake_minimum_required(VERSION 3.16)

project(gestion_stock VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# === Modules Qt requis ===
find_package(Qt6 REQUIRED COMPONENTS
    Core
    Widgets
    Sql
    Network
    PrintSupport
    Charts
    SerialPort       # ⚡ IMPORTANT POUR QSerialPort
)

# === Sources ===
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    connexion.h
    connexion.cpp
    produit.h
    produit.cpp
    employe.h
    employe.cpp
    fournisseur.h
    fournisseur.cpp
    client.h
    client.cpp
    arduino1.cpp          # ⚡ Ajout Arduino1
    arduino1.h
)

# === Exécutable ===
qt_add_executable(gestion_stock
    ${PROJECT_SOURCES}
)

# === Liens Qt ===
target_link_libraries(gestion_stock PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::Sql
    Qt6::Network
    Qt6::PrintSupport
    Qt6::Charts
    Qt6::SerialPort       # ⚡ obligatoire pour Arduino
)

# === Configuration Windows / Mac ===
set_target_properties(gestion_stock PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS gestion_stock
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_finalize_executable(gestion_stock)
