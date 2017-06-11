#-------------------------------------------------
#
# Project created by QtCreator 2016-10-18T12:10:47
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Work1
TEMPLATE = app


SOURCES +=\
    openglwindow.cpp \
    geometryrender.cpp \
    work1.cpp

HEADERS  += \
    openglwindow.h \
    geometryrender.h

FORMS    +=

OTHER_FILES += \
    vshader.glsl \
    fshader.glsl
