# test codecov C++

This project is trying to check if the [Code Coverage Module for CMake](https://github.com/bilke/cmake-modules/blob/master/CodeCoverage.cmake) really works.

The current problem I'm experiencing in another one of my repositories is this:

I cannot call the function `append_coverage_compiler_flags()`. Why? Because it modifies `CMAKE_CXX_FLAGS`, which is a problem since it slows down compilation (down to a freeze) for my Catch unit tests.
I tried to replace it with a call such as the following which will only apply the coverage flags to my library:

```CMake
if (ENABLE_COVERAGE) # Uncomment these lines
    target_compile_options(test-codecov-lib PRIVATE "-g;-O0;--coverage;-fprofile-arcs;-ftest-coverage")
endif (ENABLE_COVERAGE)
```

However, this does not work, since now header files are not being included in the code coverage.

To experiment with this issue yourself, then try building this project with the command:

```
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTS=ON -DENABLE_COVERAGE=ON ..
make # make test is also available
make coverage
```

Running the code as it is above should result in a compilation freeze (The expected coverage is 60%). Now try the following changes:

In `CMakeLists.txt`, change:

```diff
-append_coverage_compiler_flags() # <-- Comment this line and uncomment the selected lines in src/CMakeLists.txt
+#append_coverage_compiler_flags() # <-- Comment this line and uncomment the selected lines in src/CMakeLists.txt
```

And in `src/CMakeLists.txt`, change:

```diff
-#[[if (ENABLE_COVERAGE) # Uncomment these lines
+if (ENABLE_COVERAGE) # Uncomment these lines
    target_compile_options(test-codecov-lib PRIVATE "-g;-O0;--coverage;-fprofile-arcs;-ftest-coverage")
-endif (ENABLE_COVERAGE)]]
+endif (ENABLE_COVERAGE)
```

Now run the same build steps. You should now get a higher code coverage (75%), as the code coverage in `include/test-codecov/sample.hpp` is completely ignored.
