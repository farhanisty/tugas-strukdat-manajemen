# Minimum versi CMake
cmake_minimum_required(VERSION 3.10)

# Nama proyek
project(MyProject VERSION 1.0 LANGUAGES CXX)

# Set standar C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Direktori sumber
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

# Cari semua file .cpp di src/ termasuk subfolder
file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp")

# Output build ke folder dist
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/dist)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Tambahkan executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Tambahkan opsi kompilasi
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -O2)