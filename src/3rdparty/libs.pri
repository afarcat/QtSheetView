# Copyright (C) 2018 afarcat <kabak@sina.com>. All rights reserved.
#   Use of this source code is governed by a Apache license that can be
#   found in the LICENSE file.

INCLUDEPATH += $$PWD/libs/flake $$PWD/libs/kundo2 $$PWD/libs/main $$PWD/libs/odf $$PWD/libs/store $$PWD/libs/widgets
DEFINES += KOXML_USE_QDOM

HEADERS += \
    $$PWD/libs/flake/KoCanvasBase.h \
    $$PWD/libs/flake/KoCanvasWidget.h \
    $$PWD/libs/flake/KoCanvasWidget_p.h \
    $$PWD/libs/flake/KoCanvasWidgetViewport_p.h \
    $$PWD/libs/flake/KoDataCenterBase.h \
    $$PWD/libs/flake/KoInputDevice.h \
    $$PWD/libs/flake/KoPointerEvent.h \
    $$PWD/libs/flake/KoPostscriptPaintDevice.h \
    $$PWD/libs/flake/KoRTree.h \
    $$PWD/libs/flake/KoToolBase.h \
    $$PWD/libs/flake/KoToolBase_p.h \
    $$PWD/libs/flake/KoToolFactoryBase.h \
    $$PWD/libs/flake/KoToolManager.h \
    $$PWD/libs/flake/KoToolManager_p.h \
    $$PWD/libs/flake/KoToolProxy.h \
    $$PWD/libs/flake/KoToolProxy_p.h \
    $$PWD/libs/flake/KoToolRegistry.h \
    $$PWD/libs/flake/KoToolSelection.h \
    $$PWD/libs/flake/KoViewConverter.h \
    $$PWD/libs/flake/tools/KoInteractionStrategy.h \
    $$PWD/libs/flake/tools/KoInteractionStrategy_p.h \
    $$PWD/libs/flake/tools/KoInteractionTool.h \
    $$PWD/libs/flake/tools/KoInteractionTool_p.h \
    $$PWD/libs/flake/tools/KoPanTool.h \
    $$PWD/libs/flake/tools/KoPanToolFactory.h \
    $$PWD/libs/flake/tools/KoShapeRubberSelectStrategy.h \
    $$PWD/libs/flake/tools/KoShapeRubberSelectStrategy_p.h \
    $$PWD/libs/flake/tools/KoZoomStrategy.h \
    $$PWD/libs/flake/tools/KoZoomTool.h \
    $$PWD/libs/flake/tools/KoZoomToolFactory.h \
    $$PWD/libs/main/KoDocument.h \
    $$PWD/libs/main/MainDebug.h \
    $$PWD/libs/odf/KoDocumentBase.h \
    $$PWD/libs/odf/KoUnit.h \
    $$PWD/libs/store/KoXmlNS.h \
    $$PWD/libs/store/KoXmlReader.h \
    $$PWD/libs/store/KoXmlWriter.h \
    $$PWD/libs/widgets/KoDpi.h \
    $$PWD/libs/widgets/KoZoomHandler.h \
    $$PWD/libs/widgets/KoZoomMode.h

SOURCES += \
    $$PWD/libs/flake/KoCanvasBase.cpp \
    $$PWD/libs/flake/KoCanvasWidget.cpp \
    $$PWD/libs/flake/KoCanvasWidgetViewport_p.cpp \
    $$PWD/libs/flake/KoDataCenterBase.cpp \
    $$PWD/libs/flake/KoInputDevice.cpp \
    $$PWD/libs/flake/KoPointerEvent.cpp \
    $$PWD/libs/flake/KoPostscriptPaintDevice.cpp \
    $$PWD/libs/flake/KoToolBase.cpp \
    $$PWD/libs/flake/KoToolFactoryBase.cpp \
    $$PWD/libs/flake/KoToolManager.cpp \
    $$PWD/libs/flake/KoToolManager_p.cpp \
    $$PWD/libs/flake/KoToolProxy.cpp \
    $$PWD/libs/flake/KoToolRegistry.cpp \
    $$PWD/libs/flake/KoToolSelection.cpp \
    $$PWD/libs/flake/KoViewConverter.cpp \
    $$PWD/libs/flake/tools/KoInteractionStrategy.cpp \
    $$PWD/libs/flake/tools/KoInteractionTool.cpp \
    $$PWD/libs/flake/tools/KoPanTool.cpp \
    $$PWD/libs/flake/tools/KoPanToolFactory.cpp \
    $$PWD/libs/flake/tools/KoShapeRubberSelectStrategy.cpp \
    $$PWD/libs/flake/tools/KoZoomStrategy.cpp \
    $$PWD/libs/flake/tools/KoZoomTool.cpp \
    $$PWD/libs/flake/tools/KoZoomToolFactory.cpp \
    $$PWD/libs/main/KoDocument.cpp \
    $$PWD/libs/odf/KoDocumentBase.cpp \
    $$PWD/libs/odf/KoUnit.cpp \
    $$PWD/libs/store/KoXmlNS.cpp \
    $$PWD/libs/store/KoXmlReader.cpp \
    $$PWD/libs/store/KoXmlWriter.cpp \
    $$PWD/libs/widgets/KoDpi.cpp \
    $$PWD/libs/widgets/KoZoomHandler.cpp \
    $$PWD/libs/widgets/KoZoomMode.cpp

ENABLE_WIDGETS {
}
else {
HEADERS += \
    $$PWD/libs/kundo2/kundostack.h \
    $$PWD/libs/kundo2/kundostack_p.h

SOURCES += \
    $$PWD/libs/kundo2/kundostack.cpp
}
