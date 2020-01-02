cmake_minimum_required(VERSION 3.12)
project(marsrover)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -std=gnu++17")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include_directories(include)
add_executable(game src/main.cpp)

include(FetchContent)
FetchContent_Declare(
        rangev3
        GIT_REPOSITORY https://github.com/ericniebler/range-v3.git
        GIT_TAG        0.10.0
)
FetchContent_GetProperties(rangev3)
if(NOT rangev3_POPULATED)
    FetchContent_Populate(rangev3)
    add_subdirectory(${rangev3_SOURCE_DIR} ${rangev3_BINARY_DIR})
    include_directories(${rangev3_SOURCE_DIR}/include)
endif()


FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.10.0
)
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
    include_directories(${googletest_SOURCE_DIR}/googletest/include)
endif()
include(GoogleTest)
enable_testing()
macro(gtest TESTNAME)
    add_executable(${TESTNAME} ${ARGN})
    target_link_libraries(${TESTNAME} PUBLIC gtest gmock gtest_main)

    gtest_discover_tests(${TESTNAME}
            TEST_PREFIX "${TESTNAME}."
            PROPERTIES FOLDER "tests")
endmacro()
add_subdirectory(tests)