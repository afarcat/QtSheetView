TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS += sheetview

greaterThan(QT_MAJOR_VERSION, 4) {
    qtHaveModule(quick) {
        SUBDIRS += sheetqml
    }
}
