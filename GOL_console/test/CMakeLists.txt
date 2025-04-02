set(TEST_FILE test.cpp)

set(HPP_TEST_SOURCES ${CMAKE_SOURCE_DIR}/GOL_console/GOL.hpp)

find_package(GTest CONFIG REQUIRED)

add_executable(testGOL ${TEST_FILE} ${HPP_TEST_SOURCES}) 
target_link_libraries(testGOL PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
add_test(NAME testGOL COMMAND testGOL)

target_compile_features(testGOL PUBLIC cxx_std_20)

if(MSVC)
    target_compile_options(testGOL PRIVATE /W4)
else()
    target_compile_options(testGOL PRIVATE -Wall -Wextra)
endif()

target_include_directories(testGOL PRIVATE ${CMAKE_SOURCE_DIR}/GOL_console)


