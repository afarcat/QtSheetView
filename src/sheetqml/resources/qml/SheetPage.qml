/* Copyright (C) 2018 afarcat <kabak@sina.com>. All rights reserved.
   Use of this source code is governed by a Apache license that can be
   found in the LICENSE file.
*/

import QtQuick 2.7
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.3
import QtQuick.Layouts 1.0

import QtSheetQml 1.0
import "qrc:/resources/qml/QWidgetLogic.js" as QWidgetLogic

//AFA: QtSheetQml basic struct
//At leat QtQuick.Controls 2.3 (Qt 5.10)
Page {
    id: sheetRoot

    header: Rectangle {
        width: parent.width
        height: rowLayout.height
        color: Material.backgroundColor

        RowLayout {
            id: rowLayout
            width: parent.width

            ComboBox {
                objectName: "locationComboBox"
                editable: true
            }

            ToolButton {
                objectName: "applyAction"
            }

            ToolButton {
                objectName: "cancelAction"
            }

            TextArea {
                id: textArea
                objectName: "externalEditor"
                topPadding: 4
                bottomPadding: 4
                Layout.fillWidth: true

                background: Rectangle {
                    y: parent.height - height + 6
                    height: textArea.activeFocus ? 2 : 1
                    color: textArea.activeFocus ? Material.accentColor : Material.hintTextColor
                }
            }
        }
    }

    SheetView {
        id: sheetView
        width: parent.width
        height: parent.height

        SheetCanvas {
            id: sheetCanvas
            objectName: "sheetCanvas"

            GridLayout {
                width: parent.width
                height: parent.height
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
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    SheetCanvasWidget {
                        objectName: "canvasWidget"
                        width: sheetCanvas.width - sheetSelectAll.width
                        height: sheetCanvas.height - sheetSelectAll.height

                        Component.onCompleted: {
                            sheetView.buildLayout(sheetRoot);
                        }
                    }
                }
            }
        }

        function createQmlWidget(parent, className)
        {
            return QWidgetLogic.createQmlWidget(parent, className);
        }

        function destroyQmlWidget(qmlWidget)
        {
            if (qmlWidget !== null) {
                qmlWidget.destroy();
            }
        }
    }

    //
    Component {
        id: tabButtonComponent

        TabButton {
            width: implicitWidth
        }
    }

    footer: TabBar {
        id: tabBar
        objectName: "tabBar"

        signal tabChanged(string name)
        onCurrentIndexChanged: {
            var tabButton = tabBar.itemAt(tabBar.currentIndex);
            tabChanged(tabButton.text);
        }
    }

    function addTab(name)
    {
        var tabButton = tabButtonComponent.createObject(tabBar);
        tabButton.text = name;
        tabBar.addItem(tabButton);
    }

    function removeTab(name)
    {
        var tabIndex = getTabIndex(name);
        if (tabIndex !== -1) {
            var tabButton = tabBar.itemAt(tabIndex);
            tabBar.removeItem(tabButton);
        }
    }

    function setActiveTab(name)
    {
        var tabIndex = getTabIndex(name);
        if (tabIndex !== -1) {
            tabBar.currentIndex = tabIndex;
        }
    }

    function activeTab()
    {
        var tabButton = tabBar.itemAt(tabBar.currentIndex);
        if (tabButton !== null) {
            return tabButton.text;
        }
        return "";
    }

    function moveTab(from, to)
    {
        tabBar.moveItem(from, to);
    }

    function ensureVisible(name)
    {
        var tabIndex = getTabIndex(name);
        if (tabIndex !== -1) {
            tabBar.currentIndex = tabIndex;
        }
    }

    function getTabIndex(name)
    {
        for (var tabIndex = 0; tabIndex < tabBar.count; tabIndex++)
        {
            if (tabBar.itemAt(tabIndex).text === name) {
                return tabIndex;
            }
        }

        return -1;
    }
}
