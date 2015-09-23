# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/GNU-Linux-x86
TARGET = MyVersion
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
PKGCONFIG +=
QT = core gui widgets
SOURCES += MurmurHash2.cpp MyTableModel.cpp filearchiver.cpp main.cpp mainwindow.cpp pathChoice.cpp version.cpp
HEADERS += MurmurHash2.h MyTableModel.h filearchiver.h mainwindow.h pathChoice.h version.h
FORMS += mainwindow.ui pathChoice.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += `cppunit-config --libs`  
