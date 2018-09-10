/* Copyright (C) 2018 afarcat <kabak@sina.com>. All rights reserved.
   Use of this source code is governed by a Apache license that can be
   found in the LICENSE file.
*/

#include "CellToolBar.h"

// Calligra
#include <KoToolProxy.h>
#include <KoToolManager.h>

// Calligra Sheets
#include "CellToolBase.h"
#include "part/Canvas.h"

using namespace Calligra::Sheets;

CellToolBar::CellToolBar(QWidget *parent)
    : QToolBar(parent)
{
    m_canvas = nullptr;
}

void CellToolBar::setCanvas(Canvas *canvas)
{
    setEnabled(canvas != 0);

    m_canvas = canvas;

    if (m_canvas) {
        KoToolProxy *toolProxy = m_canvas->toolProxy();
        connect(toolProxy, SIGNAL(toolChanged(QString)), this, SLOT(toolChanged(QString)));
    }
}

void CellToolBar::unsetCanvas()
{
    if (m_canvas) {
        KoToolProxy *toolProxy = m_canvas->toolProxy();
        disconnect(toolProxy, SIGNAL(toolChanged(QString)), this, SLOT(toolChanged(QString)));
    }

    m_canvas = nullptr;
}

void CellToolBar::toolChanged(const QString &toolId)
{
    debugSheets << "tool changed to" << toolId;

    const bool isCellTool = toolId == QLatin1String("KSpreadCellToolId");
    setEnabled(isCellTool);

    if (isCellTool) {
        KoToolBase* tool = KoToolManager::instance()->toolById(m_canvas, toolId);
        CellToolBase *cellTool = qobject_cast<CellToolBase*>(tool);
        Q_ASSERT(cellTool);

        addAction(cellTool->action("cut"));
        addAction(cellTool->action("copy"));
        addAction(cellTool->action("paste"));

        addSeparator();

        addAction(cellTool->action("cellStyle"));

        addSeparator();

        addAction(cellTool->action("alignLeft"));
        addAction(cellTool->action("alignCenter"));
        addAction(cellTool->action("alignRight"));
        addAction(cellTool->action("alignTop"));
        addAction(cellTool->action("alignMiddle"));
        addAction(cellTool->action("alignBottom"));

        addSeparator();

        addAction(cellTool->action("borderLeft"));
        addAction(cellTool->action("borderRight"));
        addAction(cellTool->action("borderTop"));
        addAction(cellTool->action("borderBottom"));
        addAction(cellTool->action("borderAll"));
        addAction(cellTool->action("borderRemove"));

        addSeparator();

        addAction(cellTool->action("mergeCells"));
        addAction(cellTool->action("mergeCellsHorizontal"));
        addAction(cellTool->action("mergeCellsVertical"));
        addAction(cellTool->action("dissociateCells"));

        addSeparator();

        addAction(cellTool->action("insertColumn"));
        addAction(cellTool->action("deleteColumn"));
        addAction(cellTool->action("insertRow"));
        addAction(cellTool->action("deleteRow"));
    }
}
