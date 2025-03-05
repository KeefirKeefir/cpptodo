cmake_minimum_required(VERSION 3.28)

project(todolist VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

# Define source files
set(SOURCES
    src/main.cpp
)

# Define module files
set(MODULES
    src/my_module.cppm
)

# Include directories
include_directories("C:/vcpkg/installed/x64-windows/include")
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/incl)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Add modules
target_sources(${PROJECT_NAME}
    PRIVATE
        FILE_SET CXX_MODULES
        FILES ${MODULES}
)
