TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

SOURCES += \
        client.cpp \
        jsonhelper.cpp \
        main.cpp \
        repository.cpp \
        sendinglogic.cpp \
        server.cpp \
        worker.cpp

HEADERS += \
    client.h \
    jsonhelper.h \
    jsonhelper_копия.h \
    repository.h \
    sendinglogic.h \
    server.h \
    worker.h

QT += network core sql
