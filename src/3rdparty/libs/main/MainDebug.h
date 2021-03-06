﻿/*
 *  Copyright (c) 2015 Friedrich W. H. Kossebau <kossebau@kde.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */
#ifndef MAIN_DEBUG_H_
#define MAIN_DEBUG_H_

#include <QDebug>
#include <QLoggingCategory>
#include <komain_export.h>

//AFA extern const KOMAIN_EXPORT QLoggingCategory &MAIN_LOG();
QLoggingCategory MAIN_LOG("calligra.lib.main");
#define debugMain qCDebug(MAIN_LOG)
#define warnMain qCWarning(MAIN_LOG)
#define errorMain qCCritical(MAIN_LOG)

//AFA extern const KOMAIN_EXPORT QLoggingCategory &FILTER_LOG();
QLoggingCategory FILTER_LOG("calligra.lib.filter");
#define debugFilter qCDebug(FILTER_LOG)
#define warnFilter qCWarning(FILTER_LOG)
#define errorFilter qCCritical(FILTER_LOG)

#endif
