add_executable(test_runner main.cpp)
target_link_libraries(test_runner test-codecov-lib)

add_test(test_runner test_runner)
