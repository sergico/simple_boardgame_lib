QT += testlib
QT -= gui

DEPSPATH_FILE = "../depspath.pri"

!include($$DEPSPATH_FILE) {
    error("$$DEPSPATH_FILE file not found; project configuration aborted")
}

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH = $$SGL_BASEPATH

SOURCES +=  tst_test_genericresource.cpp
