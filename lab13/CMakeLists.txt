cmake_minimum_required(VERSION 3.20)

project(hello_cmake)

option(BUILD_DYNAMIC_LIB OFF)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SOURCES ${SOURCE_DIR}/auto.c)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

if(BUILD_DYNAMIC_LIB)
    message(STATUS "Выбрана динамическая библиотека")
    add_library(AUTO_LIB SHARED ${SOURCES})
else()
    message(STATUS "Выбрана статическая библиотека")
    add_library(AUTO_LIB STATIC ${SOURCES})
endif()

add_executable(app main.c)
target_link_libraries(app AUTO_LIB)