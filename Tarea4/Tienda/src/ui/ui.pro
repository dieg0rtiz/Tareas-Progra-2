QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    formid.cpp \
    formproducto.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    formid.h \
    formproducto.h \
    mainwindow.h

FORMS += \
    formid.ui \
    formproducto.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Tienda/release/ -lTienda
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Tienda/debug/ -lTienda
else:unix: LIBS += -L$$OUT_PWD/../Tienda/ -lTienda

INCLUDEPATH += $$PWD/../Tienda
DEPENDPATH += $$PWD/../Tienda

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Tienda/release/libTienda.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Tienda/debug/libTienda.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Tienda/release/Tienda.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Tienda/debug/Tienda.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Tienda/libTienda.a
