#include <QtCore/qglobal.h>

#if defined(KSHEET_LIBRARY)
#  define CALLIGRA_SHEETS_ODF_EXPORT Q_DECL_EXPORT
#else
#  define CALLIGRA_SHEETS_ODF_EXPORT Q_DECL_IMPORT
#endif

#define i18n        QObject::tr
#define i18nc(x, y) QObject::tr(x)
#define ki18n       QObject::tr
#define I18N_NOOP   QT_TR_NOOP

#define SHEETS_FUNCTIONS ":/sheets/functions/"
