﻿/* This file is part of the KDE project
   Copyright 2009 Thomas Zander <zander@kde.org>
   Copyright 2006-2007 Stefan Nikolaus <stefan.nikolaus@kdemail.net>
   Copyright 2006 Robert Knight <robertknight@gmail.com>
   Copyright 2006 Inge Wallin <inge@lysator.liu.se>
   Copyright 1999-2002,2004 Laurent Montel <montel@kde.org>
   Copyright 2002-2005 Ariya Hidayat <ariya@kde.org>
   Copyright 1999-2004 David Faure <faure@kde.org>
   Copyright 2004-2005 Meni Livne <livne@kde.org>
   Copyright 2001-2003 Philipp Mueller <philipp.mueller@gmx.de>
   Copyright 2002-2003 Norbert Andres <nandres@web.de>
   Copyright 2003 Hamish Rodda <rodda@kde.org>
   Copyright 2003 Joseph Wenninger <jowenn@kde.org>
   Copyright 2003 Lukas Tinkl <lukas@kde.org>
   Copyright 2000-2002 Werner Trobin <trobin@kde.org>
   Copyright 2002 Harri Porten <porten@kde.org>
   Copyright 2002 John Dailey <dailey@vt.edu>
   Copyright 2002 Daniel Naber <daniel.naber@t-online.de>
   Copyright 1999-2000 Torben Weis <weis@kde.org>
   Copyright 1999-2000 Stephan Kulow <coolo@kde.org>
   Copyright 2000 Bernd Wuebben <wuebben@kde.org>
   Copyright 2000 Wilco Greven <greven@kde.org>
   Copyright 2000 Simon Hausmann <hausmann@kde.org
   Copyright 1999 Michael Reiher <michael.reiher@gmx.de>
   Copyright 1999 Boris Wedl <boris.wedl@kfunigraz.ac.at>
   Copyright 1999 Reginald Stadlbauer <reggie@kde.org>

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

// Local
#include "Canvas.h"
#include "CanvasBase_p.h"

// std
#include <assert.h>
#include <float.h>
#include <stdlib.h>

// Qt
#include <QGuiApplication>
#include <QBuffer>
#include <QByteArray>
#include <QClipboard>
#include <QDragLeaveEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QEvent>
#include <QFocusEvent>
#include <QKeyEvent>
#include <QList>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>
#include <QPixmap>
#include <QPoint>
#include <QTextStream>

#ifdef QT_WIDGETS_LIB
#include <QLabel>
#include <QMenu>
#include <QScrollBar>
#include <QToolTip>
#include <QWidget>
#endif

// KF5
//AFA #include <kxmlguifactory.h>

// Calligra
#include <KoCanvasWidget.h>
//AFA #include <KoShapeManager.h>
#include <KoToolManager.h>
#include <KoToolProxy.h>
#include <KoZoomHandler.h>
#include <KoPointerEvent.h>

// Sheets
#include "SheetsDebug.h"
#include "CellStorage.h"
#include "Doc.h"
#include "Global.h"
#include "HeaderWidgets.h"
#include "Localization.h"
#include "Map.h"
#include "RowColumnFormat.h"
#include "Sheet.h"
#include "Util.h"
#include "Validity.h"
#include "View.h"

// commands
#include "commands/CopyCommand.h"
#include "commands/DeleteCommand.h"
#include "commands/PasteCommand.h"
#include "commands/StyleCommand.h"

// ui
#include "ui/CellView.h"
#include "ui/Selection.h"
#include "ui/SheetView.h"

#define MIN_SIZE 10

using namespace Calligra::Sheets;

class Q_DECL_HIDDEN Canvas::Private
{
public:
    View *view;
};

/****************************************************************
 *
 * Canvas
 *
 ****************************************************************/

Canvas::Canvas(View *view)
        : QWidget(view)
        , CanvasBase(view ? view->doc() : 0)
        , cd(new Private)
{
    cd->view = view;

#ifdef QT_WIDGETS_LIB
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_StaticContents);
    setBackgroundRole(QPalette::Base);
    QWidget::setFocusPolicy(Qt::StrongFocus);
    setMouseTracking(true);

    setAcceptDrops(true);
    setAttribute(Qt::WA_InputMethodEnabled, true); // ensure using the InputMethod
#endif

    installEventFilter(this);   // for TAB key processing, otherwise focus change
}

Canvas::~Canvas()
{
#ifdef QT_WIDGETS_LIB
    foreach (QAction* action, actions()) {
        removeAction(action);
    }
#endif

    delete cd;
}

View* Canvas::view() const
{
    return cd->view;
}

void Canvas::setView(View *view)
{
    cd->view = view;

    setDoc(view ? view->doc() : 0);
}

