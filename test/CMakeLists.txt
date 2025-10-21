# Create an executable for running test cases.
add_executable(TestFilenameValidator TestFilenameValidator.cpp)

# Link the required libraries.
target_link_libraries(TestFilenameValidator 
	              PRIVATE 
		      FilenameValidator
)
target_link_libraries(TestFilenameValidator 
	              PUBLIC
		      /usr/lib/libgtest.a
		      /usr/lib/libgtest_main.a
)

# Enable testing.
enable_testing()
include(CTest)

# Make the tests discoverable using Ctest command.
include(GoogleTest)
gtest_discover_tests(TestFilenameValidator)
