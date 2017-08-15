#include "dialog.h"
#include <QApplication>
#include<QFont>
#include<QTextCodec>
#include"mainwindow.h"
#include<QPalette>
int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    return a.exec();
    exit(0);
}
