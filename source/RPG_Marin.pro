#-------------------------------------------------
#
# Project created by QtCreator 2017-04-20T22:03:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RPG_Marin
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    personnage.cpp \
    heros.cpp \
    savetools.cpp \
    combat.cpp \
    attaqueaction.cpp \
    attaque.cpp \
    statsmodifier.cpp \
    setattaque.cpp \
    slacsheffectattaquedial.cpp \
    ennemiesset.cpp \
    operatorequal.cpp \
    briefing.cpp \
    infospersos.cpp

HEADERS  += mainwindow.h \
    personnage.h \
    heros.h \
    savetools.h \
    combat.h \
    attaqueaction.h \
    attaque.h \
    statsmodifier.h \
    setattaque.h \
    slacsheffectattaquedial.h \
    ennemiesset.h \
    operatorequal.h \
    briefing.h \
    infospersos.h

FORMS    += mainwindow.ui \
    combat.ui \
    statsmodifier.ui \
    setattaque.ui \
    slacsheffectattaquedial.ui \
    ennemiesset.ui \
    briefing.ui \
    infospersos.ui

DISTFILES += \
    tableau_noms
