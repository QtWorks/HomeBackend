#-------------------------------------------------
#
# Project created by QtCreator 2016-11-03T10:54:55
#
#-------------------------------------------------

QT       -= core gui

TARGET = zsocket
TEMPLATE = lib
CONFIG += staticlib

SOURCES += src/zsocket/zsocket.cpp \
    src/zsocket/tcpserverhandlerfactory.cpp

HEADERS += src/zsocket/zsocket.h \
    src/zsocket/tcpserverhandlerfactory.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}


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

INCLUDEPATH += /usr/local/include
LIBS += -L"/usr/local/lib" -lPocoFoundationd -lPocoJSONd -lPocoNetd -lPocoUtild -lPocoXMLd
LIBS += -L"/usr/local/lib" -lPocoFoundation -lPocoJSON -lPocoNet -lPocoUtil -lPocoXML
QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter

INCLUDEPATH += /usr/local/include
LIBS += -L"/usr/local/lib" -lPocoFoundationd -lPocoJSONd -lPocoNetd -lPocoUtild -lPocoXMLd
LIBS += -L"/usr/local/lib" -lPocoFoundation -lPocoJSON -lPocoNet -lPocoUtil -lPocoXML
QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter
