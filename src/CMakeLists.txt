set(atlas_SOURCES
    main.cpp
    mainwindow.cpp
    scene.cpp
)
set(atlas_HEADERS
    mainwindow.h
    scene.h
)

set(QT_USE_QTOPENGL true)

qt4_wrap_cpp(atlas_HEADERS_MOC ${atlas_HEADERS})
include(${QT_USE_FILE})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_definitions(${QT_DEFINITIONS})

add_executable(../atlas ${atlas_SOURCES} ${atlas_HEADERS_MOC})
target_link_libraries(../atlas ${QT_LIBRARIES})
