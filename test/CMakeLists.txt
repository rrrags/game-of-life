set(CMAKE_CXX_COMPILER "g++-12")

# Add source files
set(TEST_FILE
test.cpp)

set(CPP_TEST_SOURCES ${CMAKE_SOURCE_DIR}/include/GOL.hpp)

find_package(GTest CONFIG REQUIRED)

add_executable(testGOL ${TEST_FILE} ${CPP_TEST_SOURCES})
target_link_libraries(testGOL PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
add_test(NAME testGOL COMMAND testGOL)

target_compile_features(testGOL PUBLIC cxx_std_20)
target_compile_options(testGOL PRIVATE -Wall -Wextra)
target_include_directories(testGOL PRIVATE ${CMAKE_SOURCE_DIR}/include)


