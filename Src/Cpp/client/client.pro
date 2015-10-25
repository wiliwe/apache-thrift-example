TEMPLATE = app
TARGET = person_client

CONFIG += console
CONFIG -= app_bundle

#CONFIG -= qt
QT -= gui

CONFIG += link_pkgconfig
PKGCONFIG += thrift

LIBS += -lboost_system

SOURCES += main.cpp \
    Person_constants.cpp \
    Person_types.cpp \
    PersonService.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Person_constants.h \
    Person_types.h \
    PersonService.h
