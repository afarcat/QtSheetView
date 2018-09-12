/* Copyright (C) 2018 afarcat <kabak@sina.com>. All rights reserved.
   Use of this source code is governed by a Apache license that can be
   found in the LICENSE file.
*/

import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.0

import QtSheetQml 1.0

//AFA: QtSheetQml basic struct
SheetView {
    id: sheetView
    canvas: sheetCanvas

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        SheetCanvas {
            id: sheetCanvas
            Layout.fillWidth: true
            Layout.fillHeight: true

            GridLayout {
                anchors.fill: parent
                columnSpacing: 0; rowSpacing: 0

                SheetSelectAll {
                    id: sheetSelectAll
                    objectName: "selectAll"
                    Layout.row: 0; Layout.column: 0; Layout.rowSpan: 1; Layout.columnSpan: 1
                }
                SheetColumnHeader {
                    objectName: "columnHeader"
                    Layout.row: 0; Layout.column: 1; Layout.rowSpan: 1; Layout.columnSpan: 1
                    Layout.fillWidth: true
                }
                SheetRowHeader {
                    objectName: "rowHeader"
                    Layout.row: 1; Layout.column: 0; Layout.rowSpan: 1; Layout.columnSpan: 1
                    Layout.fillHeight: true
                }
                ScrollView {
                    objectName: "scrollView"
                    clip: true
                    Layout.row: 1; Layout.column: 1; Layout.rowSpan: 1; Layout.columnSpan: 1
                    x: sheetSelectAll.width
                    y: sheetSelectAll.height
                    width: sheetCanvas.width - sheetSelectAll.width
                    height: sheetCanvas.height - sheetSelectAll.height

                    SheetCanvasWidget {
                        objectName: "canvasWidget"
                        x: 0
                        y: 0
                        width: sheetCanvas.width - sheetSelectAll.width
                        height: sheetCanvas.height - sheetSelectAll.height
                    }
                }
            }
        }

        TabBar {
            objectName: "tabBar"
            Layout.fillWidth: true
        }
    }
}
