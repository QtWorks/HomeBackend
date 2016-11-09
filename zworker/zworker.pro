#-------------------------------------------------
#
# Project created by QtCreator 2016-11-02T15:39:27
#
#-------------------------------------------------

QT       -= core gui

TARGET = worker
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    src/zworker/zworker.cpp

HEADERS += \
    src/zworker/zworker.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

INCLUDEPATH += /usr/local/include
LIBS += -L"/usr/local/lib" -lPocoFoundationd -lPocoJSONd -lPocoNetd -lPocoUtild -lPocoXMLd
LIBS += -L"/usr/local/lib" -lPocoFoundation -lPocoJSON -lPocoNet -lPocoUtil -lPocoXML
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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../zdevice/release/ -lzdevice
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../zdevice/debug/ -lzdevice
else:unix: LIBS += -L$$OUT_PWD/../zdevice/ -lzdevice

INCLUDEPATH += $$PWD/../zdevice
DEPENDPATH += $$PWD/../zdevice

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zdevice/release/libzdevice.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zdevice/debug/libzdevice.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zdevice/release/zdevice.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zdevice/debug/zdevice.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../zdevice/libzdevice.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../zsession/release/ -lzsession
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../zsession/debug/ -lzsession
else:unix: LIBS += -L$$OUT_PWD/../zsession/ -lzsession

INCLUDEPATH += $$PWD/../zsession
DEPENDPATH += $$PWD/../zsession

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zsession/release/libzsession.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zsession/debug/libzsession.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zsession/release/zsession.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zsession/debug/zsession.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../zsession/libzsession.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../zsession/release/ -lzsession
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../zsession/debug/ -lzsession
else:unix: LIBS += -L$$OUT_PWD/../zsession/ -lzsession

INCLUDEPATH += $$PWD/../zsession
DEPENDPATH += $$PWD/../zsession

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zsession/release/libzsession.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zsession/debug/libzsession.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zsession/release/zsession.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zsession/debug/zsession.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../zsession/libzsession.a
