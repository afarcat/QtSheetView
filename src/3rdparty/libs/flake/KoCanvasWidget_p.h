/* This file is part of the KDE project
 *
 * Copyright (C) 2006, 2008-2009 Thomas Zander <zander@kde.org>
 * Copyright (C) 2006 Peter Simonsson <peter.simonsson@gmail.com>
 * Copyright (C) 2006, 2009 Thorsten Zachmann <zachmann@kde.org>
 * Copyright (C) 2007-2010 Boudewijn Rempt <boud@valdyas.org>
 * Copyright (C) 2007 C. Boemann <cbo@boemann.dk>
 * Copyright (C) 2006-2008 Jan Hambrecht <jaham@gmx.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */
#ifndef KoCanvasWidget_p_h
#define KoCanvasWidget_p_h

#include "KoCanvasWidget.h"

#include "KoCanvasWidgetViewport_p.h"
//AFA #include "KoShape.h"
#include "KoViewConverter.h"
#include "KoCanvasBase.h"
//AFA #include "KoCanvasObserverBase.h"
//AFA #include "KoCanvasSupervisor.h"
#include "KoToolManager_p.h"

//AFA #include <FlakeDebug.h>
#include <QMouseEvent>
#include <QPainter>
#include <QEvent>
#include <QTimer>
#ifdef QT_WIDGETS_LIB
#include <QDockWidget>
#include <QScrollBar>
#endif

//AFA #include <KoConfig.h>

class Q_DECL_HIDDEN KoCanvasWidget::Private
{
public:

    Private(KoCanvasWidget *qq)
        : q(qq)
        , canvas(0)
        , ignoreScrollSignals(false)
        , zoomWithWheel(false)
        , vastScrollingFactor(0)
        , canvasMode(Centered)
        , margin(0)
        , preferredCenterFractionX(0.5)
        , preferredCenterFractionY(0.5)
    {
    }

    /**
     * Gets called by the tool manager if this canvas controller is the current active canvas controller.
     */
    void setDocumentOffset();

    void resetScrollBars();
    void emitPointerPositionChangedSignals(QEvent *event);

    void activate();
    void unsetCanvas();

    KoCanvasWidget *q;
    KoCanvasBase *canvas;
#ifdef QT_WIDGETS_LIB
    Viewport *viewportWidget;
#else
    QPointer<QQuickScrollView> viewport;
#endif
    bool ignoreScrollSignals;
    bool zoomWithWheel;
    qreal vastScrollingFactor;

    CanvasMode canvasMode;
    int margin;
    QSize documentSize;
    QPoint documentOffset;
    qreal preferredCenterFractionX;
    qreal preferredCenterFractionY;
};

#endif
