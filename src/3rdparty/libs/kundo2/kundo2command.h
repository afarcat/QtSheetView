//AFA #include <kundo2stack.h>

#include <QUndoStack>
#define KUndo2Command       QUndoCommand
#define KUndo2Stack         QUndoStack
#define KUndo2MagicString   QString

#define kundo2_i18n(x)      QObject::tr(x)
#define kundo2_noi18n(x)    (x)
