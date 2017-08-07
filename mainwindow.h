#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<Qdialog>
#include<QLayout>
#include<QListWidget>
#include"dialog.h"
class Mainwindow:public QDialog
{
public:
    Mainwindow(QDialog* parent = 0);
    ~Mainwindow();
};

#endif // MAINWINDOW_H
