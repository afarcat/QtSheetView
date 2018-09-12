.pragma library // shared library
.import QtQuick 2.0 as QQ

var QComboBoxComponent = Qt.createComponent("QComboBox.qml");
var QTextEditComponent = Qt.createComponent("QTextEdit.qml");

function createQmlWidget(parent, className) {
    var WidgetComponent = null;

    if (className === "QComboBox")
        WidgetComponent = QComboBoxComponent;
    else if (className === "QTextEdit")
        WidgetComponent = QTextEditComponent;

    if (WidgetComponent === null) {
        console.log("unknown className=", className);
    }

    if (WidgetComponent.status === QQ.Component.Ready) {
        var widget = WidgetComponent.createObject(
                    parent,
                    {"visible": true}); //default is visible

        if (widget === null) {
            // Error Handling
            console.log("Error creating object");

            return null;
        }

        return widget;
    }
    else if (WidgetComponent.status === QQ.Component.Error) {
        // Error Handling
        console.log("Error loading component:", WidgetComponent.errorString());

        return null;
    }

    return null;
}
