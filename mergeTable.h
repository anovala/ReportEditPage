#pragma once

#include <QWidget>
#include <QMenu>
#include "mergeModel.h"
#include "headerDelegate.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class mergeTable;
}
QT_END_NAMESPACE

class mergeTable : public QWidget
{
    Q_OBJECT

public:
    // mergeTable(QWidget *parent = nullptr);
    mergeTable(const QString &name,QWidget *parent = nullptr);
    ~mergeTable();

    virtual void closeEvent(QCloseEvent *event);

private:
    void showMenu(const QPoint &pos);
    void createConnection();
    QString santizeTableName(const QString& input);

signals:
    void editFinished(TableState state);

public slots:
    void onConfirm();
    void onCancel();

private:
    Ui::mergeTable *ui;
    mergeModel *m_model;
    headerDelegate *m_delegate;
    QMenu menu;
    QString m_tableName;
};
