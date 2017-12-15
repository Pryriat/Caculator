#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QPushButton>
#include<QLineEdit>
#include<QTextEdit>
#include<QLabel>
#include<QString>
#include<QGraphicsEffect>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
protected:
    QString str;

    QLineEdit *resault;

    QPushButton *button_0;
    QPushButton *button_1;
    QPushButton *button_2;
    QPushButton *button_3;
    QPushButton *button_4;
    QPushButton *button_5;
    QPushButton *button_6;
    QPushButton *button_7;
    QPushButton *button_8;
    QPushButton *button_9;
    QPushButton *button_add;
    QPushButton *button_dec;
    QPushButton *button_mul;
    QPushButton *button_dev;
    QPushButton *button_dot;
    QPushButton *button_lb;
    QPushButton *button_rb;
    QPushButton *button_times;
    QPushButton *button_equ;
    QPushButton *button_AC;
    QPushButton *button_BACK;
    QLabel* history;
    QTextEdit* history_edit;
    QString* historydata;
    QPixmap background;
    QPalette pale;

private slots:
    void button_0_clicked();
    void button_1_clicked();
    void button_2_clicked();
    void button_3_clicked();
    void button_4_clicked();
    void button_5_clicked();
    void button_6_clicked();
    void button_7_clicked();
    void button_8_clicked();
    void button_9_clicked();
    void button_add_clicked();
    void button_dec_clicked();
    void button_mul_clicked();
    void button_dev_clicked();
    void button_dot_clicked();
    void button_lb_clicked();
    void button_rb_clicked();
    void button_times_clicked();
    void button_equ_clicked();
    void button_AC_clicked();
    void button_BACK_clicked();
public:
    explicit Dialog(QWidget *parent = 0);
    void setbutton(QPushButton* p, QFont* font, QSize* size, QGraphicsOpacityEffect* effect);
    void resizeEvent(QResizeEvent*);
    ~Dialog();

private:
    //Ui::Dialog *ui;
};

#endif // DIALOG_H
