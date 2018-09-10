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

#ifndef CALLIGRA_SHEETS_CELL_EDITOR_WIDGET
#define CALLIGRA_SHEETS_CELL_EDITOR_WIDGET

#include <QWidget>

namespace Calligra
{
namespace Sheets
{
class Sheet;
class Canvas;

class CellEditorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CellEditorWidget(QWidget* parent = nullptr);
    virtual ~CellEditorWidget();

    /// reimplemented from KoCanvasObserver
    virtual void setCanvas(Canvas *canvas);
    virtual void unsetCanvas();

protected: // reimplementations
    virtual void resizeEvent(QResizeEvent *event);

private Q_SLOTS:
    void toolChanged(const QString& toolId);

private:
    class Private;
    Private *const d;
};

} // namespace Sheets
} // namespace Calligra

#endif // CALLIGRA_SHEETS_CELL_EDITOR_WIDGET
