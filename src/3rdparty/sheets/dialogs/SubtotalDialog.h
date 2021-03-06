/* This file is part of the KDE project
   Copyright (C) 2002-2003 Norbert Andres <nandres@web.de>
             (C) 2002 Philipp Mueller <philipp.mueller@gmx.de>
             (C) 2002 Laurent Montel <montel@kde.org>

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


#ifndef CALLIGRA_SHEETS_SUBTOTAL_DIALOG
#define CALLIGRA_SHEETS_SUBTOTAL_DIALOG

#include <KoDialog.h>

namespace Calligra
{
namespace Sheets
{
class Selection;

/**
 * \ingroup UI
 * Dialog to add subtotals.
 */
class SubtotalDialog : public KoDialog
{
    Q_OBJECT

public:
    SubtotalDialog(QWidget* parent, Selection* selection);
    ~SubtotalDialog();

public Q_SLOTS: // reimplemented
    virtual void accept();
    virtual void reject();

private Q_SLOTS:
    void slotUser1();

private:
    void fillColumnBoxes();
    void fillFunctionBox();
    void removeSubtotalLines();
    bool addSubtotal(int mainCol, int column, int row, int topRow,
                     bool addRow, QString const & text);

    class Private;
    Private *const d;
};

} // namespace Sheets
} // namespace Calligra

#endif // CALLIGRA_SHEETS_SUBTOTAL_DIALOG
