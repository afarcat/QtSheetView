/* Copyright (C) 2018 afarcat <kabak@sina.com>. All rights reserved.
   Use of this source code is governed by a Apache license that can be
   found in the LICENSE file.
*/

#include "sheetqml_ui.h"

#include <part/View.h>
#include <KoCanvasWidget.h>

#ifndef QT_WIDGETS_LIB

using namespace Calligra::Sheets;

// -----------------------------------------------------------------------------
QQmlWidget::QQmlWidget(QWidget *parent, QString className)
    : QWidget(parent)
{
    QWidget *item = parent;
    View *view = nullptr;
    while (item) {
        view = qobject_cast<View *>(item);
        if (view) {
            break;
        }
        item = item->parentItem();
    }

    if (view) {
        QVariant returnArg;
        if (QMetaObject::invokeMethod(view, "createQmlWidget", Qt::DirectConnection,
                                      Q_RETURN_ARG(QVariant, returnArg),
                                      Q_ARG(QVariant, QVariant::fromValue(view->canvasController())),
                                      Q_ARG(QVariant, className))){
            m_qmlWidget = returnArg.value<QWidget *>();
        }
    }

    QObject::connect(qApp, SIGNAL(aboutToQuit()), this, SLOT(slotAppQuit()));
}

QQmlWidget::~QQmlWidget()
{
    clearQmlWidget();
}

