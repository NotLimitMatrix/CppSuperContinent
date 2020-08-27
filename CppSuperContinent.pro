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
    Core/Block.cpp \
    Core/JsonParser.cpp \
    Core/Player.cpp \
    Core/ZoningSlot.cpp \
    GUI/GUI_MESSAGE.cpp \
    GUI/GUI_PANEL.cpp \
    GUI/GUI_WORLD.cpp \
    GUI/GUI_ZONING.cpp \
    GUI/SizeManager.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Const/COLOR.h \
    Const/STATIC.h \
    Core/Block.h \
    Core/JsonParser.h \
    Core/Player.h \
    Core/ZoningSlot.h \
    GUI/GUI_MESSAGE.h \
    GUI/GUI_PANEL.h \
    GUI/GUI_WORLD.h \
    GUI/GUI_ZONING.h \
    GUI/SizeManager.h \
    mainwindow.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
