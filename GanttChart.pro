#-------------------------------------------------
#
# Project created by QtCreator 2014-03-19T23:35:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GanttChart
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    about.cpp \
    documentation.cpp \
    ganttgraphics.cpp \
    spinboxdelegate.cpp \
    dateeditdelegate.cpp \
    fileio.cpp

HEADERS  += mainwindow.h \
    about.h \
    documentation.h \
    ganttgraphics.h \
    spinboxdelegate.h \
    dateeditdelegate.h \
    fileio.h

FORMS    += mainwindow.ui \
    about.ui \
    documentation.ui
