#include "calc.h"
#include "ui_calc.h"
#include<iostream>

double first,last,num,res;
char op;
QString a;
calc::calc(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::calc)
{
    ui->setupUi(this);
    connect(ui->b0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->b1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->b2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->b3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->b4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->b5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->b6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->b7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->b8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->b9,SIGNAL(released()),this,SLOT(digit_pressed()));


}

calc::~calc()
{
    delete ui;
}


void calc::digit_pressed()
{
    QPushButton * button = (QPushButton*)sender();
    QString lab;

    num=(ui->LE->text()+button->text()).toDouble();
    lab=QString::number(num);
    ui->LE->setText(lab);
}


void calc::on_b_cl_released()
{
    ui->LE->clear();
    first=0;
    last=0;
}


void calc::on_b_plus_released()
{
    first=num;
    ui->LE->clear();
    op='+';
}


void calc::on_b_min_released()
{
    first=num;
    ui->LE->clear();
    op='-';
}


void calc::on_b_div_released()
{
    first=num;
    ui->LE->clear();
    op='/';
}


void calc::on_b_mul_released()
{
    first=num;
    ui->LE->clear();
    op='*';
}


void calc::on_b_eq_released()
{
    last=num;
    switch(op)
    {
        case '+' :
            res=first+last;
            a=QString::number(res);
            ui->LE->setText(a);
            break;

         case '-':
            res=first-last;
            a=QString::number(res);
            ui->LE->setText(a);
            break;

         case '/':
            res=first/last;
            a=QString::number(res);
            ui->LE->setText(a);
            break;

          case '*':
            res=first*last;
            a=QString::number(res);
            ui->LE->setText(a);
            break;



    }
}

