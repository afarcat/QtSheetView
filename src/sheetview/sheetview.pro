# Copyright (C) 2018 afarcat <kabak@sina.com>. All rights reserved.
#   Use of this source code is governed by a Apache license that can be
#   found in the LICENSE file.

TARGET = QtSheetView
TEMPLATE = lib

QT += core gui xml sql printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += ENABLE_WIDGETS

DESTDIR = ../../bin

include (../src.pri)

INCLUDEPATH += $$PWD/../sheetqml
