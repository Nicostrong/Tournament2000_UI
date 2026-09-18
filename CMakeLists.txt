cmake_minimum_required(VERSION 3.5)

project(Tournament2000QT VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/gui)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)

set(TS_FILES Tournament2000QT_fr_FR.ts)

set(MAIN_SOURCE
	src/main.cpp
)

set(CORE_SOURCES
	core/class/Match.cpp
	core/class/Phase.cpp
	core/class/Player.cpp
	core/class/Pool.cpp
	core/class/Settings.cpp
	core/class/Team.cpp
	core/class/Tournament.cpp
	core/controller/TournamentController.cpp
	core/factory/TeamFactory.cpp
	core/manager/PhaseManager.cpp
	core/manager/PlayerManager.cpp
	core/manager/PoolManager.cpp
	core/manager/TeamManager.cpp
	core/utils/CheckerCSV.cpp
	core/utils/Exporter.cpp
	core/utils/FormatUtils.cpp
	core/utils/Importer.cpp
	core/utils/PrintUtils.cpp
	core/utils/SettingsChecker.cpp
	core/utils/TablePrinter.cpp
	includes/class/Match.hpp
	includes/class/Phase.hpp
	includes/class/Player.hpp
	includes/class/Pool.hpp
	includes/class/Settings.hpp
	includes/class/Team.hpp
	includes/class/Tournament.hpp
	includes/controller/TournamentController.hpp
	includes/factory/TeamFactory.hpp
	includes/manager/PhaseManager.hpp
	includes/manager/PlayerManager.hpp
	includes/manager/PoolManager.hpp
	includes/manager/TeamManager.hpp
	includes/utils/CheckerCSV.hpp
	includes/utils/Exporter.hpp
	includes/utils/FormatUtils.hpp
	includes/utils/Importer.hpp
	includes/utils/PrintUtils.hpp
	includes/utils/SettingsChecker.hpp
	includes/utils/TablePrinter.hpp
)

set(GUI_SOURCES
	gui/mainwindow.cpp
	gui/mainwindow.h
	gui/mainwindow.ui
)

set(PROJECT_SOURCES
	${MAIN_SOURCE}
	${CORE_SOURCES}
	${GUI_SOURCES}
	${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
	qt_add_executable(Tournament2000QT
		MANUAL_FINALIZATION
		${PROJECT_SOURCES}
	)
# Define target properties for Android with Qt 6 as:
#	set_property(TARGET Tournament2000QT APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#					${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

	qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
	if(ANDROID)
		add_library(Tournament2000QT SHARED
			${PROJECT_SOURCES}
		)
# Define properties for Android with Qt 5 after find_package() calls as:
#	set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
	else()
		add_executable(Tournament2000QT
			${PROJECT_SOURCES}
		)
	endif()

	qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(Tournament2000QT PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Tournament2000QT PROPERTIES
	MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
	MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
	MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
	MACOSX_BUNDLE TRUE
	WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
	qt_finalize_executable(Tournament2000QT)
endif()
