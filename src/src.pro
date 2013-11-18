UI_DIR = tmp
MOC_DIR = tmp
RCC_DIR = tmp
OBJECTS_DIR = tmp

contains(QT_VERSION, ^5.*): QT += widgets
else: QT += gui

TARGET = atlas
DESTDIR = ../
CONFIG -= app_bundle

HEADERS += \
    mainwindow.h \
    scene.h

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    scene.cpp
