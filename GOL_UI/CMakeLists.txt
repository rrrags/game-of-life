
find_package(Qt6  CONFIG REQUIRED COMPONENTS Core Gui Qml Quick Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(GOL_SOURCES
  grid.h
  gridModel.h
  gridModel.cpp
  main.cpp
)

set(GOL_QRCS
  qml/resource.qrc
)
qt_add_resources(GOL_SOURCES ${GOL_QRCS})

add_executable(GOL_GUI ${GOL_SOURCES}
)
target_link_libraries(GOL_GUI
  PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Qml
    Qt::Quick
)

target_compile_features(GOL_GUI PUBLIC cxx_std_20)

if(MSVC)
    target_compile_options(GOL_GUI PRIVATE /W4)
else()
    target_compile_options(GOL_GUI PRIVATE -Wall -Wextra)
endif()
