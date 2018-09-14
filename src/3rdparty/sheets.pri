# Copyright (C) 2018 afarcat <kabak@sina.com>. All rights reserved.
#   Use of this source code is governed by a Apache license that can be
#   found in the LICENSE file.

INCLUDEPATH += $$PWD $$PWD/interfaces $$PWD/sheets
DEFINES += SHEETS_NO_PLUGINMODULES

#ENABLE_PRINT ENABLE_SHAPE

HEADERS += \
    $$PWD/sheets/commands/AbstractRegionCommand.h \
    #$$PWD/sheets/commands/ApplyFilterCommand.h \
    $$PWD/sheets/commands/AutoFillCommand.h \
    $$PWD/sheets/commands/AutoFilterCommand.h \
    $$PWD/sheets/commands/AutoFormatCommand.h \
    $$PWD/sheets/commands/BorderColorCommand.h \
    $$PWD/sheets/commands/CommentCommand.h \
    $$PWD/sheets/commands/ConditionCommand.h \
    $$PWD/sheets/commands/CopyCommand.h \
    $$PWD/sheets/commands/DataManipulators.h \
    $$PWD/sheets/commands/DeleteCommand.h \
    $$PWD/sheets/commands/IndentationCommand.h \
    $$PWD/sheets/commands/LinkCommand.h \
    $$PWD/sheets/commands/MergeCommand.h \
    $$PWD/sheets/commands/NamedAreaCommand.h \
    $$PWD/sheets/commands/PasteCommand.h \
    $$PWD/sheets/commands/PointStorageUndoCommand.h \
    $$PWD/sheets/commands/PrecisionCommand.h \
    $$PWD/sheets/commands/RectStorageUndoCommand.h \
    $$PWD/sheets/commands/RowColumnManipulators.h \
    $$PWD/sheets/commands/SheetCommands.h \
    $$PWD/sheets/commands/SortManipulator.h \
    $$PWD/sheets/commands/StyleCommand.h \
    $$PWD/sheets/commands/StyleStorageUndoCommand.h \
    $$PWD/sheets/commands/ValidityCommand.h \
    $$PWD/sheets/database/Database.h \
    $$PWD/sheets/database/DatabaseManager.h \
    $$PWD/sheets/database/DatabaseStorage.h \
    $$PWD/sheets/database/Filter.h \
    $$PWD/sheets/functions/BitOpsModule.h \
    $$PWD/sheets/functions/ConversionModule.h \
    $$PWD/sheets/functions/DatabaseModule.h \
    $$PWD/sheets/functions/DateTimeModule.h \
    $$PWD/sheets/functions/EngineeringModule.h \
    $$PWD/sheets/functions/FinancialModule.h \
    $$PWD/sheets/functions/helper.h \
    $$PWD/sheets/functions/InformationModule.h \
    $$PWD/sheets/functions/MathModule.h \
    $$PWD/sheets/functions/ReferenceModule.h \
    $$PWD/sheets/functions/StatisticalModule.h \
    $$PWD/sheets/functions/TextModule.h \
    $$PWD/sheets/functions/TrigonometryModule.h \
    $$PWD/sheets/odf/SheetsOdf.h \
    $$PWD/sheets/part/Canvas.h \
    $$PWD/sheets/part/CanvasBase.h \
    $$PWD/sheets/part/CanvasBase_p.h \
    $$PWD/sheets/part/CellTool.h \
    $$PWD/sheets/part/CellToolFactory.h \
    $$PWD/sheets/part/Digest.h \
    $$PWD/sheets/part/Doc.h \
    $$PWD/sheets/part/Headers.h \
    $$PWD/sheets/part/HeaderWidgets.h \
    $$PWD/sheets/part/ToolRegistry.h \
    $$PWD/sheets/part/View.h \
    $$PWD/sheets/ui/AbstractSelectionStrategy.h \
    $$PWD/sheets/ui/AutoFillStrategy.h \
    $$PWD/sheets/ui/CellEditor.h \
    $$PWD/sheets/ui/CellEditorBase.h \
    $$PWD/sheets/ui/CellToolBase.h \
    $$PWD/sheets/ui/CellToolBase_p.h \
    $$PWD/sheets/ui/CellView.h \
    $$PWD/sheets/ui/DragAndDropStrategy.h \
    $$PWD/sheets/ui/ExternalEditor.h \
    $$PWD/sheets/ui/FormulaEditorHighlighter.h \
    $$PWD/sheets/ui/HyperlinkStrategy.h \
    $$PWD/sheets/ui/LocationComboBox.h \
    $$PWD/sheets/ui/MergeStrategy.h \
    $$PWD/sheets/ui/PasteStrategy.h \
    $$PWD/sheets/ui/Selection.h \
    $$PWD/sheets/ui/SelectionStrategy.h \
    $$PWD/sheets/ui/SheetView.h \
    $$PWD/sheets/ApplicationSettings.h \
    $$PWD/sheets/CalculationSettings.h \
    $$PWD/sheets/calligra_sheets_limits.h \
    $$PWD/sheets/Cell.h \
    $$PWD/sheets/CellStorage.h \
    $$PWD/sheets/CellStorage_p.h \
    $$PWD/sheets/Cluster.h \
    $$PWD/sheets/Condition.h \
    $$PWD/sheets/ConditionsStorage.h \
    $$PWD/sheets/Currency.h \
    $$PWD/sheets/Damages.h \
    $$PWD/sheets/DependencyManager.h \
    $$PWD/sheets/DependencyManager_p.h \
    $$PWD/sheets/DocBase.h \
    $$PWD/sheets/DocBase_p.h \
    $$PWD/sheets/ElapsedTime_p.h \
    $$PWD/sheets/Format.h \
    $$PWD/sheets/Formula.h \
    $$PWD/sheets/FormulaStorage.h \
    $$PWD/sheets/Function.h \
    $$PWD/sheets/FunctionDescription.h \
    $$PWD/sheets/FunctionModule.h \
    $$PWD/sheets/FunctionModuleRegistry.h \
    $$PWD/sheets/FunctionRepository.h \
    $$PWD/sheets/Global.h \
    $$PWD/sheets/LoadingInfo.h \
    $$PWD/sheets/Map.h \
    #$$PWD/sheets/MapModel.h \
    $$PWD/sheets/NamedAreaManager.h \
    $$PWD/sheets/PointStorage.h \
    $$PWD/sheets/ProtectableObject.h \
    $$PWD/sheets/RecalcManager.h \
    $$PWD/sheets/RectStorage.h \
    $$PWD/sheets/Region.h \
    #$$PWD/sheets/RegionModel.h \
    $$PWD/sheets/RowColumnFormat.h \
    $$PWD/sheets/RowFormatStorage.h \
    $$PWD/sheets/RTree.h \
    $$PWD/sheets/Sheet.h \
    $$PWD/sheets/SheetAccessModel.h \
    $$PWD/sheets/SheetModel.h \
    $$PWD/sheets/sheets_common_export.h \
    $$PWD/sheets/sheets_odf_export.h \
    $$PWD/sheets/SheetsDebug.h \
    $$PWD/sheets/Style.h \
    $$PWD/sheets/StyleManager.h \
    $$PWD/sheets/StyleStorage.h \
    $$PWD/sheets/Util.h \
    $$PWD/sheets/Validity.h \
    $$PWD/sheets/ValidityStorage.h \
    $$PWD/sheets/Value.h \
    $$PWD/sheets/ValueCalc.h \
    $$PWD/sheets/ValueConverter.h \
    $$PWD/sheets/ValueFormatter.h \
    $$PWD/sheets/ValueParser.h \
    $$PWD/sheets/ValueStorage.h

