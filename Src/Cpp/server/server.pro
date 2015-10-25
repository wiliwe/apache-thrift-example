TEMPLATE = app
TARGET = person_server

CONFIG += console
CONFIG -= app_bundle

#CONFIG -= qt
QT -= gui

CONFIG += link_pkgconfig
PKGCONFIG += thrift

LIBS += -lboost_system

SOURCES += \
    Person_constants.cpp \
    Person_types.cpp \
    PersonService.cpp \
    PersonService_server.skeleton.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Person_constants.h \
    Person_types.h \
    PersonService.h

