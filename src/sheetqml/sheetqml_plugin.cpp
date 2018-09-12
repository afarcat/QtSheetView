/* Copyright (C) 2018 afarcat <kabak@sina.com>. All rights reserved.
   Use of this source code is governed by a Apache license that can be
   found in the LICENSE file.
*/

#include <QtQml>

#include "sheetqml_plugin.h"

#include <part/View.h>
#include <part/Canvas.h>
#include <part/HeaderWidgets.h>
#include <KoCanvasWidget.h>

class QtSheetQmlPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT

    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    QtSheetQmlPlugin(QObject *parent = 0) : QQmlExtensionPlugin(parent) { }
    virtual void registerTypes(const char *uri)
    {
        registerSheetQmlTypes();
    }

};

void registerSheetQmlTypes()
{
    const char *uri = "QtSheetQml";

    Q_ASSERT(QLatin1String(uri) == QLatin1String("QtSheetQml"));

    // QtSheetQml 1.0
    qmlRegisterType<Calligra::Sheets::View>(uri, 1, 0, "SheetView");
    qmlRegisterType<Calligra::Sheets::Canvas>(uri, 1, 0, "SheetCanvas");
    qmlRegisterType<Calligra::Sheets::SelectAllButtonWidget>(uri, 1, 0, "SheetSelectAll");
    qmlRegisterType<Calligra::Sheets::ColumnHeaderWidget>(uri, 1, 0, "SheetColumnHeader");
    qmlRegisterType<Calligra::Sheets::RowHeaderWidget>(uri, 1, 0, "SheetRowHeader");
    qmlRegisterType<KoCanvasWidget>(uri, 1, 0, "SheetCanvasWidget");
}

#include "sheetqml_plugin.moc"
