# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux-x86
TARGET = MyVersion
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += MurmurHash2.cpp MyTableModel.cpp filearchiver.cpp main.cpp mainwindow.cpp pathChoice.cpp version.cpp
HEADERS += MurmurHash2.h MyTableModel.h filearchiver.h mainwindow.h pathChoice.h version.h
FORMS += mainwindow.ui pathChoice.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += /usr/include/boost /usr/include/cppconn /usr/include/qt4 
LIBS += -Wl,-rpath,/usr/lib /usr/lib/libmysqlcppconn.so -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libQtGui.so -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libQtCore.so `cppunit-config --libs`  
