# Copyright (C) 2018 afarcat <kabak@sina.com>. All rights reserved.
#   Use of this source code is governed by a Apache license that can be
#   found in the LICENSE file.

DEFINES += KSHEET_LIBRARY

msvc {
    DEFINES += _USE_MATH_DEFINES
}

CONFIG(release, debug|release) {
DEFINES += QT_NO_DEBUG_OUTPUT
}

#make sure this at first
INCLUDEPATH += $$PWD/compat $$PWD/source

include (3rdparty/libs.pri)
include (3rdparty/sheets.pri)
