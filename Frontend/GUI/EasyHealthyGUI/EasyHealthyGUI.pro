QT       += core gui quickwidgets virtualkeyboard qml quick concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

static {
    QT += svg
    QTPLUGIN += qtvirtualkeyboardplugin qtquickvirtualkeyboardplugin
}

CONFIG += c++11 disable-desktop link_pkgconfig

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MessageQueue.cpp \
    ceventfilter.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    MessageQueue.h \
    ceventfilter.h \
    fifo.h \
    widget.h

FORMS += \
    widget.ui

RESOURCES += \
    images.qrc \
    res.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /root/EasyHealthy/GUI
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
