#include "ReportEditPage.h"
#include "ReportChapterItem.h"
#include "./ui_ReportEditPage.h"

ReportEditPage::ReportEditPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ReportEditPage)
{
    ui->setupUi(this);
    // ui->verticalLayout->removeItem(ui->mainItem);
}

ReportEditPage::~ReportEditPage()
{
    delete ui;
}

void ReportEditPage::initChaters(const QList<QString> &chapters, bool firstMain)
{
    for(int i = 0; i< chapters.size(); ++i)
    {
        auto item = new ReportChapterItem(chapters.at(i),this);
        if(i == 0)
            item->setMainItem();
        item->setName(chapters.at(i));
        ui->verticalLayout->addWidget(item);
    }
}
