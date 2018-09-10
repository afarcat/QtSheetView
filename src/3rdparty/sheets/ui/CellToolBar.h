/* Copyright (C) 2018 afarcat <kabak@sina.com>. All rights reserved.
   Use of this source code is governed by a Apache license that can be
   found in the LICENSE file.
*/

#ifndef CELLTOOLBAR_H
#define CELLTOOLBAR_H

#include <QToolBar>

namespace Calligra
{
namespace Sheets
{
class Canvas;

class CellToolBar : public QToolBar
{
    Q_OBJECT
public:
    explicit CellToolBar(QWidget *parent = nullptr);

public:
    void setCanvas(Canvas *canvas);
    void unsetCanvas();

private Q_SLOTS:
    void toolChanged(const QString& toolId);

private:
    Canvas *m_canvas;
};


} // namespace Sheets
} // namespace Calligra
#endif // CELLTOOLBAR_H
