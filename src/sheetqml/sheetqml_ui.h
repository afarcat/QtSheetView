/* Copyright (C) 2018 afarcat <kabak@sina.com>. All rights reserved.
   Use of this source code is governed by a Apache license that can be
   found in the LICENSE file.
*/

#ifndef __sheetqmlui_h
#define __sheetqmlui_h

#ifndef QT_WIDGETS_LIB

#include <QPointer>
#include <QCursor>
#include <QTextCursor>
#include <QQuickItem>
#include <QQuickPaintedItem>

#define QWidget QQuickItem
#define QLabel QQuickItem
#define QMenu QQuickItem
#define QToolBar QQuickItem
#define QRubberBand QQuickItem
#define QAbstractScrollArea QQuickPaintedItem

#include <QtQuickTemplates2/private/qquickaction_p.h>
#include <QtQuickTemplates2/private/qquickactiongroup_p.h>
#include <QtQuickTemplates2/private/qquickcombobox_p.h>
#include <QtQuickTemplates2/private/qquickcheckbox_p.h>
#include <QtQuickTemplates2/private/qquickradiobutton_p.h>
#include <QtQuickTemplates2/private/qquickbutton_p.h>
#include <QtQuickTemplates2/private/qquicktextfield_p.h>
#include <QtQuickTemplates2/private/qquicktextarea_p.h>
#include <QtQuickTemplates2/private/qquickscrollbar_p.h>
#include <QtQuickTemplates2/private/qquickscrollview_p.h>
#include <QtQuick/private/qquicklistview_p.h>

//AFA: QtQuickTemplates2 NO UI, so use it in qml file
//#define QCheckBox QQuickCheckBox
//#define QComboBox QQuickComboBox
//#define QRadioButton QQuickRadioButton
//#define QPushButton QQuickButton
//#define QLineEdit QQuickTextField
//#define QTextEdit QQuickTextArea
//#define QListWidget QQuickListView
#define QScrollBar QQuickScrollBar

// -----------------------------------------------------------------------------
class QQmlWidget : public QWidget
{
    Q_OBJECT
public:
    QQmlWidget(QWidget *parent = 0, QString className = "");
    ~QQmlWidget();

public:
    void clearQmlWidget();
    QWidget *qmlWidget() const;
    void setQmlWidget(QWidget *qmlWidget);

protected slots:
    void slotAppQuit();

protected:
    QPointer<QWidget> m_qmlWidget;
};

// -----------------------------------------------------------------------------
class QActionGroup;
class QAction : public QQuickAction
{
    Q_OBJECT
public:
    QAction(QObject *parent = nullptr);
    QAction(const QString &text, QObject *parent = nullptr);
    QAction(const QString &icon, const QString &text, QObject *parent = nullptr);

public:
    void setIcon(QString icon);
    void setToolTip(QString str);
    void setIconText(QString str);
    void setActionGroup(QActionGroup *actionGroup);
    void setShortcuts(const QList<QKeySequence> &shortcuts);

Q_SIGNALS:
    void triggered(bool);
};

// -----------------------------------------------------------------------------
class QActionGroup : public QQuickActionGroup
{
    Q_OBJECT
public:
    explicit QActionGroup(QObject *parent = nullptr);
};

// -----------------------------------------------------------------------------
class QComboBox : public QQmlWidget
{
    Q_OBJECT
public:
    QComboBox(QWidget *parent = 0);

public:
    void attachQmlObject(QWidget *qmlObject);

public:
    void setEditable(bool editable);
    void clear();
    int count();
    void setCurrentIndex(int index);
    void insertItem(int index, const QString &text);
    void removeItem(int index);
    void setItemText(int index, const QString &text);
    QString itemText(int index) const;
    QString editText() const;
    void setEditText(const QString &text);

Q_SIGNALS:
    void activated(int index);

private:
    QPointer<QQuickComboBox> m_qmlComboBox;
    QStringList m_qmlComboBoxModel;
};

// -----------------------------------------------------------------------------
class QTextEdit : public QQmlWidget
{
    Q_OBJECT
public:
    QTextEdit(QWidget *parent = 0);

public:
    void attachQmlObject(QWidget *qmlObject);

protected:
      bool eventFilter(QObject *obj, QEvent *event);

public:
    bool hasFocus();

    void cut();
    void copy();
    void paste();
    void clear();

    QRectF rect() const;
    void setGeometry(int x, int y, int w, int h);

    QFont font() const;
    void setFont(QFont font);

    QTextCursor textCursor() const;
    void setTextCursor(QTextCursor cursor);

    void setPlainText(QString str);
    QString toPlainText() const;

    QPalette palette() const;
    void setPalette(const QPalette &palette);

    void setReadOnly(bool);
    void setWrapMode(QQuickTextEdit::WrapMode w);
    void setTextFormat(QQuickTextEdit::TextFormat format);

Q_SIGNALS:
    void textChanged();
    void cursorPositionChanged();

private:
    QPointer<QQuickTextArea> m_qmlTextArea;
};

#endif

#endif // __sheetqmlui_h
