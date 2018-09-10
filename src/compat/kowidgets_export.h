#include <QtCore/qglobal.h>

#if defined(KSHEET_LIBRARY)
#  define KOWIDGETS_EXPORT Q_DECL_EXPORT
#else
#  define KOWIDGETS_EXPORT Q_DECL_IMPORT
#endif

#define i18n        QObject::tr
#define I18N_NOOP   QT_TR_NOOP
