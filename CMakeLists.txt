cmake_minimum_required(VERSION 3.26)
project(tv)

set(CMAKE_CXX_STANDARD 20) # Use C++20
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Enforce the standard
set(CMAKE_CXX_EXTENSIONS OFF) # Disable compiler-specific extensions (optional)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src/app)
add_subdirectory(src/library)

set(BUILD_SHARED_LIBS ON)
