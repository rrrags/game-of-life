cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_COMPILER "g++-12")

project(gol)

# Specify include directories

# Add source files
set(CPP_SOURCES
src/main.cpp)

set(HPP_SOURCES include/GOL.hpp)  

#find_package(spdlog REQUIRED) 
#find_package(Eigen3 REQUIRED)

# Define the executable 
add_executable(gol ${CPP_SOURCES} ${HPP_SOURCES})
#target_link_libraries(gol PRIVATE spdlog::spdlog)
#target_link_libraries(gol PRIVATE Eigen3::Eigen)

enable_testing()
add_subdirectory(test)


target_compile_features(gol PUBLIC cxx_std_20)
target_compile_options(gol PRIVATE -Wall -Wextra)
target_include_directories(gol PRIVATE ${PROJECT_SOURCE_DIR}/include)


