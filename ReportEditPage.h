#pragma once

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class ReportEditPage;
}
QT_END_NAMESPACE

class ReportEditPage : public QWidget
{
    Q_OBJECT

public:
    ReportEditPage(QWidget *parent = nullptr);
    ~ReportEditPage();

    void initChaters(const QList<QString>& chapters, bool firstMain = true);

private:
    Ui::ReportEditPage *ui;
};
