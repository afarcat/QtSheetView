/* This file is part of the KDE project
   Copyright 2006 - Robert Knight <robertknight@gmail.com>
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

#ifndef CALLIGRA_SHEETS_HEADERWIDGETS
#define CALLIGRA_SHEETS_HEADERWIDGETS

#ifdef QT_WIDGETS_LIB
#include <QWidget>
#endif
#include <QGuiApplication>
#include "Headers.h"

class QRubberBand;


namespace Calligra
{
namespace Sheets
{
class Canvas;
class View;

/**
 * The widget above the cells showing the column headers.
 */
#ifdef QT_WIDGETS_LIB
class ColumnHeaderWidget : public QWidget, public ColumnHeader
#else
class ColumnHeaderWidget : public QQuickPaintedItem, public ColumnHeader
#endif
{
    Q_OBJECT
public:
#ifdef QT_WIDGETS_LIB
    ColumnHeaderWidget(QWidget *_parent, Canvas *_canvas, View *_view);
#else
    explicit ColumnHeaderWidget(QWidget* parent = nullptr);  //AFA
#endif
    virtual ~ColumnHeaderWidget();

    virtual void updateColumns(int from, int to);
    virtual QSizeF size() const { return QWidget::size(); }
    virtual void setCursor(const QCursor& cursor) { QWidget::setCursor(cursor); }
    virtual void scroll(qreal dx, qreal dy) {
#ifdef QT_WIDGETS_LIB
        QWidget::scroll(dx, dy);
#else
        update();
#endif
    }
    virtual QPalette palette() const {
#ifdef QT_WIDGETS_LIB
        return QWidget::palette();
#else
        return qApp->palette();
#endif
    }
#ifdef QT_WIDGETS_LIB
    virtual void update() { QWidget::update(); }
#else
    virtual void update() { QQuickPaintedItem::update(); }
    virtual void paint(QPainter *painter);
#endif
private Q_SLOTS:
    void slotAutoScroll(const QPoint& distance);

protected:
    virtual void paintEvent(QPaintEvent* _ev);
    virtual void mousePressEvent(QMouseEvent* _ev);
    virtual void mouseReleaseEvent(QMouseEvent* _ev);
    virtual void mouseDoubleClickEvent(QMouseEvent* _ev);
    virtual void mouseMoveEvent(QMouseEvent* _ev);
    virtual void wheelEvent(QWheelEvent*);
    virtual void focusOutEvent(QFocusEvent* ev);
#ifndef QT_WIDGETS_LIB
    virtual void hoverMoveEvent(QHoverEvent *event);
#endif
    virtual void resizeEvent(QResizeEvent * _ev);

    virtual void paintSizeIndicator(int mouseX);
    virtual void removeSizeIndicator();
    
private Q_SLOTS:
    void toolChanged(const QString& toolId);

private:
    QRubberBand* m_rubberband;
};

/**
 * The widget left to the cells showing the row headers.
 */
#ifdef QT_WIDGETS_LIB
class RowHeaderWidget : public QWidget, public RowHeader
#else
class RowHeaderWidget : public QQuickPaintedItem, public RowHeader
#endif
{
    Q_OBJECT
public:
#ifdef QT_WIDGETS_LIB
    RowHeaderWidget(QWidget *_parent, Canvas *_canvas, View *_view);
#else
    explicit RowHeaderWidget(QWidget* parent = nullptr);  //AFA
#endif
    virtual ~RowHeaderWidget();

    void updateRows(int from, int to);
    virtual QSizeF size() const { return QWidget::size(); }
    virtual void setCursor(const QCursor& cursor) { QWidget::setCursor(cursor); }
    virtual void scroll(qreal dx, qreal dy) {
#ifdef QT_WIDGETS_LIB
        QWidget::scroll(dx, dy);
#else
        update();
#endif
    }
    virtual QPalette palette() const {
#ifdef QT_WIDGETS_LIB
        return QWidget::palette();
#else
        return qApp->palette();
#endif
    }
#ifdef QT_WIDGETS_LIB
    virtual void update() { QWidget::update(); }
#else
    virtual void update() { QQuickPaintedItem::update(); }
    virtual void paint(QPainter *painter);
#endif
private Q_SLOTS:
    void slotAutoScroll(const QPoint& distance);

protected:
    virtual void paintEvent(QPaintEvent* _ev);
    virtual void mousePressEvent(QMouseEvent* _ev);
    virtual void mouseReleaseEvent(QMouseEvent* _ev);
    virtual void mouseMoveEvent(QMouseEvent* _ev);
    virtual void mouseDoubleClickEvent(QMouseEvent* _ev);
    virtual void wheelEvent(QWheelEvent*);
    virtual void focusOutEvent(QFocusEvent* ev);
#ifndef QT_WIDGETS_LIB
    virtual void hoverMoveEvent(QHoverEvent *event);
#endif
    virtual void paintSizeIndicator(int mouseY);
    virtual void removeSizeIndicator();
private Q_SLOTS:
    void toolChanged(const QString& toolId);

private:
    QRubberBand* m_rubberband;
};

/**
 * The widget in the top left corner of the canvas,
 * responsible for selecting all cells in a sheet.
 */
#ifdef QT_WIDGETS_LIB
class SelectAllButtonWidget : public QWidget, public SelectAllButton
#else
class SelectAllButtonWidget : public QQuickPaintedItem, public SelectAllButton
#endif
{
    Q_OBJECT
public:
#ifdef QT_WIDGETS_LIB
    explicit SelectAllButtonWidget(CanvasBase* canvasBase);
#else
    explicit SelectAllButtonWidget(QWidget* parent = nullptr);  //AFA
#endif
    virtual ~SelectAllButtonWidget();

    virtual QPalette palette() const {
#ifdef QT_WIDGETS_LIB
        return QWidget::palette();
#else
        return qApp->palette();
#endif
    }
#ifdef QT_WIDGETS_LIB
    virtual void update() { QWidget::update(); }
#else
    virtual void update() { QQuickPaintedItem::update(); }
    virtual void paint(QPainter *painter);
#endif
protected:
    virtual void paintEvent(QPaintEvent* event);
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual void wheelEvent(QWheelEvent*);

private Q_SLOTS:
    void toolChanged(const QString& toolId);
};

} // namespace Sheets
} // namespace Calligra

#endif
