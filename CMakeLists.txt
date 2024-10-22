# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Name of the project
project(Asteroid)

find_package(SDL2 REQUIRED)
find_package(glm REQUIRED)
find_package (Threads REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})
# include_directories(${GLM_INCLUDE_DIR})

include_directories(include)

# add_subdirectory(src)
set(BINDIR bin)
set(TARGET asteroids)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/${BINDIR})

file(GLOB_RECURSE sources "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_executable(${TARGET} ${sources})

target_compile_definitions(${TARGET} PUBLIC "DATA_PATH=std::string\(\"${CMAKE_CURRENT_SOURCE_DIR}/\"\)")

target_link_libraries(${TARGET} 
  ${SDL2_LIBRARY}
  glm
  ${CMAKE_THREAD_LIBS_INIT}
)

# if (APPLE)
#     target_link_libraries(${TARGET} "-F/Library/Frameworks" "-framework SDL2")
# endif (APPLE)