﻿/* This file is part of the KDE project
   Copyright 2006 - Robert Knight <robertknight@gmail.com>

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

#ifndef CALLIGRA_SHEETS_HEADERS
#define CALLIGRA_SHEETS_HEADERS

#ifdef QT_WIDGETS_LIB
#include <QWidget>
#endif

#include "sheets_common_export.h"

class QLabel;
class KoPointerEvent;

namespace Calligra
{
namespace Sheets
{
class CanvasBase;
class Selection;

/**
 * Base class for the widget above the cells showing the column headers.
 */
class CALLIGRA_SHEETS_COMMON_EXPORT ColumnHeader
{
public:
    explicit ColumnHeader(CanvasBase *_canvas);
    virtual ~ColumnHeader();

    void setCanvas(CanvasBase* canvasBase); //AFA

    int markerColumn() const {
        return  m_iSelectionAnchor;
    }
    void equalizeColumn(double resize);

    virtual void updateColumns(int from, int to) = 0;
    virtual QSizeF size() const = 0;
    qreal width() const { return size().width(); }
    qreal height() const { return size().height(); }
    virtual void setCursor(const QCursor& cursor) = 0;
    virtual void scroll(qreal dx, qreal dy) = 0;
    virtual QPalette palette() const = 0;
    virtual void update() = 0;

    void setHeaderFont(const QFont& font);
    QFont headerFont() const;
protected:
    void paint(QPainter* painter, const QRectF& painterRect);
    void mousePress(KoPointerEvent* _ev);
    void mouseRelease(KoPointerEvent* _ev);
    void mouseDoubleClick(KoPointerEvent* _ev);
    void mouseMove(KoPointerEvent* _ev);
    void focusOut(QFocusEvent* ev);
    void resize(const QSizeF& size, const QSizeF& oldSize);
    virtual void paintSizeIndicator(int mouseX) = 0;
    virtual void removeSizeIndicator() = 0;
    
    void doToolChanged(const QString& toolId);

protected:
    CanvasBase *m_pCanvas;

    /**
     * Flag that indicates whether the user wants to mark columns.
     * The user may mark columns by dragging the mouse around in th XBorder widget.
     * If the user is doing that right now, this flag is true. Mention that the user may
     * also resize columns by dragging the mouse. This case is not covered by this flag.
     */
    bool m_bSelection;

    /**
     * The column over which the user pressed the mouse button.
     * If the user marks columns in the XBorder widget, then this is the initial
     * column on which the user pressed the mouse button.
     */
    int m_iSelectionAnchor;

    /**
     * Flag that indicates whether the user resizes a column
     * The user may resize columns by dragging the mouse around in the ColumnHeader widget.
     * If the user is doing that right now, this flag is true.
     */
    bool m_bResize;

    /**
     * The column over which the user pressed the mouse button.
     * The user may resize columns by dragging the mouse around the XBorder widget.
     * This is the column over which the user pressed the mouse button. This column is going
     * to be resized.
      */
    int m_iResizedColumn;

    /**
     * Last position of the mouse, when resizing.
     */
    int m_iResizePos;

    /**
     * The label used for showing the current size, when resizing
     */
    QLabel *m_lSize;

    /**
     * True when the mouse button is pressed
     */
    bool m_bMousePressed;

    bool m_cellToolIsActive;

    QFont m_font;
};



/**
 * Base class for the widget left to the cells showing the row headers.
 */
class CALLIGRA_SHEETS_COMMON_EXPORT RowHeader
{
public:
    explicit RowHeader(CanvasBase *_canvas);
    virtual ~RowHeader();

    void setCanvas(CanvasBase* canvasBase); //AFA

    int markerRow() const {
        return  m_iSelectionAnchor;
    }
    void equalizeRow(double resize);
    
    virtual void updateRows(int from, int to) = 0;
    virtual QSizeF size() const = 0;
    qreal width() const { return size().width(); }
    qreal height() const { return size().height(); }
    virtual void setCursor(const QCursor& cursor) = 0;
    virtual void scroll(qreal dx, qreal dy) = 0;
    virtual QPalette palette() const = 0;
    virtual void update() = 0;

    void setHeaderFont(const QFont& font);
    QFont headerFont() const;
protected:
    void paint(QPainter* painter, const QRectF& painterRect);
    void mousePress(KoPointerEvent* _ev);
    void mouseRelease(KoPointerEvent* _ev);
    void mouseDoubleClick(KoPointerEvent* _ev);
    void mouseMove(KoPointerEvent* _ev);
    void focusOut(QFocusEvent* ev);
    virtual void paintSizeIndicator(int mouseX) = 0;
    virtual void removeSizeIndicator() = 0;

    void doToolChanged(const QString& toolId);
protected:
    CanvasBase *m_pCanvas;

    bool m_bSelection;
    int m_iSelectionAnchor;
    bool m_bResize;
    int m_iResizedRow;
    int m_iResizePos;
    /**
     * The label used for showing the current size, when resizing
     */
    QLabel *m_lSize;

    /**
     * True when the mouse button is pressed
     */
    bool m_bMousePressed;

    bool m_cellToolIsActive;

    QFont m_font;
};



/**
 * Base class for the widget in the top left corner of the canvas,
 * responsible for selecting all cells in a sheet.
 */
class SelectAllButton
{
public:
    explicit SelectAllButton(CanvasBase* canvasBase);
    virtual ~SelectAllButton();

    void setCanvas(CanvasBase* canvasBase); //AFA

    virtual QPalette palette() const = 0;
    virtual void update() = 0;
protected:
    void paint(QPainter* painter, const QRectF& painterRect);
    void mousePress(KoPointerEvent* event);
    void mouseRelease(KoPointerEvent* event);
    void doToolChanged(const QString& toolId);

protected:
    CanvasBase* m_canvasBase;
    bool m_mousePressed;
    bool m_cellToolIsActive;
};

} // namespace Sheets
} // namespace Calligra

#endif
