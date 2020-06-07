#include "commercial1.h"
#include "ui_commercial1.h"
#include<qmath.h>
#include<QPainter>
#include"getinformation1.h"
#include"getinformation2.h"
#include<QDebug>
#include<mypushbutton1.h>
#include<QString>

Commercial1::Commercial1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Commercial1)
{
    //  配置信息场景
    ui->setupUi(this);
     this->setFixedSize(800,600);

     //  设置图标
     setWindowIcon(QIcon(":/image/logol1.jpg"));
     //  设置标题
     setWindowTitle("输出信息");
     MyPushButton1  *btn=new MyPushButton1;
     btn->setParent(this);
     btn->setText(" 开始计算");
     btn->resize(180,50);
     btn->setFont(QFont("开始计算",15,QFont::Bold));

    //设置完成按钮 结束程序
     MyPushButton1  *btn4=new MyPushButton1;
     btn4->setParent(this);
     btn4->setText(" 完成");
     btn4->resize(180,50);
     btn4->move(this->width()-btn4->width(),this->height()-btn4->height());
     btn4->setFont(QFont("完成",15,QFont::Bold));
     connect(btn4,&MyPushButton1::clicked,this,&QWidget::close);

      // 设置输出框字体大小
     ui->lineEdit1->setFont(QFont("ui->lineEdit1->text()",12,QFont::Bold));
     ui->lineEdit2->setFont(QFont("ui->lineEdit2->text()",12,QFont::Bold));
     ui->lineEdit3->setFont(QFont("ui->lineEdit3->text()",12,QFont::Bold));
     ui->lineEdit4->setFont(QFont("ui->lineEdit4->text()",12,QFont::Bold));
     ui->lineEdit5->setFont(QFont("ui->lineEdit5->text()",12,QFont::Bold));
     ui->lineEdit6->setFont(QFont("ui->lineEdit6->text()",12,QFont::Bold));

        //  用信号和槽的机制调用传递和计算函数
     connect(btn,&MyPushButton1::clicked,[=](){
         pass();
         calculate( unit_price, area, period,  percentage1);
     });
}

// 设置背景图片
void Commercial1:: paintEvent(QPaintEvent *)
{
    QPainter painter1(this);
    QPixmap pix;
    pix.load(":/image/base.jpg");
    painter1.drawPixmap(0,0,this->width(),this->height(),pix);
}

// 计算及显示函数的实现
 void Commercial1 ::calculate(double unit_price, double area,int period, float percentage1)
 {   extern  int variety;                                                   //确定贷款类型
     sumprice=unit_price*area;                                      //总价
     totalloans=sumprice*percentage1/10;                       //贷款总额
     payment=sumprice-totalloans;                                 //首付

     // 根据贷款类型和贷款年数得到不同贷款利率 计算首月月供
     if(period<=5&&variety==1)
    { monthsupply=(totalloans*rate1*qPow((1+rate1),period*12))/(qPow(1+rate1,period*12)-1);}
     if(6<=period&&variety==1)
     {monthsupply=(totalloans*rate2*qPow((1+rate2),period*12))/(qPow(1+rate2,period*12)-1);}

     if(period<=5&&variety==2)
    { monthsupply=(totalloans*rate3*qPow((1+rate3),period*12))/(qPow(1+rate3,period*12)-1);}
     if(6<=period&&variety==2)
     {monthsupply=(totalloans*rate4*qPow((1+rate4),period*12))/(qPow(1+rate4,period*12)-1);}
     sumpaybacks=monthsupply*period*12;                        //还款总额
     sumrates=sumpaybacks-totalloans;                              //还款总利息
     month=period*12;                                                         //还款月数

   //显示      用四舍五入  不能直接强制类型转换 否则结果不准确
     ui->lineEdit1->setText(QString::number((int)round(payment)));
     ui->lineEdit2->setText(QString::number((int)round(monthsupply)));
     ui->lineEdit3->setText(QString::number((int)round(totalloans)));
     ui->lineEdit4->setText(QString::number((int)round(sumrates)));
     ui->lineEdit5->setText(QString::number((int)round(sumpaybacks)));
     ui->lineEdit6->setText(QString::number((int)month));
 }

 // 传递函数的实现
 void Commercial1::pass()
{
     extern float price;
     extern float space;
     extern float percentage;
     extern int year;
     unit_price=price;
     area=space;
     period=year;
     percentage1=percentage;
}
Commercial1::~Commercial1()
{
    delete ui;
}
