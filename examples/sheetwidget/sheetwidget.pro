# Copyright (C) 2018 afarcat <kabak@sina.com>. All rights reserved.
#   Use of this source code is governed by a Apache license that can be
#   found in the LICENSE file.

TARGET = SheetWidget
TEMPLATE = app

QT += core gui printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += ../../src/compat ../../src/source
INCLUDEPATH += ../../src/3rdparty/sheets ../../src/3rdparty/libs/widgets

DESTDIR = ../../bin

LIBS += -L$$DESTDIR
LIBS += -lQtSheetView

SOURCES += \
    main.cpp \
    sheetwidget.cpp

RESOURCES += \
    sheetwidget.qrc

HEADERS += \
    sheetwidget.h
