cmake_minimum_required(VERSION 3.3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

project(Q)
   
# Adding source files
file(GLOB_RECURSE src Source/*.cpp)
   
# Adding dependencies
find_package(OpenGL 3.3 REQUIRED) # Or 3.2?
	include_directories(${OPENGL_INCLUDE_DIRS})
	link_libraries(${OPENGL_LIBRARIES})
find_package(SFML 2.5 REQUIRED window graphics)

# Compiling
add_executable(Q ${src})
target_link_libraries(Q sfml-window sfml-graphics)

