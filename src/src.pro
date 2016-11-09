QT += core sql
QT -= gui

CONFIG += c++11

TARGET = home_backend
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    serverapp.cpp

HEADERS += \
    serverapp.h



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../zhttp/release/ -lzhttp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../zhttp/debug/ -lzhttp
else:unix: LIBS += -L$$OUT_PWD/../zhttp/ -lzhttp

INCLUDEPATH += $$PWD/../zhttp
DEPENDPATH += $$PWD/../zhttp

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zhttp/release/libzhttp.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zhttp/debug/libzhttp.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zhttp/release/zhttp.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zhttp/debug/zhttp.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../zhttp/libzhttp.a

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


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../database/release/ -ldatabase
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../database/debug/ -ldatabase
else:unix: LIBS += -L$$OUT_PWD/../database/ -ldatabase

INCLUDEPATH += $$PWD/../database
DEPENDPATH += $$PWD/../database

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../database/release/libdatabase.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../database/debug/libdatabase.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../database/release/database.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../database/debug/database.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../database/libdatabase.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../zsocket/release/ -lzsocket
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../zsocket/debug/ -lzsocket
else:unix: LIBS += -L$$OUT_PWD/../zsocket/ -lzsocket

INCLUDEPATH += $$PWD/../zsocket
DEPENDPATH += $$PWD/../zsocket

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zsocket/release/libzsocket.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zsocket/debug/libzsocket.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zsocket/release/zsocket.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zsocket/debug/zsocket.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../zsocket/libzsocket.a

INCLUDEPATH += /usr/local/include
LIBS += -L"/usr/local/lib" -lPocoFoundationd -lPocoJSONd -lPocoNetd -lPocoUtild -lPocoXMLd
LIBS += -L"/usr/local/lib" -lPocoFoundation -lPocoJSON -lPocoNet -lPocoUtil -lPocoXML
QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../zdb/release/ -lzdb
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../zdb/debug/ -lzdb
else:unix: LIBS += -L$$OUT_PWD/../zdb/ -lzdb

INCLUDEPATH += $$PWD/../zdb
DEPENDPATH += $$PWD/../zdb

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zdb/release/libzdb.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zdb/debug/libzdb.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zdb/release/zdb.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zdb/debug/zdb.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../zdb/libzdb.a

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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../zworker/release/ -lworker
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../zworker/debug/ -lworker
else:unix: LIBS += -L$$OUT_PWD/../zworker/ -lworker

INCLUDEPATH += $$PWD/../zworker
DEPENDPATH += $$PWD/../zworker

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zworker/release/libworker.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zworker/debug/libworker.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zworker/release/worker.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../zworker/debug/worker.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../zworker/libworker.a
