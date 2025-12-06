# Commands:
# 
# cmake -S . -B build (apply this config file)
# cmake --build build/ (build executable)
#
# run executable in build file

cmake_minimum_required(VERSION 4.1.2)
project(PoliticalPartyParty)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_STANDARD 23)

# find library packages (assuming you have GLFW and OpenGL installed)
find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)


add_executable(PoliticalPartyParty
  src/glad.c
  src/main.cpp
)

# include (gcc -I./)
target_include_directories(PoliticalPartyParty PRIVATE 
  include
)

# link libraries
target_link_libraries(PoliticalPartyParty PRIVATE
  OpenGL::GL
  glfw
)

target_compile_options(PoliticalPartyParty PRIVATE
  -Wall -Wextra -Wformat-nonliteral -Wcast-align -Wpointer-arith
  -Wmissing-declarations -Winline -Wundef
  -Wcast-qual -Wshadow -Wwrite-strings -Wno-unused-parameter
  -Wfloat-equal
)