void Canvas::mousePressEvent(QMouseEvent* event)
{
    //KoPointerEvent pev(event, QPointF());
    //mousePressed(&pev);

    QMouseEvent *const origEvent = event;
    QPointF documentPosition;
    if (layoutDirection() == Qt::LeftToRight) {
        documentPosition = viewConverter()->viewToDocument(event->pos()) + offset();
    } else {
        const QPoint position(QWidget::width() - event->x(), event->y());
        const QPointF offset(this->offset().x(), this->offset().y());
        documentPosition = viewConverter()->viewToDocument(position) + offset;
        debugSheets << "----------------------------";
        debugSheets << "event->pos():" << event->pos();
        debugSheets << "event->globalPos():" << event->globalPos();
        debugSheets << "position:" << position;
        debugSheets << "offset:" << offset;
        debugSheets << "documentPosition:" << documentPosition;
        event = new QMouseEvent(QEvent::MouseButtonPress, position, mapToGlobal(position), event->button(), event->buttons(), event->modifiers());
        debugSheets << "newEvent->pos():" << event->pos();
        debugSheets << "newEvent->globalPos():" << event->globalPos();
    }

#if 0  // This is disabled for now as per irc, as it blocks resize.
    // If the celltool is not active and we initiate a click on something that is not a flake element, we need
    // to reactivate the cell tool. THis is a temporary solution, pending the flake updates.
    if (KoToolManager::instance()->activeToolId() != "KSpreadCellToolId")
        if (!shapeManager()->shapeAt (documentPosition, KoFlake::ShapeOnTop))
            KoToolManager::instance()->switchToolRequested("KSpreadCellToolId");
#endif

    // flake
    if(CanvasBase::d->toolProxy) {
        CanvasBase::d->toolProxy->mousePressEvent(event, documentPosition);

        if (!event->isAccepted() && event->button() == Qt::RightButton) {
            showContextMenu(origEvent->globalPos());
            origEvent->setAccepted(true);
        }
    }

    if (layoutDirection() == Qt::RightToLeft) {
        delete event;
    }
}

void Canvas::showContextMenu(const QPoint& globalPos)
{
    //AFA
    //view()->unplugActionList("toolproxy_action_list");
    //view()->plugActionList("toolproxy_action_list", toolProxy()->popupActionList());
    //if (KXMLGUIFactory *factory = view()->factory()) {
    //    QMenu* menu = dynamic_cast<QMenu*>(factory->container("default_canvas_popup", view()));
    //    // Only show the menu, if there are items. The plugged action list counts as one action.
    //    if (menu && menu->actions().count() > 1) {
    //        menu->exec(globalPos);
    //    }
    //}
}

void Canvas::mouseReleaseEvent(QMouseEvent* event)
{
//    KoPointerEvent pev(event, QPointF());
//    mouseReleased(&pev);

    QPointF documentPosition;
    if (layoutDirection() == Qt::LeftToRight) {
        documentPosition = viewConverter()->viewToDocument(event->pos()) + offset();
    } else {
        const QPoint position(QWidget::width() - event->x(), event->y());
        const QPointF offset(this->offset().x(), this->offset().y());
        documentPosition = viewConverter()->viewToDocument(position) + offset;
        event = new QMouseEvent(QEvent::MouseButtonRelease, position, mapToGlobal(position), event->button(), event->buttons(), event->modifiers());
    }

    // flake
    if(CanvasBase::d->toolProxy) {
        CanvasBase::d->toolProxy->mouseReleaseEvent(event, documentPosition);
    }

    if (layoutDirection() == Qt::RightToLeft) {
       delete event;
    }
}

void Canvas::mouseMoveEvent(QMouseEvent* event)
{
//    KoPointerEvent pev(event, QPointF());
//    mouseMoved(&pev);

    QPointF documentPosition;
    if (layoutDirection() == Qt::LeftToRight) {
        documentPosition = viewConverter()->viewToDocument(event->pos()) + offset();
    } else {
        const QPoint position(QWidget::width() - event->x(), event->y());
        const QPointF offset(this->offset().x(), this->offset().y());
        documentPosition = viewConverter()->viewToDocument(position) + offset;
        event = new QMouseEvent(QEvent::MouseMove, position, mapToGlobal(position), event->button(), event->buttons(), event->modifiers());
    }

    // flake
    if(CanvasBase::d->toolProxy) {
        CanvasBase::d->toolProxy->mouseMoveEvent(event, documentPosition);
    }

    if (layoutDirection() == Qt::RightToLeft) {
       delete event;
    }
}

