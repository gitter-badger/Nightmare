#============================================================#
#     __  _         _      _                                 #
#  /\ \ \(_)  __ _ | |__  | |_  _ __ ___    __ _  _ __  ___  #
# /  \/ /| | / _` || '_ \ | __|| '_ ` _ \  / _` || '__|/ _ \ #
#/ /\  / | || (_| || | | || |_ | | | | | || (_| || |  |  __/ #
#\_\ \/  |_| \__, ||_| |_| \__||_| |_| |_| \__,_||_|   \___| #
#            |___/                                           #
#============================================================#

cmake_minimum_required (VERSION 2.8)

project (NigthmareProject)

#ADICIONANDO C++11 AO PROJETO
set(CMAKE_CXX_FLAGS "-std=c++0x")

#CONFIGURAÇÕES DA QT PARA O PROJETO
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS} ${Qt5Core_EXECUTABLE_COMPILE_FLAGS} -fPIC")

#SETANDO CMAKE PARA VER OS MODULOS DAS BIBLIOTECAS USADAS
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(CMAKE_AUTOMOC ON)
	
#INCLUINDO TODOS OS ARQUIVOS PARA SEREM COMPILADOS		 
File(GLOB SRCS "Sources/*.cc"
			   "Sources/Game/*.cc"
			   "Sources/Game/Layers/*.cc"
			   "Sources/Game/Map/*.cc"
			   "Sources/Game/Map/MapExceptions/*.cc"
			   "Sources/Game/Observer/*.cc")

#INCLUINDO OS CABEÇARIOS PARA SEREM COMPILADOS			   
File(GLOB HDRS "Sources/*.h"
			   "Sources/Game/*.h"
			   "Sources/Game/Layers/*.h"
			   "Sources/Game/Map/*.h"
			   "Sources/Game/Map/MapExceptions/*.h"
			   "Sources/Game/Observer/*.h")
#SFML BIBLIOTECAS			   
find_package(SFML 2 REQUIRED system window graphics network audio)

#BIBLIOTECAS DA QT
find_package(Qt5Widgets)
find_package(Qt5Core)

include_directories(${Qt5Widgets_INCLUDE_DIRS})
include_directories(${Qt5Core_INCLUDE_DIRS})

#NOME DA EXECUTAVEL
set(EXECUTABLE_NAME "Nigthmare")
add_executable(${EXECUTABLE_NAME} ${HDRS} ${SRCS})


target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})

#installing the program
#install(DIRECTORY  DESTINATION bin)


