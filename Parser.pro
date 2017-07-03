QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Parser
TEMPLATE = app

SOURCES += main.cpp mainwindow.cpp \
        buttons.cpp \
        parser.cpp \
        tools.cpp

HEADERS += mainwindow.h \
        parser.h

FORMS += mainwindow.ui
