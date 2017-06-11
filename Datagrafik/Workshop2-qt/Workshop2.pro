#-------------------------------------------------
#
# Project created by QtCreator 2016-10-18T12:10:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Workshop2
TEMPLATE = app


SOURCES += main.cpp\
    openglwindow.cpp \
    geometryrender.cpp

HEADERS  += \
    openglwindow.h \
    geometryrender.h

FORMS    +=

OTHER_FILES += \
    vshader.glsl \
    fshader.glsl
