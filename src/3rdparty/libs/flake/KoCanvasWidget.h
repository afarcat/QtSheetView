/* This file is part of the KDE project
 * Copyright (C) 2006, 2008 Thomas Zander <zander@kde.org>
 * Copyright (C) 2007-2010 Boudewijn Rempt <boud@valdyas.org>
 * Copyright (C) 2007-2008 C. Boemann <cbo@boemann.dk>
 * Copyright (C) 2006-2007 Jan Hambrecht <jaham@gmx.net>
 * Copyright (C) 2009 Thorsten Zachmann <zachmann@kde.org>
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

#ifndef KOCANVASWIDGET_H
#define KOCANVASWIDGET_H

#include "flake_export.h"

#ifdef QT_WIDGETS_LIB
#include <QAbstractScrollArea>
#endif

#include <QPointer>

class KoShape;
class KoCanvasBase;

/**
 * KoCanvasWidget implementation for QWidget based canvases
 */
class FLAKE_EXPORT KoCanvasWidget : public QAbstractScrollArea
{
    Q_OBJECT
public:
    /// An enum to alter the positioning and size of the canvas inside the canvas controller
    enum CanvasMode {
        AlignTop,     ///< canvas is top aligned if smaller than the viewport
        Centered,     ///< canvas is centered if smaller than the viewport
        Infinite,     ///< canvas is never smaller than the viewport
        Spreadsheet   ///< same as Infinite, but supports right-to-left layouts
    };

    /**
     * Constructor.
     * @param parent the parent this widget will belong to
     */
    explicit KoCanvasWidget(QWidget *parent = 0);
    virtual ~KoCanvasWidget();

    /// Reimplemented from QObject
    virtual bool eventFilter(QObject *watched, QEvent *event);

#ifndef QT_WIDGETS_LIB
    void paint(QPainter *painter);

    void hoverMoveEvent(QHoverEvent *event);

    void ensureVisible(int x, int y, int xmargin = 50, int ymargin = 50);

    QWidget *viewport() const;
    void setViewport(QWidget *viewport);

    QQuickFlickable *flickable() const;

    QQuickScrollBar *horizontalScrollBar() const;
    QQuickScrollBar *verticalScrollBar() const;
#endif

public:
    /**
     * Sets the how the canvas behaves if the zoomed document becomes smaller than the viewport.
     * @param mode the new canvas mode, CanvasMode::Centered is the default value
     */
    virtual void setCanvasMode(CanvasMode mode);

    /// Returns the current canvas mode
    virtual CanvasMode canvasMode() const;

    /**
     * Reimplemented from QAbstractScrollArea.
     */
    void scrollContentsBy(int dx, int dy);

    virtual QSize viewportSize() const;

    /// Reimplemented from KoCanvasWidget

    /**
     * Activate this canvascontroller
     */
    virtual void activate();

    virtual void setDrawShadow(bool drawShadow);

    virtual void setCanvas(KoCanvasBase *canvas);

    virtual KoCanvasBase *canvas() const;

    /**
     * Change the actual canvas widget used by the current canvas. This allows the canvas widget
     * to be changed while keeping the current KoCanvasBase canvas and its associated resources as
     * they are. This might be used, for example, to switch from a QWidget to a QOpenGLWidget canvas.
     * @param widget the new canvas widget.
     */
    virtual void changeCanvasWidget(QWidget *widget);

    virtual int visibleHeight() const;
    virtual int visibleWidth() const;
    virtual int canvasOffsetX() const;
    virtual int canvasOffsetY() const;

    virtual void ensureVisible(const QRectF &rect, bool smooth = false);

    virtual void ensureVisible(KoShape *shape);

    /**
     * will cause the toolOptionWidgetsChanged to be emitted and all
     * listeners to be updated to the new widget.
     *
     * FIXME: This doesn't belong her and it does an
     * inherits("KoView") so it too much tied to komain
     *
     * @param widgets the map of widgets
     */
    void setToolOptionWidgets(const QList<QPointer<QWidget> > &widgets);

