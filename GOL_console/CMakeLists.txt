add_subdirectory(test)

set(CPP_SOURCES main.cpp)

set(HPP_SOURCES GOL.hpp)  

add_executable(GOL_console_main ${CPP_SOURCES} ${HPP_SOURCES})

target_compile_features(GOL_console_main PUBLIC cxx_std_20)

if(MSVC)
    target_compile_options(GOL_console_main PRIVATE /W4)
else()
    target_compile_options(GOL_console_main PRIVATE -Wall -Wextra)
endif()

target_include_directories(GOL_console_main PRIVATE ${PROJECT_SOURCE_DIR}/GOL_console) 