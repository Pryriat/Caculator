#include "mainwindow.h"

Mainwindow::Mainwindow(QDialog* parent):QDialog(parent)
{
    QGridLayout* mainlayout = new QGridLayout(this);
    QListWidget* left = new QListWidget(this);
    left->addItem("Caculator");
    mainlayout->setSpacing(10);
    mainlayout->setMargin(10);
    mainlayout->setSizeConstraint(QLayout::SetFixedSize);
    mainlayout->addWidget(left,0,0);
    Dialog* ca = new Dialog;
    mainlayout->addWidget(ca,0,1);
}
Mainwindow::~Mainwindow()
{

}