void Canvas::mouseDoubleClickEvent(QMouseEvent* event)
{
//    KoPointerEvent pev(event, QPointF());
//    mouseDoubleClicked(&pev);

    QPointF documentPosition;
    if (layoutDirection() == Qt::LeftToRight) {
        documentPosition = viewConverter()->viewToDocument(event->pos()) + offset();
    } else {
        const QPoint position(QWidget::width() - event->x(), event->y());
        const QPointF offset(this->offset().x(), this->offset().y());
        documentPosition = viewConverter()->viewToDocument(position) + offset;
        event = new QMouseEvent(QEvent::MouseButtonDblClick, position, mapToGlobal(position), event->button(), event->buttons(), event->modifiers());
    }

    // flake
    if (CanvasBase::d->toolProxy) {
        // If the celltool is not active and the double click is on something that is not a flake element, we need
        // to reactivate the cell tool. Normally flake would handle this, but the main app is not a shape, so we have to.
        // TODO: figure out a way to make the flake's functionality work. It'd likely require turning the main app
        // widget into a KoShape or something along those lines.

        if (KoToolManager::instance()->activeToolId() != "KSpreadCellToolId") {
            //AFA if (!shapeManager()->shapeAt (documentPosition, KoFlake::ShapeOnTop)) {
                KoToolManager::instance()->switchToolRequested("KSpreadCellToolId");
            //AFA     return;
            //AFA }
        }

        CanvasBase::d->toolProxy->mouseDoubleClickEvent(event, documentPosition);
    }

    if (layoutDirection() == Qt::RightToLeft) {
        delete event;
    }
}

bool Canvas::event(QEvent *e)
{
    if(toolProxy()) {
        toolProxy()->processEvent(e);
    }
    return QWidget::event(e);
}

void Canvas::paintEvent(QPaintEvent* event)
{
#ifdef QT_WIDGETS_LIB
    QPainter painter(this);
    paint(&painter, event->rect());
    event->accept();
#endif
}

void Canvas::dragEnterEvent(QDragEnterEvent* event)
{
    if (CanvasBase::dragEnter(event->mimeData())) {
        event->acceptProposedAction();
    }
}

void Canvas::dragMoveEvent(QDragMoveEvent* event)
{
    if (CanvasBase::dragMove(event->mimeData(), event->pos(), event->source())) {
        event->acceptProposedAction();
    } else {
        event->ignore();
    }
}

void Canvas::dragLeaveEvent(QDragLeaveEvent*)
{
    CanvasBase::dragLeave();
}

void Canvas::dropEvent(QDropEvent *event)
{
    if (CanvasBase::drop(event->mimeData(), event->pos(), event->source())) {
        event->setAccepted(true);
    } else {
        event->ignore();
    }
}

#ifndef QT_WIDGETS_LIB
void Canvas::update()
{
    if (view() && view()->canvasController()) {
        view()->canvasController()->update();
    }
}

void Canvas::update(const QRectF &rect)
{
    if (view() && view()->canvasController()) {
        view()->canvasController()->update(rect.toRect());
    }
}
#endif

void Canvas::setVertScrollBarPos(qreal pos)
{
#ifdef QT_WIDGETS_LIB
    if (pos < 0) pos = view()->vertScrollBar()->maximum() - pos;
    view()->vertScrollBar()->setValue((int)pos);
#else
    if (view() && view()->canvasController()) {
        QQuickFlickable *flickable = view()->canvasController()->flickable();
        if (flickable) {
            if (pos < 0) pos = flickable->contentHeight() - pos;
            flickable->setContentY(pos);
        }
    }
#endif
}

void Canvas::setHorizScrollBarPos(qreal pos)
{
#ifdef QT_WIDGETS_LIB
    if (pos < 0) pos = view()->horzScrollBar()->maximum() - pos;
    view()->horzScrollBar()->setValue((int)pos);
#else
    if (view() && view()->canvasController()) {
        QQuickFlickable *flickable = view()->canvasController()->flickable();
        if (flickable) {
            if (pos < 0) pos = flickable->contentWidth() - pos;
            flickable->setContentX(pos);
        }
    }
#endif
}

KoZoomHandler* Canvas::zoomHandler() const
{
    return view()->zoomHandler();
}

Sheet* Canvas::activeSheet() const
{
    return view()->activeSheet();
}

bool Canvas::isViewLoading() const
{
    return view()->isLoading();
}

SheetView* Canvas::sheetView(const Sheet* sheet) const
{
    return view()->sheetView(sheet);
}

Calligra::Sheets::Selection* Canvas::selection() const
{
    return view()->selection();
}

ColumnHeader* Canvas::columnHeader() const
{
    return view()->columnHeader();
}

RowHeader* Canvas::rowHeader() const
{
    return view()->rowHeader();
}

void Canvas::enableAutoScroll()
{
    view()->enableAutoScroll();
}

void Canvas::disableAutoScroll()
{
    view()->disableAutoScroll();
}

void Canvas::setCursor(const QCursor &cursor)
{
    QWidget::setCursor(cursor);
}
