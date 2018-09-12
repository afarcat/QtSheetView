#include <QtCore/qglobal.h>

#if defined(KSHEET_LIBRARY)
#  define FLAKE_EXPORT Q_DECL_EXPORT
#else
#  define FLAKE_EXPORT Q_DECL_IMPORT
#endif

#define i18n QObject::tr

#ifndef QT_WIDGETS_LIB
#include <sheetqml_ui.h>
#endif
