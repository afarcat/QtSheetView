/* Copyright (C) 2018 afarcat <kabak@sina.com>. All rights reserved.
   Use of this source code is governed by a Apache license that can be
   found in the LICENSE file.
*/

#include <QApplication>
#include <QScreen>

#include "sheetwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SheetWidget sheetWidget;

    QScreen *screen = qApp->primaryScreen();
    sheetWidget.resize(screen->availableSize().width()*0.75, screen->availableSize().height()*0.75);
    sheetWidget.move(screen->availableSize().width()*0.125, screen->availableSize().height()*0.125);

    sheetWidget.show();

    return a.exec();
}
