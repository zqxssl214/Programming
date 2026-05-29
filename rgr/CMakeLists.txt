cmake_minimum_required(VERSION 3.10)
project(Maze)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(maze
    src/main.cpp
    src/maze.cpp
    src/logger.cpp
)

target_include_directories(maze PRIVATE src)

enable_testing()
add_executable(tests
    src/tests/tests.cpp
    src/maze.cpp
    src/logger.cpp
)
target_include_directories(tests PRIVATE src)
add_test(NAME MazeTests COMMAND tests)