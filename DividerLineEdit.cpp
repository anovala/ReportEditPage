#include "DividerLineEdit.h"
#include <QPainter>
#include <QTextBlock>
#include <QRectF>
#include <QLine>
#include <QAbstractTextDocumentLayout>

DividerLineEdit::DividerLineEdit(QWidget *parent) :QPlainTextEdit(parent) {

    auto textCharFormat = this->currentCharFormat();
    // auto pen = textCharFormat.textOutline();
    this->setCurrentCharFormat(textCharFormat);
    this->setReadOnly(true);

    // connect(this,&QPlainTextEdit::blockCountChanged,this,[this](int){
    //     this->setLineHeight(35);
    // });
}

void DividerLineEdit::paintEvent(QPaintEvent *event)
{
    QPainter painter(viewport());
    painter.setPen(QPen(QColor(220,220,220)));
    auto contentRect =contentOffset();

    qDebug() <<"\n";
    qDebug() <<"contentOffset: " << contentRect;
    QTextBlock block = document()->begin();
    int count = 0;
    while (block.isValid()) {
        contentRect.setY(contentRect.y()*(count+1));
        auto blockRect = blockBoundingGeometry(block);
        blockRect.translate(0,1);
        // if(!block.next().isValid())
        // {
        //     blockRect.setHeight(blockRect.height()-contentRect.y());
        // }
        // painter.drawRect(blockRect);
        QLineF line(blockRect.bottomLeft(),blockRect.bottomRight());
        painter.drawLine(line);
        qDebug() << "blockBoundingRect"<<contentRect;
        qDebug() << "block:"<<count << "rect:"<<blockRect;
        count++;
        block = block.next();
    }

    QPlainTextEdit::paintEvent(event);
}

void DividerLineEdit::setLineHeight(qreal lineHeight)
{
    auto doc = this->document();
    QTextCursor cursor(doc);

    cursor.movePosition(QTextCursor::Start);
    while(!cursor.atEnd())
    {
        auto blockFormat = cursor.blockFormat();
        blockFormat.setLineHeight(lineHeight,QTextBlockFormat::FixedHeight);
        cursor.setBlockFormat(blockFormat);
        cursor.movePosition(QTextCursor::NextBlock);
    }
}
