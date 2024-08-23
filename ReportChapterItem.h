#pragma once

#include "mergeModel.h"
#include "mergeTable.h"
#include <QWidget>

namespace Ui {
class ReportChapterItem;
}

class ReportChapterItem : public QWidget
{
    Q_OBJECT

public:
    // explicit ReportChapterItem(QWidget *parent = nullptr);
    explicit ReportChapterItem(const QString& name, QWidget *parent);
    ~ReportChapterItem();

    void setName(const QString &name);
    void setMainItem(bool b = true);
    void createConnection();

public slots:
    void insertPic();
    void configTable();

private:
    Ui::ReportChapterItem *ui;
    bool isMainItem;
    TableState m_tableState;
    QString m_itemName;
    mergeTable *m_table;
    bool m_useTable;
};
