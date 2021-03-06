﻿/* This file is part of the KDE project
   Copyright 2007 Stefan Nikolaus <stefan.nikolaus@kdemail.net>

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

// Local
#include "CellToolFactory.h"

//AFA #include <KLocalizedString>

//AFA #include <KoIcon.h>
#define koIconName QString

#include "CellTool.h"

using namespace Calligra::Sheets;

CellToolFactory::CellToolFactory(const QString& id)
        : KoToolFactoryBase(id)
{
    setToolTip(i18n("Cell formatting"));
    setIconName(koIconName("tool_cellformatting"));
    setToolType(dynamicToolType()+",calligrasheets");
    setPriority(0);
    setActivationShapeId("flake/always");
}

CellToolFactory::~CellToolFactory()
{
}

KoToolBase* CellToolFactory::createTool(KoCanvasBase* canvas)
{
    return new CellTool(canvas);
}

void CellToolFactory::setPriority(int priority)
{
    KoToolFactoryBase::setPriority(priority);
}

void CellToolFactory::setToolTip(const QString& toolTip)
{
    KoToolFactoryBase::setToolTip(toolTip);
}

void CellToolFactory::setIconName(const char *iconName)
{
    KoToolFactoryBase::setIconName(iconName);
}

void CellToolFactory::setIconName(const QString &iconName)
{
    KoToolFactoryBase::setIconName(iconName);
}