SOURCES += \
    $$PWD/sheets/commands/AbstractRegionCommand.cpp \
    $$PWD/sheets/commands/ApplyFilterCommand.cpp \
    $$PWD/sheets/commands/AutoFillCommand.cpp \
    $$PWD/sheets/commands/AutoFilterCommand.cpp \
    $$PWD/sheets/commands/AutoFormatCommand.cpp \
    $$PWD/sheets/commands/BorderColorCommand.cpp \
    $$PWD/sheets/commands/CommentCommand.cpp \
    $$PWD/sheets/commands/ConditionCommand.cpp \
    $$PWD/sheets/commands/CopyCommand.cpp \
    $$PWD/sheets/commands/DataManipulators.cpp \
    $$PWD/sheets/commands/DeleteCommand.cpp \
    $$PWD/sheets/commands/IndentationCommand.cpp \
    $$PWD/sheets/commands/LinkCommand.cpp \
    $$PWD/sheets/commands/MergeCommand.cpp \
    $$PWD/sheets/commands/NamedAreaCommand.cpp \
    $$PWD/sheets/commands/PasteCommand.cpp \
    $$PWD/sheets/commands/PrecisionCommand.cpp \
    $$PWD/sheets/commands/RowColumnManipulators.cpp \
    $$PWD/sheets/commands/SheetCommands.cpp \
    $$PWD/sheets/commands/SortManipulator.cpp \
    $$PWD/sheets/commands/StyleCommand.cpp \
    $$PWD/sheets/commands/ValidityCommand.cpp \
    $$PWD/sheets/database/Database.cpp \
    $$PWD/sheets/database/DatabaseManager.cpp \
    $$PWD/sheets/database/DatabaseStorage.cpp \
    $$PWD/sheets/database/Filter.cpp \
    $$PWD/sheets/functions/bitops.cpp \
    $$PWD/sheets/functions/conversion.cpp \
    $$PWD/sheets/functions/databaseFunc.cpp \
    $$PWD/sheets/functions/datetime.cpp \
    $$PWD/sheets/functions/engineering.cpp \
    $$PWD/sheets/functions/financial.cpp \
    $$PWD/sheets/functions/helper.cpp \
    $$PWD/sheets/functions/information.cpp \
    $$PWD/sheets/functions/logic.cpp \
    $$PWD/sheets/functions/math.cpp \
    $$PWD/sheets/functions/reference.cpp \
    $$PWD/sheets/functions/statistical.cpp \
    $$PWD/sheets/functions/text.cpp \
    $$PWD/sheets/functions/trig.cpp \
    #$$PWD/sheets/odf/SheetsOdfDoc.cpp \
    $$PWD/sheets/odf/SheetsOdfRegion.cpp \
    $$PWD/sheets/part/Canvas.cpp \
    $$PWD/sheets/part/CanvasBase.cpp \
    $$PWD/sheets/part/CellTool.cpp \
    $$PWD/sheets/part/CellToolFactory.cpp \
    $$PWD/sheets/part/Digest.cpp \
    $$PWD/sheets/part/Doc.cpp \
    $$PWD/sheets/part/Headers.cpp \
    $$PWD/sheets/part/HeaderWidgets.cpp \
    $$PWD/sheets/part/ToolRegistry.cpp \
    $$PWD/sheets/part/View.cpp \
    $$PWD/sheets/ui/AbstractSelectionStrategy.cpp \
    $$PWD/sheets/ui/AutoFillStrategy.cpp \
    $$PWD/sheets/ui/CellEditor.cpp \
    $$PWD/sheets/ui/CellEditorBase.cpp \
    $$PWD/sheets/ui/CellToolBase.cpp \
    $$PWD/sheets/ui/CellToolBase_p.cpp \
    $$PWD/sheets/ui/CellView.cpp \
    $$PWD/sheets/ui/DragAndDropStrategy.cpp \
    $$PWD/sheets/ui/ExternalEditor.cpp \
    $$PWD/sheets/ui/FormulaEditorHighlighter.cpp \
    $$PWD/sheets/ui/HyperlinkStrategy.cpp \
    $$PWD/sheets/ui/LocationComboBox.cpp \
    $$PWD/sheets/ui/MergeStrategy.cpp \
    $$PWD/sheets/ui/PasteStrategy.cpp \
    $$PWD/sheets/ui/Selection.cpp \
    $$PWD/sheets/ui/SelectionStrategy.cpp \
    $$PWD/sheets/ui/SheetView.cpp \
    $$PWD/sheets/ApplicationSettings.cpp \
    $$PWD/sheets/CalculationSettings.cpp \
    $$PWD/sheets/Cell.cpp \
    $$PWD/sheets/CellStorage.cpp \
    $$PWD/sheets/Cluster.cpp \
    $$PWD/sheets/Condition.cpp \
    $$PWD/sheets/ConditionsStorage.cpp \
    $$PWD/sheets/Currency.cpp \
    $$PWD/sheets/Damages.cpp \
    $$PWD/sheets/DependencyManager.cpp \
    $$PWD/sheets/DocBase.cpp \
    $$PWD/sheets/Format.cpp \
    $$PWD/sheets/Formula.cpp \
    $$PWD/sheets/Function.cpp \
    $$PWD/sheets/FunctionDescription.cpp \
    $$PWD/sheets/FunctionModule.cpp \
    $$PWD/sheets/FunctionModuleRegistry.cpp \
    $$PWD/sheets/FunctionRepository.cpp \
    $$PWD/sheets/Localization.cpp \
    $$PWD/sheets/Map.cpp \
    #$$PWD/sheets/MapModel.cpp \
    $$PWD/sheets/NamedAreaManager.cpp \
    $$PWD/sheets/Number.cpp \
    $$PWD/sheets/ProtectableObject.cpp \
    $$PWD/sheets/RecalcManager.cpp \
    $$PWD/sheets/RectStorage.cpp \
    $$PWD/sheets/Region.cpp \
    #$$PWD/sheets/RegionModel.cpp \
    $$PWD/sheets/RowColumnFormat.cpp \
    $$PWD/sheets/RowFormatStorage.cpp \
    $$PWD/sheets/RowRepeatStorage.cpp \
    $$PWD/sheets/Sheet.cpp \
    $$PWD/sheets/SheetAccessModel.cpp \
    $$PWD/sheets/SheetModel.cpp \
    $$PWD/sheets/SheetsDebug.cpp \
    $$PWD/sheets/Style.cpp \
    $$PWD/sheets/StyleManager.cpp \
    $$PWD/sheets/StyleStorage.cpp \
    $$PWD/sheets/Util.cpp \
    $$PWD/sheets/Validity.cpp \
    $$PWD/sheets/ValidityStorage.cpp \
    $$PWD/sheets/Value.cpp \
    $$PWD/sheets/ValueCalc.cpp \
    $$PWD/sheets/ValueConverter.cpp \
    $$PWD/sheets/ValueFormatter.cpp \
    $$PWD/sheets/ValueParser.cpp

