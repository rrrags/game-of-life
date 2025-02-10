cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_COMPILER "g++-12")

project(test)

# Specify include directories

# Add source files
set(CPP_SOURCES
src/main.cpp)

set(HPP_SOURCES include/GOL.hpp)

#find_package(spdlog REQUIRED)
#find_package(Eigen3 REQUIRED)

# Define the executable
add_executable(test ${CPP_SOURCES} ${HPP_SOURCES})
#target_link_libraries(test PRIVATE spdlog::spdlog)
#target_link_libraries(test PRIVATE Eigen3::Eigen)



target_compile_features(test PUBLIC cxx_std_20)
target_compile_options(test PRIVATE -Wall -Wextra)
target_include_directories(test PRIVATE ${PROJECT_SOURCE_DIR}/include)


