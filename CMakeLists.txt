project(thema-game)
cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

find_package(SFML REQUIRED system window graphics audio)
include_directories(${SFML_INCLUDE_DIR})

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

set(CMAKE_CXX_STANDARD 11)

add_executable(thema-game ${SOURCE_FILES})
target_link_libraries(thema-game ${SFML_LIBRARIES})
