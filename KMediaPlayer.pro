#-------------------------------------------------
#
# Project created by QtCreator 2014-06-11T12:49:15
#
#-------------------------------------------------

QT       += core gui
QT += phonon

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KMediaPlayer
TEMPLATE = app


SOURCES += main.cpp\
    kmplayer.cpp \
    mediaplayer.cpp \
    dialog.cpp \
    mediavideowidget.cpp

HEADERS  += \
    mediaplayer.h \
    dialog.h \
    kmplayer.h \
    mediavideowidget.h \
    MyHeader.h

FORMS    += widget.ui \
    mediaplayer.ui \
    dialog.ui

RESOURCES += \
    KMP.qrc
