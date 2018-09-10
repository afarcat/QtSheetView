/* This file is part of the KDE project

   Copyright (C) 2006 Thorsten Zachmann <zachmann@kde.org>

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

#include "KoCanvasBase.h"
//AFA #include "KoCanvasResourceManager.h"
//AFA #include "KoShapeController.h"
#include "KoCanvasWidget.h"
#include "KoViewConverter.h"
//AFA #include "KoSnapGuide.h"
//AFA #include "SnapGuideConfigWidget.h"
//AFA #include "KoShapeManager.h"
//AFA #include "KoToolProxy.h"
//AFA #include "KoSelection.h"

class Q_DECL_HIDDEN KoCanvasBase::Private
{
public:
    Private() : //AFA shapeController(0),
        //AFA resourceManager(0),
        //AFA isResourceManagerShared(false),
        controller(0)//,
        //AFA snapGuide(0)
    {
    }

    ~Private() {
        //AFA delete shapeController;
        //AFA if (!isResourceManagerShared) {
        //AFA     delete resourceManager;
        //AFA }
        //AFA delete snapGuide;
    }
    //AFA KoShapeController *shapeController;
    //AFA KoCanvasResourceManager *resourceManager;
    //AFA bool isResourceManagerShared;
    KoCanvasWidget *controller;
    //AFA KoSnapGuide *snapGuide;
};

KoCanvasBase::KoCanvasBase(KoShapeBasedDocumentBase *shapeBasedDocument, KoCanvasResourceManager *sharedResourceManager)
        : d(new Private())
{
    //AFA
    //d->resourceManager = sharedResourceManager ?
    //    sharedResourceManager : new KoCanvasResourceManager();
    //d->isResourceManagerShared = sharedResourceManager;

    //d->shapeController = new KoShapeController(this, shapeBasedDocument);
    //d->snapGuide = new KoSnapGuide(this);
}

KoCanvasBase::~KoCanvasBase()
{
    delete d;
}

QPointF KoCanvasBase::viewToDocument(const QPointF &viewPoint) const
{
    return viewConverter()->viewToDocument(viewPoint - documentOrigin());
}

KoShapeController *KoCanvasBase::shapeController() const
{
    return nullptr; //AFA d->shapeController;
}

void KoCanvasBase::disconnectCanvasObserver(QObject *object)
{
    //AFA
    //if (shapeManager()) shapeManager()->selection()->disconnect(object);
    //if (resourceManager()) resourceManager()->disconnect(object);
    //if (shapeManager()) shapeManager()->disconnect(object);
    //if (toolProxy()) toolProxy()->disconnect(object);
}


KoCanvasResourceManager *KoCanvasBase::resourceManager() const
{
    return nullptr; //AFA d->resourceManager;
}

void KoCanvasBase::ensureVisible(const QRectF &rect)
{
    if (d->controller && d->controller->canvas())
        d->controller->ensureVisible(
                d->controller->canvas()->viewConverter()->documentToView(rect));
}

void KoCanvasBase::setCanvasController(KoCanvasWidget *controller)
{
    d->controller = controller;
}

KoCanvasWidget *KoCanvasBase::canvasController() const
{
    return d->controller;
}

void KoCanvasBase::clipToDocument(const KoShape *, QPointF &) const
{
}

KoSnapGuide * KoCanvasBase::snapGuide() const
{
    return 0; //AFA d->snapGuide;
}

KoGuidesData * KoCanvasBase::guidesData()
{
    return 0;
}

QWidget *KoCanvasBase::createSnapGuideConfigWidget() const
{
    return nullptr; //AFA new SnapGuideConfigWidget(d->snapGuide);
}
