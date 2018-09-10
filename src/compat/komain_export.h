#include <QtCore/qglobal.h>

#if defined(KSHEET_LIBRARY)
#  define KOMAIN_EXPORT Q_DECL_EXPORT
#else
#  define KOMAIN_EXPORT Q_DECL_IMPORT
#endif
