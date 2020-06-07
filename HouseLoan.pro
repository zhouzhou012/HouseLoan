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
    choosetype.cpp \
    combine1.cpp \
    combine2.cpp \
    commercial1.cpp \
    commercial2.cpp \
    getinformation1.cpp \
    getinformation2.cpp \
    getinformation3.cpp \
    main.cpp \
    mainscene.cpp \
    mypushbutton.cpp \
    mypushbutton1.cpp

HEADERS += \
    choosetype.h \
    combine1.h \
    combine2.h \
    commercial1.h \
    commercial2.h \
    getinformation1.h \
    getinformation2.h \
    getinformation3.h \
    mainscene.h \
    mypushbutton.h \
    mypushbutton1.h

FORMS += \
    choosetype.ui \
    combine1.ui \
    combine2.ui \
    commercial1.ui \
    commercial2.ui \
    getinformation1.ui \
    getinformation2.ui \
    getinformation3.ui \
    mainscene.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
