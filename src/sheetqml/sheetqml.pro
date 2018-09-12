# Copyright (C) 2018 afarcat <kabak@sina.com>. All rights reserved.
#   Use of this source code is governed by a Apache license that can be
#   found in the LICENSE file.

TARGET = QtSheetQml
TEMPLATE = lib

QT += core gui xml sql
QT += quick quickcontrols2
QT += qml-private quick-private quicktemplates2-private

DESTDIR = ../../bin

include (../src.pri)

INCLUDEPATH += $$PWD

HEADERS += \
    sheetqml_plugin.h \
    sheetqml_ui.h

SOURCES += \
    sheetqml_plugin.cpp \
    sheetqml_ui.cpp

RESOURCES += sheetqml.qrc
