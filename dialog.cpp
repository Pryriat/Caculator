#include "dialog.h"
//#include "ui_dialog.h"
#include<caculate.h>
#include<head.h>
#include<QLayout>

void Dialog::setbutton(QPushButton *p, QFont* font, QSize* size, QGraphicsOpacityEffect* effect)
{
    p->setFlat(true);
    p->setFixedSize(*size);
    p->setFont(*font);
    //p->setGraphicsEffect(effect);
}

Dialog::Dialog(QWidget *parent) :QDialog(parent)
  //ui(new Ui::Dialog)
{
    QSize size(50,50);
    this->setMinimumSize(QSize(480,480));
    QGraphicsOpacityEffect* p = new QGraphicsOpacityEffect(this);
    p->setOpacity(0.5);
    QGraphicsOpacityEffect* pq = new QGraphicsOpacityEffect(this);
    pq->setOpacity(0.5);
    QFont font;
    font.setPointSize(25);
    button_0 = new QPushButton("0");
    button_1 = new QPushButton("1");
    button_2 = new QPushButton("2");
    button_3 = new QPushButton("3");
    button_4 = new QPushButton("4");
    button_5 = new QPushButton("5");
    button_6 = new QPushButton("6");
    button_7 = new QPushButton("7");
    button_8 = new QPushButton("8");
    button_9 = new QPushButton("9");
    button_mul = new QPushButton("*");
    button_dec = new QPushButton("-");
    button_add = new QPushButton("+");
    button_dev = new QPushButton("/");
    button_lb = new QPushButton("(");
    button_rb = new QPushButton(")");
    button_times = new QPushButton("^");
    button_dot = new QPushButton(".");
    button_equ = new QPushButton("=");
    button_AC = new QPushButton("AC");

    setbutton(button_0,&font,&size,p);
    setbutton(button_1,&font,&size,p);
    setbutton(button_2,&font,&size,p);
    setbutton(button_3,&font,&size,p);
    setbutton(button_4,&font,&size,p);
    setbutton(button_5,&font,&size,p);
    setbutton(button_6,&font,&size,p);
    setbutton(button_7,&font,&size,p);
    setbutton(button_8,&font,&size,p);
    setbutton(button_9,&font,&size,p);
    setbutton(button_mul,&font,&size,p);
    setbutton(button_dec,&font,&size,p);
    setbutton(button_add,&font,&size,p);
    setbutton(button_dev,&font,&size,p);
    setbutton(button_lb,&font,&size,p);
    setbutton(button_rb,&font,&size,p);
    setbutton(button_times,&font,&size,p);
    setbutton(button_dot,&font,&size,p);
    setbutton(button_equ,&font,&size,p);
    setbutton(button_AC,&font,&size,p);

    resault = new QLineEdit();
    resault->setFixedHeight(50);
    resault->setFixedWidth(300);
    resault->setFont(font);
    resault->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-width:0;border-style:outset;");
    resault->setReadOnly(true);
    history = new QLabel("历史");
    history_edit = new QTextEdit;
    historydata = new QString;
    history->setFixedWidth(50);
    font.setPointSize(20);
    history->setFont(font);
    history_edit->setFont(font);
    history_edit->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-width:0;border-style:outset;");
    history_edit->setReadOnly(true);

    QGridLayout* mainlayout = new QGridLayout(this);
    mainlayout->addWidget(resault,0,0,1,5);
    mainlayout->addWidget(button_1,1,0,1,1);
    mainlayout->addWidget(button_2,1,1,1,1);
    mainlayout->addWidget(button_3,1,2,1,1);
    mainlayout->addWidget(button_add,1,3,1,1);
    mainlayout->addWidget(button_dec,1,4,1,1);
    mainlayout->addWidget(button_4,2,0,1,1);
    mainlayout->addWidget(button_5,2,1,1,1);
    mainlayout->addWidget(button_6,2,2,1,1);
    mainlayout->addWidget(button_mul,2,3,1,1);
    mainlayout->addWidget(button_dev,2,4,1,1);
    mainlayout->addWidget(button_7,3,0,1,1);
    mainlayout->addWidget(button_8,3,1,1,1);
    mainlayout->addWidget(button_9,3,2,1,1);
    mainlayout->addWidget(button_lb,3,3,1,1);
    mainlayout->addWidget(button_rb,3,4,1,1);
    mainlayout->addWidget(button_times,4,0,1,1);
    mainlayout->addWidget(button_0,4,1,1,1);
    mainlayout->addWidget(button_dot,4,2,1,1);
    mainlayout->addWidget(button_equ,4,3,1,1);
    mainlayout->addWidget(button_AC,4,4,1,1);
    mainlayout->addWidget(history,0,5,1,3,Qt::AlignCenter);
    mainlayout->addWidget(history_edit,1,5,4,3);
    mainlayout->setMargin(10);
    //mainlayout->setSpacing(10);
    mainlayout->setRowStretch(0,1);
    mainlayout->setRowStretch(1,1);
    mainlayout->setRowStretch(2,1);
    mainlayout->setRowStretch(3,1);
    mainlayout->setRowStretch(4,1);

    mainlayout->setColumnStretch(0,1);
    mainlayout->setColumnStretch(1,1);
    mainlayout->setColumnStretch(2,1);
    mainlayout->setColumnStretch(3,1);
    mainlayout->setColumnStretch(4,1);
    mainlayout->setColumnStretch(5,3);
    //mainlayout->setSizeConstraint(QLayout::SetFixedSize);
    //mainlayout->setRowStretch(0,1);
    //mainlayout->setSizeConstraint(QLayout::SetFixedSize);

    connect(button_0,SIGNAL(clicked(bool)),this,SLOT(button_0_clicked()));
    connect(button_1,SIGNAL(clicked(bool)),this,SLOT(button_1_clicked()));
    connect(button_2,SIGNAL(clicked(bool)),this,SLOT(button_2_clicked()));
    connect(button_3,SIGNAL(clicked(bool)),this,SLOT(button_3_clicked()));
    connect(button_4,SIGNAL(clicked(bool)),this,SLOT(button_4_clicked()));
    connect(button_5,SIGNAL(clicked(bool)),this,SLOT(button_5_clicked()));
    connect(button_6,SIGNAL(clicked(bool)),this,SLOT(button_6_clicked()));
    connect(button_7,SIGNAL(clicked(bool)),this,SLOT(button_7_clicked()));
    connect(button_8,SIGNAL(clicked(bool)),this,SLOT(button_8_clicked()));
    connect(button_9,SIGNAL(clicked(bool)),this,SLOT(button_9_clicked()));
    connect(button_add,SIGNAL(clicked(bool)),this,SLOT(button_add_clicked()));
    connect(button_mul,SIGNAL(clicked(bool)),this,SLOT(button_mul_clicked()));
    connect(button_dec,SIGNAL(clicked(bool)),this,SLOT(button_dec_clicked()));
    connect(button_dev,SIGNAL(clicked(bool)),this,SLOT(button_dev_clicked()));
    connect(button_dot,SIGNAL(clicked(bool)),this,SLOT(button_dot_clicked()));
    connect(button_lb,SIGNAL(clicked(bool)),this,SLOT(button_lb_clicked()));
    connect(button_rb,SIGNAL(clicked(bool)),this,SLOT(button_rb_clicked()));
    connect(button_times,SIGNAL(clicked(bool)),this,SLOT(button_times_clicked()));
    connect(button_AC,SIGNAL(clicked(bool)),this,SLOT(button_AC_clicked()));
    connect(button_equ,SIGNAL(clicked(bool)),this,SLOT(button_equ_clicked()));

    //setLayout(frame);

    //ui->setupUi(this);
}