ENABLE_WIDGETS {
HEADERS += \
    $$PWD/sheets/dialogs/FormulaDialog.h \
    $$PWD/sheets/dialogs/LayoutDialog.h \
    $$PWD/sheets/part/TabBar.h \
    $$PWD/sheets/ui/CellEditorWidget.h \
    $$PWD/sheets/ui/CellToolBar.h \
    $$PWD/sheets/ui/FunctionCompletion.h

SOURCES += \
    $$PWD/sheets/dialogs/FormulaDialog.cpp \
    $$PWD/sheets/dialogs/LayoutDialog.cpp \
    $$PWD/sheets/part/TabBar.cpp \
    $$PWD/sheets/ui/CellEditorWidget.cpp \
    $$PWD/sheets/ui/CellToolBar.cpp \
    $$PWD/sheets/ui/FunctionCompletion.cpp
}

ENABLE_BINDING {
HEADERS += \
    #$$PWD/sheets/Binding.h \
    #$$PWD/sheets/BindingManager.h \
    #$$PWD/sheets/BindingModel.h \
    #$$PWD/sheets/BindingStorage.h

SOURCES += \
    #$$PWD/sheets/Binding.cpp \
    #$$PWD/sheets/BindingManager.cpp \
    #$$PWD/sheets/BindingModel.cpp \
    #$$PWD/sheets/BindingStorage.cpp \
}

ENABLE_PRINT {
HEADERS += \
    #$$PWD/sheets/HeaderFooter.h \
    #$$PWD/sheets/PageManager.h \
    #$$PWD/sheets/PrintSettings.h \
    #$$PWD/sheets/SheetPrint.h \
    #$$PWD/sheets/SheetPrint_p.h

SOURCES += \
    #$$PWD/sheets/HeaderFooter.cpp \
    #$$PWD/sheets/PageManager.cpp \
    #$$PWD/sheets/PrintSettings.cpp \
    #$$PWD/sheets/SheetPrint.cpp \
    #$$PWD/sheets/SheetPrint_p.cpp
}

RESOURCES += \
    $$PWD/sheets.qrc

FORMS += \
    $$PWD/sheets/dialogs/ProtectionWidget.ui \
    $$PWD/sheets/dialogs/PositionWidget.ui \
    $$PWD/sheets/dialogs/FontWidget.ui
