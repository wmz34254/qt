QT       += core gui multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    apple.cpp \
    banana.cpp \
    basket.cpp \
    bomb.cpp \
    dialoghelp.cpp \
    dialogover.cpp \
    game.cpp \
    item.cpp \
    main.cpp \
    mainwindow.cpp \
    pear.cpp \
    spider.cpp

HEADERS += \
    apple.h \
    banana.h \
    basket.h \
    bomb.h \
    dialoghelp.h \
    dialogover.h \
    game.h \
    global.h \
    item.h \
    mainwindow.h \
    pear.h \
    spider.h

FORMS += \
    dialoghelp.ui \
    dialogover.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    game.qrc
