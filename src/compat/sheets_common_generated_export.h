#include <QtCore/qglobal.h>

#if defined(KSHEET_LIBRARY)
#  define CALLIGRA_SHEETS_COMMON_EXPORT Q_DECL_EXPORT
#else
#  define CALLIGRA_SHEETS_COMMON_EXPORT Q_DECL_IMPORT
#endif

#define RESOURCES_IMAGES    QString(":/resources/images/")
#define koIcon(name)        QIcon(QFile::exists(RESOURCES_IMAGES + name + ".svg") ? RESOURCES_IMAGES + name + ".svg" : "")
#define koIconName(name)    QString(QFile::exists(RESOURCES_IMAGES + name + ".svg") ? RESOURCES_IMAGES + name + ".svg" : "")
