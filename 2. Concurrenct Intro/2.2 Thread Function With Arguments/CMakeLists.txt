cmake_minimum_required(VERSION 3.28) 

project(TFWA VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(EXECUTABLE_NAME Homework)

option(ENABLE_TESTING "Enable a Unit Test Build" ON)

include(FetchContent)

if(ENABLE_TESTING)
    FetchContent_Declare(
        Catch2 
        GIT_REPOSITORY https://gh-proxy.org/https://github.com/catchorg/Catch2
        GIT_TAG v3.11.0
        GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(Catch2)
    list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
endif()

add_subdirectory(app)
add_subdirectory(inclusion)
if(ENABLE_TESTING)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif()
