/* This file is part of the KDE project
   Copyright 2011 Marijn Kruisselbrink <mkruisselbrink@kde.org>
   Copyright (C) 2018 afarcat <kabak@sina.com>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#include "CellEditorWidget.h"

// Qt
#include <QGridLayout>
#include <QHBoxLayout>
#include <QResizeEvent>
#include <QToolButton>

// Calligra
#include <KoToolProxy.h>
#include <KoToolManager.h>

// Calligra Sheets
#include "SheetsDebug.h"
#include "CellToolBase.h"
#include "ExternalEditor.h"
#include "LocationComboBox.h"
#include "SheetView.h"
#include "part/Canvas.h"

using namespace Calligra::Sheets;

class CellEditorWidget::Private
{
public:
    Canvas *canvas;
    LocationComboBox *locationComboBox;
    QToolButton *formulaButton, *applyButton, *cancelButton;
    ExternalEditor *editor;
    QGridLayout *layout;
    CellToolBase *cellTool;
    QPointer<KoToolProxy> toolProxy;
    bool canvasResetBugWorkaround;
};

CellEditorWidget::CellEditorWidget(QWidget* parent)
    : QWidget(parent), d(new Private)
{
    setWindowTitle(i18n("Cell Editor"));

    d->canvas = 0;
    d->canvasResetBugWorkaround = false;

    d->locationComboBox = new LocationComboBox(this);
    d->locationComboBox->setMinimumWidth(100);

    d->editor = new ExternalEditor(this);
    d->editor->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
    d->editor->setMaximumHeight(d->locationComboBox->height());

    d->formulaButton = new QToolButton(this);
    d->formulaButton->setText(i18n("Formula"));

    d->applyButton = new QToolButton(this);
    d->applyButton->setDefaultAction(d->editor->applyAction());

    d->cancelButton = new QToolButton(this);
    d->cancelButton->setDefaultAction(d->editor->cancelAction());

    QHBoxLayout *layout = new QHBoxLayout();
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addWidget(d->formulaButton);
    layout->addWidget(d->applyButton);
    layout->addWidget(d->cancelButton);

    d->layout = new QGridLayout(this);
    d->layout->setMargin(0);
    d->layout->setObjectName(QLatin1String("CellToolOptionWidget::Layout"));
    d->layout->addWidget(d->locationComboBox, 0, 0, Qt::AlignVCenter);
    d->layout->addLayout(layout, 0, 1, Qt::AlignVCenter);
    d->layout->addWidget(d->editor, 0, 2, Qt::AlignVCenter);
    d->layout->setColumnStretch(2, 1);
}

CellEditorWidget::~CellEditorWidget()
{
    delete d;
}

void CellEditorWidget::setCanvas(Canvas *canvas)
{
    setEnabled(canvas != 0);

    d->canvasResetBugWorkaround = !!d->canvas;
    if (d->toolProxy) {
        disconnect(d->toolProxy, SIGNAL(toolChanged(QString)), this, SLOT(toolChanged(QString)));
    }
    d->canvas = canvas;
    if (d->canvas) {
        d->locationComboBox->setSelection(d->canvas->selection());
        d->toolProxy = d->canvas->toolProxy();
        connect(d->toolProxy, SIGNAL(toolChanged(QString)), this, SLOT(toolChanged(QString)));
    }
}

void CellEditorWidget::unsetCanvas()
{
    if (d->canvasResetBugWorkaround) return;
    debugSheets << "unsetting canvas";
    if (d->toolProxy) {
        disconnect(d->toolProxy, SIGNAL(toolChanged(QString)), this, SLOT(toolChanged(QString)));
    }
    d->canvas = 0;
    d->toolProxy = 0;
    d->locationComboBox->setSelection(0);
}

void CellEditorWidget::resizeEvent(QResizeEvent *event)
{
    const int margin = 2 * d->layout->margin();
    const int newWidth = event->size().width();
    const int minWidth = d->layout->minimumSize().width();
    // The triggering width is the same in both cases, but it is calculated in
    // different ways.
    // After a row got occupied, it does not vanish anymore, even if all items
    // get removed. Hence, check for the existence of the item in the 2nd row.
    if (!d->layout->itemAtPosition(1, 0)) { /* one row */
        const int column = d->layout->count() - 1;
        QLayoutItem *const item = d->layout->itemAtPosition(0, column);
        if (!item) {
            QWidget::resizeEvent(event);
            return;
        }
        const int itemWidth = item->minimumSize().width();
        if (newWidth <= 2 *(minWidth - itemWidth) + margin) {
            d->layout->removeItem(item);
            d->layout->addItem(item, 1, 0, 1, column + 1);
            d->layout->setRowStretch(0, 0);
            d->layout->setRowStretch(1, 1);
        }
    } else { /* two rows */
        if (newWidth > 2 * minWidth + margin) {
            QLayoutItem *const item = d->layout->itemAtPosition(1, 0);
            d->layout->removeItem(item);
            d->layout->addItem(item, 0, d->layout->count());
            d->layout->setRowStretch(0, 1);
            d->layout->setRowStretch(1, 0);
        }
    }
    QWidget::resizeEvent(event);
}

void CellEditorWidget::toolChanged(const QString &toolId)
{
    debugSheets << "tool changed to" << toolId;

    const bool isCellTool = toolId == QLatin1String("KSpreadCellToolId");
    setEnabled(isCellTool);

    if (isCellTool) {
        KoToolBase* tool = KoToolManager::instance()->toolById(d->canvas, toolId);
        d->cellTool = qobject_cast<CellToolBase*>(tool);
        Q_ASSERT(d->cellTool);
        d->editor->setCellTool(d->cellTool);
        d->cellTool->setExternalEditor(d->editor);
        d->formulaButton->setDefaultAction(d->cellTool->action("insertFormula"));
        debugSheets << tool << d->cellTool;
    }
}
