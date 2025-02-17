set(CMAKE_CXX_COMPILER "g++-12")

# Specify include directories

# Add source files
set(CPP_TEST_SOURCES
test.cpp)

set(HPP_TEST_SOURCES ${CMAKE_SOURCE_DIR}/include/GOL.hpp)

#find_package(spdlog REQUIRED)
#find_package(Eigen3 REQUIRED)

# Define the executable
add_executable(test ${CPP_TEST_SOURCES} ${HPP_TEST_SOURCES})
#target_link_libraries(test PRIVATE spdlog::spdlog)
#target_link_libraries(test PRIVATE Eigen3::Eigen)



target_compile_features(test PUBLIC cxx_std_20)
target_compile_options(test PRIVATE -Wall -Wextra)
target_include_directories(test PRIVATE ${CMAKE_SOURCE_DIR}/include)


