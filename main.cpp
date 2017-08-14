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
    QPixmap background;
    background.load(":/bg");
    Dialog w;
    w.setWindowOpacity(0.9);
    QPalette pale = w.palette();
    pale.setBrush(QPalette::Background,QBrush(background.scaled(w.size())));
    w.setPalette(pale);
    w.setAutoFillBackground(true);
    w.show();
    return a.exec();
    exit(0);
}
