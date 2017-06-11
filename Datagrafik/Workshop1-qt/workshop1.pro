#-------------------------------------------------
#
# Project created by QtCreator 2016-10-18T12:10:47
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Workshop1
TEMPLATE = app


SOURCES +=\
    openglwindow.cpp \
    geometryrender.cpp \
    workshop1.cpp \
	ass2widget.cpp

HEADERS  += \
    openglwindow.h \
    geometryrender.h \
	ass2widget.h

FORMS    +=	\
    ass2widget.ui

OTHER_FILES += \
    vshader.glsl \
    fshader.glsl
