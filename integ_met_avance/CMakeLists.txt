cmake_minimum_required(VERSION 3.16)

project(gestion_stock VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Recherche des packages Qt
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql Charts)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql Charts)

# Configuration d'OpenCV
set(OpenCV_DIR "C:/opencv/build/x64/vc16/lib")
find_package(OpenCV 4.12.0 REQUIRED)

# Ajout des chemins d'inclusion
include_directories(
    ${OpenCV_INCLUDE_DIRS}
    "C:/opencv/build/include"
    "C:/opencv/build/include/opencv2"
)

# Configuration des bibliothèques
set(OPENCV_LIBS
    opencv_world4120
    opencv_imgcodecs4120
    opencv_imgproc4120
    opencv_core4120
    opencv_objdetect4120
)

message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "    libraries: ${OPENCV_LIBS}")

# Ajouter les définitions nécessaires pour QtCharts
add_definitions(-DQT_CHARTS_LIB)
add_definitions(-DQT_CHARTS_USE_NAMESPACE)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        connexion.h
        connexion.cpp
        produit.h
        produit.cpp
        employe.h      # Ajouter cette ligne
        employe.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    find_package(Qt6 REQUIRED COMPONENTS Core Widgets Sql Charts)
    set(QT_LIBRARIES Qt6::Core Qt6::Widgets Qt6::Sql Qt6::Charts)
    
    qt_add_executable(gestion_stock
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    find_package(Qt5 REQUIRED COMPONENTS Core Widgets Sql Charts)
    set(QT_LIBRARIES Qt5::Core Qt5::Widgets Qt5::Sql Qt5::Charts)
    
    if(ANDROID)
        add_library(gestion_stock SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(gestion_stock
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(gestion_stock PRIVATE 
    ${QT_LIBRARIES}
    ${OPENCV_LIBS}
    Qt${QT_VERSION_MAJOR}::Widgets 
    Qt${QT_VERSION_MAJOR}::Sql 
    Qt${QT_VERSION_MAJOR}::Charts
)

# Ajout des chemins des bibliothèques
link_directories("C:/opencv/build/x64/vc16/lib")

# Configuration spécifique pour Windows
if(WIN32)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_SCL_SECURE_NO_WARNINGS)
    if(MSVC)
        add_compile_options(/EHsc)
    endif()
endif()

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.gestion_stock)
endif()

set_target_properties(gestion_stock PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS gestion_stock
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(gestion_stock)
endif()

find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql PrintSupport)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql Charts)  # Ajouter Charts
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql Charts)  # Ajouter Charts
target_link_libraries(gestion_stock PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Sql
    Qt${QT_VERSION_MAJOR}::PrintSupport
)
