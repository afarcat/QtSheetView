/* Copyright (C) 2018 afarcat <kabak@sina.com>. All rights reserved.
   Use of this source code is governed by a Apache license that can be
   found in the LICENSE file.
*/

#include "sheetwidget.h"

#include <QVBoxLayout>

SheetWidget::SheetWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setMargin(0);

    sheetView = new View(this);

    layout->addWidget(sheetView);
}
