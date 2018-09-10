#include <QtCore/qglobal.h>

#if defined(KSHEET_LIBRARY)
#  define KOSTORE_EXPORT Q_DECL_EXPORT
#else
#  define KOSTORE_EXPORT Q_DECL_IMPORT
#endif
