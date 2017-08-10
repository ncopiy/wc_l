QT += core
QT -= gui

CONFIG += c++11

TARGET = wc_l_c_plus_plus
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    terminal.cpp

HEADERS += \
    terminal.h
