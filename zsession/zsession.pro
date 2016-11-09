#-------------------------------------------------
#
# Project created by QtCreator 2016-10-27T10:10:43
#
#-------------------------------------------------

QT       -= core gui

TARGET = zsession
TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH += /usr/local/include
LIBS += -L"/usr/local/lib" -lPocoFoundationd -lPocoJSONd -lPocoNetd -lPocoUtild -lPocoXMLd
LIBS += -L"/usr/local/lib" -lPocoFoundation -lPocoJSON -lPocoNet -lPocoUtil -lPocoXML

SOURCES += src/zsession/zsessionservice.cpp \
    private/aes256.c \
    private/base64url.cpp \
    private/sessiondata.cpp

HEADERS += src/zsession/zsessionservice.h \
    private/aes256.h \
    private/base64url.h \
    private/sessiondata.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter





win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../zcommon/release/ -lzcommon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../zcommon/debug/ -lzcommon
else:unix: LIBS += -L$$OUT_PWD/../zcommon/ -lzcommon

INCLUDEPATH += $$PWD/../zcommon
DEPENDPATH += $$PWD/../zcommon

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zcommon/release/libzcommon.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zcommon/debug/libzcommon.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zcommon/release/zcommon.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zcommon/debug/zcommon.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../zcommon/libzcommon.a
