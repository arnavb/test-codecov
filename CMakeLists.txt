cmake_minimum_required(VERSION 3.2)

project(test-codecov)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

option(BUILD_TESTS "Build tests" OFF)
option(ENABLE_COVERAGE "Enable code coverage" OFF)

if (ENABLE_COVERAGE AND NOT CMAKE_CONFIGURATION_TYPES)
    if (NOT BUILD_TESTS)
        message(FATAL_ERROR "Tests must be enabled for code coverage!")
    endif (NOT BUILD_TESTS)
    
    include(CodeCoverage)
    #append_coverage_compiler_flags() # <-- Comment this line and uncomment the selected lines in src/CMakeLists.txt
    
    set(COVERAGE_EXCLUDES "${CMAKE_SOURCE_DIR}/test/*")
    setup_target_for_coverage(NAME coverage EXECUTABLE ctest DEPENDENCIES coverage)
endif (ENABLE_COVERAGE AND NOT CMAKE_CONFIGURATION_TYPES)

add_subdirectory(src)

if (BUILD_TESTS)
    include(CTest)
    enable_testing()
    add_subdirectory(test)
endif (BUILD_TESTS)
