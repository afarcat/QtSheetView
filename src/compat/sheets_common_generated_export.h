#include <QtCore/qglobal.h>

#if defined(KSHEET_LIBRARY)
#  define CALLIGRA_SHEETS_COMMON_EXPORT Q_DECL_EXPORT
#else
#  define CALLIGRA_SHEETS_COMMON_EXPORT Q_DECL_IMPORT
#endif

#include <QIcon>

#define RESOURCES_IMAGES    QString(":/resources/images/")
#define koIconName(name)    QString(QFile::exists(RESOURCES_IMAGES + name + ".svg") ? RESOURCES_IMAGES + name + ".svg" : "")

#ifdef QT_WIDGETS_LIB
#define koIcon(name)        QIcon(QFile::exists(RESOURCES_IMAGES + name + ".svg") ? RESOURCES_IMAGES + name + ".svg" : "")
#else
#define koIcon(name)        QString(QFile::exists(RESOURCES_IMAGES + name + ".svg") ? RESOURCES_IMAGES + name + ".svg" : "")

#include <sheetqml_ui.h>
#endif
