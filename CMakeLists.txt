cmake_minimum_required(VERSION 3.22)
project(asciidraw VERSION 1.0.0 LANGUAGES C)

#FILE(GLOB_RECURSE HEADERS *.h)
set(HEADERS)
FILE(GLOB SOURCES keyboard/*.c drawmatrix/* main.c)

include_directories(./)
include_directories(conio drawmatrix)

if(NOT ${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    add_library(conio STATIC conio/conio2-ansi.c)
else()
    add_library(conio STATIC conio/conio2-win.c)
endif()

add_executable(
    ${PROJECT_NAME}
    ${HEADERS}
    ${SOURCES}
     )

target_link_libraries(${PROJECT_NAME} conio)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    target_link_options(${PROJECT_NAME} PRIVATE -static-libgcc -static-libstdc++)
endif()

