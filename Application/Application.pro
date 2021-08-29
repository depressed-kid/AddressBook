# Specifies the Qt modules that are used by your project.
QT += quick

# Specifies project configuration and compiler options. 
CONFIG += c++17 # C++14 support is enabled.

# compiler emit warnings if you use
# any Qt feature that has been marked deprecated
DEFINES += QT_DEPRECATED_WARNINGS

# Specifies the names of all source files in the project.
SOURCES += main.cpp \
    src/contactsreader.cpp \
    src/contact.cpp \
    src/contactsmodel.cpp

# Specifies the name of the resource collection files (qrc) for the target. 
RESOURCES += qml.qrc 

QML_IMPORT_PATH += $$PWD/qml
QML2_IMPORT_PATH += $$PWD/qml

# Specifies the name of the target (executable) file. 
TARGET = app

INCLUDEPATH += $$PWD/include

LIBS += -L$$PWD/../shared/lib/ -lDBManager
INCLUDEPATH += $$PWD/../shared/include


HEADERS += \
    include/contactsreader.h \
    include/contact.h \
    include/contactsmodel.h



