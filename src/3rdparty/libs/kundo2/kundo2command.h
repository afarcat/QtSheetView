//AFA #include <kundo2stack.h>

#ifdef QT_WIDGETS_LIB
#include <QUndoStack>
#else
#include "kundostack.h"
#endif

#define KUndo2Command       QUndoCommand
#define KUndo2Stack         QUndoStack
#define KUndo2MagicString   QString

#define kundo2_i18n(x)      QObject::tr(x)
#define kundo2_noi18n(x)    (x)
