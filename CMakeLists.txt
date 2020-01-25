# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)

# Name of the project
project(Test)

find_package(SDL2 REQUIRED)
find_package(glm REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})
# include_directories(${GLM_INCLUDE_DIR})

include_directories(include)

# add_subdirectory(src)

set(TARGET main)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

file(GLOB sources "src/*.cpp")
add_executable(${TARGET} ${sources})

target_link_libraries(${TARGET} ${SDL2_LIBRARY} glm)

if (APPLE)
    target_link_libraries(${TARGET} "-F/Library/Frameworks" "-framework SDL2")
endif (APPLE)