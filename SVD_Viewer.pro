QT       += core gui xml webenginewidgets axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#CONFIG += c++17
QMAKE_CXXFLAGS += /std:c++latest

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000 \   # disables all the APIs deprecated before Qt 6.0.0
    __cpp_lib_format=1

SOURCES += \
    acropdf.cpp \
    communicator.cpp \
    cpphighlighter.cpp \
    main.cpp \
    mainwindow.cpp \
    peripherals.cpp \
    svdmodel.cpp \
    svdnode.cpp \
    svdparser.cpp

HEADERS += \
    acropdf.h \
    communicator.h \
    cpphighlighter.h \
    mainwindow.h \
    peripherals.h \
    svdmodel.h \
    svdnode.h \
    svdparser.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    minified/web/pdf.viewer.js \
    minified/web/qwebchannel.js \
    minified/web/viewer.html \
    minified/web/viewer.css \
    ../pdf.js/web/viewer.js \
    ../pdf.js/web/viewer.css \
    ../pdf.js/web/viewer.html \
    acropdf.html

DESTDIR = $$PWD/bin
