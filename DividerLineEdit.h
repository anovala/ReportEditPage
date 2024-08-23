#pragma once

#include <QPlainTextEdit>

class DividerLineEdit : public QPlainTextEdit
{
    Q_OBJECT
public:
    DividerLineEdit(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event) override;
    void setLineHeight(qreal lineHegiht);
};
