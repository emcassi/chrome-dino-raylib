cmake_minimum_required(VERSION 3.15)
project(Dino)

set(CMAKE_CXX_STANDARD 23)
set( CMAKE_BUILD_TYPE Debug )

set(RAYLIB_INC "/home/alex/Programming/Games/Raylib/raylib-4.5/build/raylib/include")
set(RAYLIB_CPP_INC "/home/alex/Programming/Games/Raylib/raylib-cpp-4.5.0/include")

include_directories(${RAYLIB_INC} ${RAYLIB_CPP_INC})
link_directories(lib)

file(GLOB SOURCES "src/*.h" "src/*.cpp")

add_executable(Dino ${SOURCES})

target_link_libraries(Dino raylib)