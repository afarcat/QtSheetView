/* Copyright (C) 2018 afarcat <kabak@sina.com>. All rights reserved.
   Use of this source code is governed by a Apache license that can be
   found in the LICENSE file.
*/

#include "sheetqml_ui.h"

//#include "qhtmlpart.h"
//#include "qhtmlview.h"

#ifndef QT_WIDGETS_LIB

// -----------------------------------------------------------------------------
QQmlWidget::QQmlWidget(QWidget *parent, QString className)
    : QWidget(parent)
{
//    QHTMLView *htmlView = qobject_cast<QHTMLView *>(parent);
//    if (htmlView && htmlView->part()) {
//        QVariant returnArg;
//        if (QMetaObject::invokeMethod(htmlView->part(), "createQmlWidget", Qt::DirectConnection,
//                                      Q_RETURN_ARG(QVariant, returnArg),
//                                      Q_ARG(QVariant, QVariant::fromValue(parent)),
//                                      Q_ARG(QVariant, className))){
//            m_qmlWidget = returnArg.value<QWidget *>();
//        }
//    }

    QObject::connect(qApp, SIGNAL(aboutToQuit()), this, SLOT(slotAppQuit()));
}

QQmlWidget::~QQmlWidget()
{
//    if (!m_qmlWidget.isNull()) {
//        QHTMLView *htmlView = qobject_cast<QHTMLView *>(parent());
//        if (htmlView && htmlView->part()) {
//            QMetaObject::invokeMethod(htmlView->part(), "destroyQmlWidget", Qt::DirectConnection,
//                                      Q_ARG(QVariant, QVariant::fromValue(m_qmlWidget.data())));
//            m_qmlWidget = nullptr;
//        }
//    }
}

QWidget *QQmlWidget::qmlWidget() const
{
    return m_qmlWidget;
}

void QQmlWidget::setQmlWidget(QWidget *qmlWidget)
{
    m_qmlWidget = qmlWidget;
}

void QQmlWidget::slotAppQuit()
{
    //set m_qmlWidget to nullptr to prevent call ~QQmlWidget()
    m_qmlWidget = nullptr;
}

// -----------------------------------------------------------------------------
QAction::QAction(QObject *parent)
{

}

QAction::QAction(const QString &text, QObject *parent)
{

}

QAction::QAction(const QString &icon, const QString &text, QObject *parent)
{

}

void QAction::setIcon(QString icon)
{

}

void QAction::setToolTip(QString str)
{

}

void QAction::setIconText(QString str)
{

}

void QAction::setActionGroup(QActionGroup *actionGroup)
{

}

void QAction::setShortcuts(const QList<QKeySequence> &shortcuts)
{

}

// -----------------------------------------------------------------------------
QActionGroup::QActionGroup(QObject *parent)
{

}

// -----------------------------------------------------------------------------
QComboBox::QComboBox(QWidget *parent)
    : QQmlWidget(parent, "QComboBox")
{

}

// -----------------------------------------------------------------------------
QTextEdit::QTextEdit(QWidget *parent)
    : QQmlWidget(parent, "QTextEdit")
{

}

void QTextEdit::cut()
{

}

void QTextEdit::copy()
{

}

void QTextEdit::paste()
{

}

void QTextEdit::clear()
{

}

QRectF QTextEdit::rect() const
{

}

void QTextEdit::setGeometry(int x, int y, int w, int h)
{

}

QFont QTextEdit::font() const
{

}

void QTextEdit::setFont(QFont font)
{

}

QTextCursor QTextEdit::textCursor() const
{

}

void QTextEdit::setTextCursor(QTextCursor cursor)
{

}

void QTextEdit::setPlainText(QString str)
{

}

QString QTextEdit::toPlainText() const
{

}

QPalette QTextEdit::palette() const
{

}

void QTextEdit::setPalette(const QPalette &palette)
{

}

void QTextEdit::setReadOnly(bool v)
{
    if (m_qmlWidget) {
        m_qmlWidget->setProperty("readOnly", v);
    }
}

void QTextEdit::setWrapMode(QQuickTextEdit::WrapMode w)
{
    if (m_qmlWidget) {
        m_qmlWidget->setProperty("wrapMode", w);
    }
}

void QTextEdit::setTextFormat(QQuickTextEdit::TextFormat format)
{
    if (m_qmlWidget) {
        m_qmlWidget->setProperty("textFormat", format);
    }
}

#endif
