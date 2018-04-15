add_library(test-codecov-lib sample.cpp)

set_target_properties(test-codecov-lib PROPERTIES PREFIX "") # Remove the lib prefix

target_include_directories(test-codecov-lib PUBLIC ${CMAKE_SOURCE_DIR}/include)

#[[if (ENABLE_COVERAGE) # Uncomment these lines
    target_compile_options(test-codecov-lib PRIVATE "-g;-O0;--coverage;-fprofile-arcs;-ftest-coverage")
endif (ENABLE_COVERAGE)]]
