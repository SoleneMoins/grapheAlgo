QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    affichage_numerique.cpp \
    arc.cpp \
    explication.cpp \
    fs_aps.cpp \
    graphenonoriente.cpp \
    graphe.cpp \
    main.cpp \
    mainwindow.cpp \
    matrice_adjacence.cpp \
    saise_valeur_arc.cpp \
    saisie_fs.cpp \
    saisie_nom_sommet.cpp \
    sommet.cpp \
    zone_dessin.cpp

HEADERS += \
    affichage_numerique.h \
    arc.h \
    explication.h \
    fs_aps.h \
    graphenonoriente.h \
    graphe.h \
    mainwindow.h \
    matrice_adjacence.h \
    saise_valeur_arc.h \
    saisie_fs.h \
    saisie_nom_sommet.h \
    sommet.h \
    zone_dessin.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
