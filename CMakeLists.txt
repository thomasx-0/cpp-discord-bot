cmake_minimum_required(VERSION 3.10)
    
project(discord-bot VERSION 1.0 DESCRIPTION "A discord bot")
    
# Add the cmake directory to the module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
    
# Create an executable
add_executable(${PROJECT_NAME} src/main.cpp)
    
# Find the DPP package
find_package(DPP REQUIRED)
    
# Include the DPP directories
target_include_directories(${PROJECT_NAME} PRIVATE ${DPP_INCLUDE_DIRS})
    
# Link the DPP library
target_link_libraries(${PROJECT_NAME} ${DPP_LIBRARIES})
    
# Set C++ version
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
    
# Set linker and compiler flags
set(CMAKE_EXE_LINKER_FLAGS "-L/opt/homebrew/lib" CACHE STRING "" FORCE)
set(CMAKE_C_FLAGS "-I/opt/homebrew/include" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS "-I/opt/homebrew/include" CACHE STRING "" FORCE)