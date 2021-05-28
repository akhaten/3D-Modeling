project(Billard VERSION 0.0.1)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()


find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
set(Qt5_LIBRARIES Qt5::Core Qt5::Widgets)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)





find_package(Radium REQUIRED Core Engine Gui PluginBase IO)

set(app_sources
        main.cpp
        MainWindow.cpp
        MainApplication.cpp)

set(headers
        MainWindow.h
        MainApplication.h)

#set(app_uis
#Gui/ui/MainWindow.ui)

#qt5_wrap_ui(app_uis_moc ${app_uis})


add_executable(${PROJECT_NAME}
${app_sources}
${headers}
${app_uis_moc}
)

target_include_directories(${PROJECT_NAME} PRIVATE
${RADIUM_INCLUDE_DIRS}
${CMAKE_CURRENT_BINARY_DIR} # Moc
${CMAKE_CURRENT_SOURCE_DIR}
)

# Include Radium
include_directories(../../Radium-Engine/Bundle-GNU/include)

# Linking
target_link_libraries(${PROJECT_NAME}
Radium::Core
Radium::Engine
Radium::Gui
Radium::IO
${Qt5_LIBRARIES})

configure_radium_app(
NAME ${PROJECT_NAME}
USE_PLUGINS
)