void QQmlWidget::clearQmlWidget()
{
    if (!m_qmlWidget.isNull()) {
        QWidget *item = parentItem();
        View *view = nullptr;
        while (item) {
            view = qobject_cast<View *>(item);
            if (view) {
                break;
            }
            item = item->parentItem();
        }

        if (view) {
            QMetaObject::invokeMethod(view, "destroyQmlWidget", Qt::DirectConnection,
                                      Q_ARG(QVariant, QVariant::fromValue(m_qmlWidget.data())));
            m_qmlWidget = nullptr;
        }
    }
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
    : QQuickAction(parent)
{

}

QAction::QAction(const QString &text, QObject *parent)
    : QQuickAction(parent)
{
    setText(text);
}

QAction::QAction(const QString &icon, const QString &text, QObject *parent)
    : QQuickAction(parent)
{
    setIcon(icon);
    setText(text);
}

void QAction::setIcon(QString icon)
{
    QQuickIcon quickIcon;
    quickIcon.setSource(icon);
    QQuickAction::setIcon(quickIcon);
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
    : QQuickActionGroup(parent)
{

}

// -----------------------------------------------------------------------------
QComboBox::QComboBox(QWidget *parent)
    : QQmlWidget(parent, "QComboBox")
{
    m_qmlComboBox = qobject_cast<QQuickComboBox *>(m_qmlWidget.data());
    if (m_qmlComboBox) {
        connect(m_qmlComboBox.data(), SIGNAL(activated(int)), this, SIGNAL(activated(int)));
    }
}

void QComboBox::attachQmlObject(QQuickItem *qmlObject)
{
    clearQmlWidget();

    m_qmlComboBox = qobject_cast<QQuickComboBox *>(qmlObject);
    if (m_qmlComboBox) {
        connect(m_qmlComboBox.data(), SIGNAL(activated(int)), this, SIGNAL(activated(int)));
    }
}

void QComboBox::setEditable(bool editable)
{
    if (m_qmlComboBox) {
        m_qmlComboBox->setEditable(editable);
    }
}

void QComboBox::clear()
{
    m_qmlComboBoxModel.clear();
    if (m_qmlComboBox) {
        m_qmlComboBox->setProperty("model", QVariant::fromValue(m_qmlComboBoxModel));
    }
}

int QComboBox::count()
{
    if (m_qmlComboBox) {
        return m_qmlComboBox->count();
    }
    return 0;
}

void QComboBox::setCurrentIndex(int index)
{
    if (m_qmlComboBox) {
        m_qmlComboBox->setCurrentIndex(index);
    }
}

void QComboBox::insertItem(int index, const QString &text)
{
    m_qmlComboBoxModel.insert(index, text);
    if (m_qmlComboBox) {
        m_qmlComboBox->setProperty("model", QVariant::fromValue(m_qmlComboBoxModel));
    }
}

void QComboBox::removeItem(int index)
{
    m_qmlComboBoxModel.removeAt(index);
    if (m_qmlComboBox) {
        m_qmlComboBox->setProperty("model", QVariant::fromValue(m_qmlComboBoxModel));
    }
}

void QComboBox::setItemText(int index, const QString &text)
{
    if (0 <= index && index < m_qmlComboBoxModel.size()) {
        m_qmlComboBoxModel.replace(index, text);
        if (m_qmlComboBox) {
            m_qmlComboBox->setProperty("model", QVariant::fromValue(m_qmlComboBoxModel));
        }
    }
}

QString QComboBox::itemText(int index) const
{
    if (0 <= index && index < m_qmlComboBoxModel.size()) {
        return m_qmlComboBoxModel[index];
    }
}

QString QComboBox::editText() const
{
    if (m_qmlComboBox) {
        return m_qmlComboBox->editText();
    }
}

void QComboBox::setEditText(const QString &text)
{
    if (m_qmlComboBox) {
        m_qmlComboBox->setEditText(text);
    }
}

// -----------------------------------------------------------------------------
QTextEdit::QTextEdit(QWidget *parent)
    : QQmlWidget(parent, "QTextEdit")
{
    m_qmlTextArea = qobject_cast<QQuickTextArea *>(m_qmlWidget.data());
    if (m_qmlTextArea) {
        connect(m_qmlTextArea.data(), SIGNAL(textChanged()), this, SIGNAL(textChanged()));
        connect(m_qmlTextArea.data(), SIGNAL(cursorPositionChanged()), this, SIGNAL(cursorPositionChanged()));
        m_qmlTextArea->installEventFilter(this);
    }
}

void QTextEdit::attachQmlObject(QQuickItem *qmlObject)
{
    clearQmlWidget();

    m_qmlTextArea = qobject_cast<QQuickTextArea *>(qmlObject);
    if (m_qmlTextArea) {
        connect(m_qmlTextArea.data(), SIGNAL(textChanged()), this, SIGNAL(textChanged()));
        connect(m_qmlTextArea.data(), SIGNAL(cursorPositionChanged()), this, SIGNAL(cursorPositionChanged()));
        m_qmlTextArea->installEventFilter(this);
    }
}

bool QTextEdit::eventFilter(QObject *obj, QEvent *event)
{
    if (m_qmlTextArea && m_qmlTextArea == obj) {
        if (event->type() == QEvent::KeyPress) {
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
            keyPressEvent(keyEvent);
            keyEvent->accept();
        }
        else if (event->type() == QEvent::FocusIn) {
            QFocusEvent *focusEvent = static_cast<QFocusEvent *>(event);
            focusInEvent(focusEvent);
        }
        else if (event->type() == QEvent::FocusOut) {
            QFocusEvent *focusEvent = static_cast<QFocusEvent *>(event);
            focusOutEvent(focusEvent);
        }
    }

    // standard event processing
    return QObject::eventFilter(obj, event);
}

bool QTextEdit::hasFocus()
{
    if (m_qmlTextArea) {
        return m_qmlTextArea->hasFocus();
    }
    return false;
}

void QTextEdit::cut()
{
    if (m_qmlTextArea) {
        m_qmlTextArea->cut();
    }
}

void QTextEdit::copy()
{
    if (m_qmlTextArea) {
        m_qmlTextArea->copy();
    }
}

void QTextEdit::paste()
{
    if (m_qmlTextArea) {
        m_qmlTextArea->paste();
    }
}

void QTextEdit::clear()
{
    if (m_qmlTextArea) {
        m_qmlTextArea->clear();
    }
}

QRectF QTextEdit::rect() const
{
    if (m_qmlTextArea) {
        return QRectF(m_qmlTextArea->position(), m_qmlTextArea->size());
    }
    return QRectF(position(), size());
}

void QTextEdit::setGeometry(int x, int y, int w, int h)
{
    setPosition(QPointF(x, y));
    setSize(QSizeF(w, h));

    if (m_qmlTextArea) {
        m_qmlTextArea->setPosition(QPointF(x, y));
        m_qmlTextArea->setSize(QSizeF(w, h));
    }
}

QFont QTextEdit::font() const
{
    if (m_qmlTextArea) {
        return m_qmlTextArea->font();
    }
    return QFont();
}

void QTextEdit::setFont(QFont font)
{
    if (m_qmlTextArea) {
        return m_qmlTextArea->setFont(font);
    }
}

QTextCursor QTextEdit::textCursor() const
{
    QTextCursor textCursor;
    if (m_qmlTextArea) {
        textCursor.setPosition(m_qmlTextArea->cursorPosition());
    }
    return textCursor;
}

void QTextEdit::setTextCursor(QTextCursor cursor)
{
    if (m_qmlTextArea) {
        return m_qmlTextArea->setCursorPosition(cursor.position());
    }
}

void QTextEdit::setPlainText(QString str)
{
    if (m_qmlTextArea) {
        m_qmlTextArea->setText(str);
    }
}

QString QTextEdit::toPlainText() const
{
    if (m_qmlTextArea) {
        return m_qmlTextArea->text();
    }
    return QString();
}

QPalette QTextEdit::palette() const
{
    if (m_qmlTextArea) {
        return m_qmlTextArea->palette();
    }
    return QPalette();
}

void QTextEdit::setPalette(const QPalette &palette)
{
    if (m_qmlTextArea) {
        m_qmlTextArea->setPalette(palette);
    }
}

void QTextEdit::setReadOnly(bool v)
{
    if (m_qmlTextArea) {
        m_qmlTextArea->setReadOnly(v);
    }
}

void QTextEdit::setWrapMode(QQuickTextEdit::WrapMode w)
{
    if (m_qmlTextArea) {
        m_qmlTextArea->setWrapMode(w);
    }
}

void QTextEdit::setTextFormat(QQuickTextEdit::TextFormat format)
{
    if (m_qmlTextArea) {
        m_qmlTextArea->setTextFormat(format);
    }
}

#endif
