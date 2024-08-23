#include "ReportChapterItem.h"
#include "ui_ReportChapterItem.h"
#include <QFileDialog>
#include <QTableView>

// ReportChapterItem::ReportChapterItem(QWidget *parent)
//     : QWidget(parent)
//     , ui(new Ui::ReportChapterItem)
//     , isMainItem(false)
// {
//     ui->setupUi(this);
//     createConnection();
// }

ReportChapterItem::ReportChapterItem(const QString &name, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ReportChapterItem)
    , isMainItem(false)
    , m_table(nullptr)
    , m_useTable(false)
{
    ui->setupUi(this);
    createConnection();
    ui->chapterName->setText(name);
}

ReportChapterItem::~ReportChapterItem()
{
    delete ui;
    if(m_table)
    {
        m_table->deleteLater();
        m_table = nullptr;
    }
}

void ReportChapterItem::setName(const QString &name)
{
    ui->chapterName->setText(name);
    m_itemName = name;
}

void ReportChapterItem::setMainItem(bool b)
{
    isMainItem = true;
    ui->pinBtn->hide();
    ui->picBtn->setText("选择样品图");
}

void ReportChapterItem::createConnection()
{
    connect(ui->picBtn,&QPushButton::clicked,this,&ReportChapterItem::insertPic);
    connect(ui->pinBtn,&QPushButton::clicked,this,&ReportChapterItem::configTable);
}

void ReportChapterItem::insertPic()
{
    auto picList = QFileDialog::getOpenFileNames(this,"图片选择","",tr("Image Files (*.png *.jpg *.bmp)"));
    if(picList.empty())
        return;
    ui->plainTextEdit->clear();
    for(auto &&picPath:picList)
    {
        ui->plainTextEdit->appendPlainText(picPath);
    }
}

void ReportChapterItem::configTable()
{
    if(!m_table)
    {
        m_table = new mergeTable(m_itemName);
    }

    if(!m_useTable)
    {
        m_useTable = true;
        ui->verticalLayout->addWidget(m_table);
        ui->pinBtn->setText("取消表格");
        this->setMinimumHeight(350);
        m_table->setVisible(true);
    }else{
        m_useTable = false;
        ui->verticalLayout->removeWidget(m_table);
        ui->pinBtn->setText("设置引脚表格");
        this->setMinimumHeight(0);
        m_table->setVisible(false);
    }

    // m_table->show();
}