    virtual void zoomIn(const QPoint &center);

    virtual void zoomOut(const QPoint &center);

    virtual void zoomBy(const QPoint &center, qreal zoom);

    virtual void zoomTo(const QRect &rect);

    /**
     * Zoom document keeping point \p widgetPoint unchanged
     * \param widgetPoint sticky point in widget pixels
     */
    virtual void zoomRelativeToPoint(const QPoint &widgetPoint, qreal zoomCoeff);

    virtual void recenterPreferred();

    virtual void setPreferredCenter(const QPointF &viewPoint);

    /// Returns the currently set preferred center point in view coordinates (pixels)
    virtual QPointF preferredCenter() const;

    virtual void pan(const QPoint &distance);

    virtual int margin() const;

    virtual void setMargin(int margin);

    virtual QPoint scrollBarValue() const;

    /**
     * Used by KisCanvasController to correct the scrollbars position
     * after the rotation.
     */
    virtual void setScrollBarValue(const QPoint &value);

public slots:
    virtual void updateDocumentSize(const QSize &sz, bool recalculateCenter = true);

public:
    /**
     * Set mouse wheel to zoom behaviour
     * @param zoom if true wheel will zoom instead of scroll, control modifier will scroll
     */
    void setZoomWithWheel(bool zoom);

    virtual void setVastScrolling(qreal factor);

    QPoint documentOffset() const;

protected:
    void setDocumentSize(const QSize &sz);
    QSize documentSize() const;

    void setPreferredCenterFractionX(qreal);
    qreal preferredCenterFractionX() const;

    void setPreferredCenterFractionY(qreal);
    qreal preferredCenterFractionY() const;

    void setDocumentOffset( QPoint &offset);

    /**
     * \internal
     */
    class Private;
    KoCanvasWidget::Private *priv();

Q_SIGNALS:
    /**
     * Emitted when a previously added canvas is about to be removed.
     * @param canvasController this object
     */
    void canvasRemoved(KoCanvasWidget *canvasController);

    /**
     * Emitted when a canvas is set on this widget
     * @param canvasController this object
     */
    void canvasSet(KoCanvasWidget *canvasController);

    /**
     * Emitted whenever the document is scrolled.
     *
     * @param point the new top-left point from which the document should
     * be drawn.
     */
    void moveDocumentOffset(const QPoint &point);

    /**
     * Emit the new tool option widgets to be used with this canvas.
     */
    void toolOptionWidgetsChanged(const QList<QPointer<QWidget> > &widgets);

private Q_SLOTS:

    /// Called by the horizontal scrollbar when its value changes
    void updateCanvasOffsetX();

    /// Called by the vertical scrollbar when its value changes
    void updateCanvasOffsetY();

protected:
    friend class KisZoomAndPanTest;

    /// reimplemented from QWidget
    virtual void paintEvent(QPaintEvent *event);
    /// reimplemented from QWidget
    virtual void resizeEvent(QResizeEvent *resizeEvent);
    /// reimplemented from QWidget
    virtual void dragEnterEvent(QDragEnterEvent *event);
    /// reimplemented from QWidget
    virtual void dropEvent(QDropEvent *event);
    /// reimplemented from QWidget
    virtual void dragMoveEvent(QDragMoveEvent *event);
    /// reimplemented from QWidget
    virtual void dragLeaveEvent(QDragLeaveEvent *event);
    /// reimplemented from QWidget
    virtual void wheelEvent(QWheelEvent *event);
    /// reimplemented from QWidget
    virtual void keyPressEvent(QKeyEvent *event);
    /// reimplemented from QWidget
    virtual bool focusNextPrevChild(bool next);

private:
    Q_PRIVATE_SLOT(d, void activate())

    Private * const d;
};

#endif
