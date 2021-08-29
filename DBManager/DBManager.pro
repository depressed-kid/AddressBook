QT -= gui  // так как библеотека 
QT += core sql
CONFIG += c++17
TEMPLATE = lib

DEFINES += BUILD_TESTS
DEFINES += INSERT_TEST_DATA
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    src/manipulator.cpp \
    src/processor.cpp \
    src/selector.cpp \
    src/executor.cpp \
    src/dbmanager.cpp \
    src/connector.cpp \
    src/creator.cpp

DESTDIR = $$PWD/../shared/lib/
INCLUDEPATH += $$PWD/include

HEADERS +=\
    include/executor.h \
    include/connector.h \
    include/creator.h \
    include/dbmanager.h \
    include/dbtypes.h \
    include/selector.h \
    include/processor.h \
    include/manipulator.h \
    include/dbmapper.h \


headers.path += $$PWD/../shared/include
headers.files += include/dbtypes.h \
                include/processor.h
INSTALLS += headers










