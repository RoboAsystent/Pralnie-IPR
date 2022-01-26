QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    authorization.cpp \
    main.cpp \
    loginwidget.cpp \
    menuwidget.cpp \
    navigationwidget.cpp \
    order.cpp \
    orderdetailswidget.cpp \
    orderlist.cpp \
    orderwidget.cpp \
    servercaller.cpp

HEADERS += \
    authorization.h \
    loginwidget.h \
    menuwidget.h \
    navigationwidget.h \
    order.h \
    orderdetailswidget.h \
    orderlist.h \
    orderwidget.h \
    servercaller.h

FORMS += \
    loginwidget.ui \
    menu.ui \
    orderdetailswidget.ui \
    orderwidget.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
