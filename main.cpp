#include "ReportEditPage.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QStringList list;
    list <<"样品图"<< "E-01"<<"E-02"<<"E-03";
    ReportEditPage w;
    w.initChaters(list);
    w.resize(800,600);
    w.show();
    return a.exec();
}
