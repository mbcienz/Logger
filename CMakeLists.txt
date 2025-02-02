cmake_minimum_required(VERSION 3.10)
project(LoggerProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Configurazione per Windows
if(WIN32)
    add_compile_options(-static)
    set(CMAKE_EXE_LINKER_FLAGS "-static")
endif()

# Aggiungi directory di include
include_directories(include)

file(GLOB SOURCES "test/test.cpp")

# Eseguibile principale
add_executable(main ${SOURCES})