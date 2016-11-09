#-------------------------------------------------
#
# Project created by QtCreator 2016-11-04T13:41:55
#
#-------------------------------------------------

QT       -= core gui

TARGET = zdb
TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += private/include/hiredis \
    private/include/redis3m \
    private/include
SOURCES += \
    src/zdb/redis3m/patterns/median_filter.cpp \
    src/zdb/redis3m/patterns/scheduler.cpp \
    src/zdb/redis3m/patterns/script_exec.cpp \
    src/zdb/redis3m/utils/crc16.cpp \
    src/zdb/redis3m/utils/datetime.cpp \
    src/zdb/redis3m/utils/file.cpp \
    src/zdb/redis3m/utils/logging.cpp \
    src/zdb/redis3m/utils/resolv.cpp \
    src/zdb/redis3m/utils/sha1.cpp \
    src/zdb/redis3m/cluster_pool.cpp \
    src/zdb/redis3m/connection.cpp \
    src/zdb/redis3m/connection_pool.cpp \
    src/zdb/redis3m/reply.cpp \
    src/zdb/redis3m/simple_pool.cpp \
    src/zdb/hiredis/hiredis.c \
    src/zdb/hiredis/net.c \
    src/zdb/hiredis/read.c \
    src/zdb/hiredis/sds.c \
    src/zdb/zidgenerator.cpp \
    src/zdb/zdbproxy.cpp

HEADERS += \
    private/include/hiredis/fmacros.h \
    private/include/hiredis/hiredis.h \
    private/include/hiredis/net.h \
    private/include/hiredis/read.h \
    private/include/hiredis/sds.h \
    private/include/redis3m/patterns/median_filter.h \
    private/include/redis3m/patterns/model.h \
    private/include/redis3m/patterns/orm.h \
    private/include/redis3m/patterns/patterns.hpp \
    private/include/redis3m/patterns/scheduler.h \
    private/include/redis3m/patterns/script_exec.h \
    private/include/redis3m/patterns/simple_obj_store.h \
    private/include/redis3m/utils/crc16.h \
    private/include/redis3m/utils/datetime.h \
    private/include/redis3m/utils/exception.h \
    private/include/redis3m/utils/file.h \
    private/include/redis3m/utils/logging.h \
    private/include/redis3m/utils/noncopyable.h \
    private/include/redis3m/utils/pool.h \
    private/include/redis3m/utils/resolv.h \
    private/include/redis3m/utils/sha1.h \
    private/include/redis3m/cluster_pool.h \
    private/include/redis3m/command.h \
    private/include/redis3m/connection.h \
    private/include/redis3m/connection_pool.h \
    private/include/redis3m/redis3m.hpp \
    private/include/redis3m/reply.h \
    private/include/redis3m/simple_pool.h \
    src/zdb/zidgenerator.h \
    src/zdb/zdbproxy.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

INCLUDEPATH += /usr/local/include
LIBS += -L"/usr/local/lib" -lPocoFoundationd -lPocoJSONd -lPocoNetd -lPocoUtild -lPocoXMLd
LIBS += -L"/usr/local/lib" -lPocoFoundation -lPocoJSON -lPocoNet -lPocoUtil -lPocoXML

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