void Dialog::button_0_clicked()
{
    //str.append('0');
    resault->insert("0");
}
void Dialog::button_1_clicked()
{
    //str.append('1');
    resault->insert("1");
}
void Dialog::button_2_clicked()
{
    //str.append('2');
    resault->insert("2");
}
void Dialog::button_3_clicked()
{
    //str.append('3');
    resault->insert("3");
}
void Dialog::button_4_clicked()
{
    //str.append('4');
    resault->insert("4");
}
void Dialog::button_5_clicked()
{
    //str.append('5');
    resault->insert("5");
}
void Dialog::button_6_clicked()
{
    //str.append('6');
    resault->insert("6");
}
void Dialog::button_7_clicked()
{
    //str.append('7');
    resault->insert("7");
}
void Dialog::button_8_clicked()
{
    //str.append('8');
    resault->insert("8");
}
void Dialog::button_9_clicked()
{
    //str.append('9');
    resault->insert("9");
}
void Dialog::button_add_clicked()
{
    //str.append('+');
    resault->insert("+");
}
void Dialog::button_dec_clicked()
{
    //str.append('-');
    resault->insert("-");
}
void Dialog::button_mul_clicked()
{
    //str.append('*');
    resault->insert("*");
}
void Dialog::button_dev_clicked()
{
    //str.append('/');
    resault->insert("/");
}
void Dialog::button_dot_clicked()
{
    //str.append('.');
    resault->insert(".");
}
void Dialog::button_lb_clicked()
{
    //str.append('(');
    resault->insert("(");
}
void Dialog::button_rb_clicked()
{
    //str.append(')');
    resault->insert(")");
}
void Dialog::button_times_clicked()
{
    //str.append('^');
    resault->insert("^");
}
void Dialog::button_AC_clicked()
{
    //str.clear();
    resault->clear();
}
void Dialog::button_equ_clicked()
{
    if(resault->text()[resault->text().length()-1] != '=')
        resault->insert("=");
    str = resault->text();
    historydata->append(str);
    resault->clear();
    QString tempStr;
    QString erro_str;
    string equation = str.toStdString();
    try
    {
        analyze(equation);
        vector<num> t = numbers(equation);
        vector<char> p = signs(equation);
        brancket check = checksign(p);
        t = coustom_caculate(t,p,check);
        double temp = t[0].nums();
        tempStr.setNum(temp);
        resault->setText(tempStr);
        historydata->append(tempStr+"\n");
        history_edit->setText(*historydata);

    }
    catch (erro_info& a)
    {
        switch (a.err_num)
        {
        case 1:
            resault->setText("运算符与算子个数不匹配");
            break;
        case 2:
            resault->setText("算式末尾缺少等号");
            break;
        case 3:
            erro_str = QString("括号不匹配，左括号%1个，右括号%2个").arg(a.left_num).arg(a.right_num);
            resault->setText(erro_str);
            break;
        case 4:
            erro_str = QString("小数点位置错误或连用,错误子式为%1%2%3").arg(a.position1)\
                    .arg(a.position2).arg(a.position3);
            resault->setText(erro_str);
            break;
        case 5:
            resault->setText("有效算式长度为零");
            break;
        case 6:
            erro_str = QString("被除数为0，错误子式为%1%2%3").arg(a.left_num)\
                    .arg(a.position1).arg(a.right_num);
            resault->setText(erro_str);
            break;
        case 7:
            erro_str = QString("不支持符号连用，错误子式为%1%2%3").arg(a.position1)\
                    .arg(a.position2).arg(a.position3);
            resault->setText(erro_str);
            break;
        case 8:
            erro_str = QString("非法输入,非法字符为%1").arg(a.position1);
            resault->setText(erro_str);
            break;
        }
    }
}
Dialog::~Dialog()
{
    //delete ui;
}
