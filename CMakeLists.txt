cmake_minimum_required(VERSION 3.15)
project(FilenameValidator VERSION 1.0)

#add_subdirectory(src)
#add_subdirectory(test)

#include(CodeCoverage)
#APPEND_COVERAGE_COMPILER_FLAGS()
#setup_target_for_coverage_lcov(
#    NAME coverage
#    EXECUTABLE ctest -j
#    DEPENDENCIES my_test_target
#)

# === Enable coverage option ===
option(ENABLE_COVERAGE "Enable code coverage" OFF)

include(FetchContent)
FetchContent_Declare(
  code_coverage
  URL https://raw.githubusercontent.com/bilke/cmake-modules/master/CodeCoverage.cmake
  DOWNLOAD_NO_EXTRACT TRUE
)
FetchContent_MakeAvailable(code_coverage)
include(${code_coverage_SOURCE_DIR}/CodeCoverage.cmake)

# code coverage
if(ENABLE_COVERAGE)
    message(STATUS "Coverage enabled")
    #APPEND_COVERAGE_COMPILER_FLAGS()
    add_compile_options(--coverage -O0 -g)
    add_link_options(--coverage)
    # Setup coverage target (uses lcov)
    setup_target_for_coverage_lcov(
        NAME coverage
        EXECUTABLE ctest -j
	DEPENDENCIES TestFilenameValidator
	LCOV_ARGS --ignore-errors mismatch
    )
endif()

add_subdirectory(src)
add_subdirectory(test)

enable_testing()
include(CTest)
