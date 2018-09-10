/* Copyright (C) 2018 afarcat <kabak@sina.com>. All rights reserved.
   Use of this source code is governed by a Apache license that can be
   found in the LICENSE file.
*/

#ifndef SHEETWIDGET_H
#define SHEETWIDGET_H

#include <QWidget>

#include "part/View.h"

using namespace Calligra::Sheets;

class SheetWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SheetWidget(QWidget *parent = nullptr);

signals:

public slots:

private:
    View *sheetView;
};

#endif // SHEETWIDGET_H
