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
    GUI_power_panel.cpp \
    GUI_research_panel.cpp \
    GUI_resource_panel.cpp \
    GUI_select.cpp \
    GUI_world.cpp \
    GUI_zoning.cpp \
    main.cpp \
    MainGui.cpp

HEADERS += \
    Core.h \
    GUI_power_panel.h \
    GUI_research_panel.h \
    GUI_resource_panel.h \
    GUI_select.h \
    GUI_world.h \
    GUI_zoning.h \
    MainGui.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
