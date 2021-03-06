﻿/* This file is part of the KDE project
   Copyright 2008 Stefan Nikolaus stefan.nikolaus@kdemail.net

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

#ifndef KSPREAD_CANVAS_RESOURCES
#define KSPREAD_CANVAS_RESOURCES

//AFA #include <KoCanvasResourceManager.h>

namespace Calligra
{
namespace Sheets
{

/**
 * Calligra Sheets specific canvas resources
 */
namespace CanvasResource
{
enum {
    Selection = 6000    //AFA KoCanvasResourceManager::SheetsStart  ///< the cell selection
};
} // namespace CanvasResource

} // namespace Sheets
} // namespace Calligra

#endif // KSPREAD_CANVAS_RESOURCES
