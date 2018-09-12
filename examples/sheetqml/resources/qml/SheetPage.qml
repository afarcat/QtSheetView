/* Copyright (C) 2018 afarcat <kabak@sina.com>. All rights reserved.
   Use of this source code is governed by a Apache license that can be
   found in the LICENSE file.
*/

import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0

//AFA: SheetItem file in QtSheetQml
import "qrc:/resources/qml"

Page {
    id: page

    SheetItem {
        id: sheetPart
        anchors.fill: parent
    }
}
