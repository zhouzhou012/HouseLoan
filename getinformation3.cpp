#include "getinformation3.h"
#include "ui_getinformation3.h"
#include<QPainter>
#include<QDebug>
#include <QTimer>
#include<mypushbutton1.h>
#include<QIntValidator>
float loan1;
float loan2;
int years;
int ctype;
Getinformation3::Getinformation3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Getinformation3)
{
       //  配置信息场景
     ui->setupUi(this);
     this->setFixedSize(800,600);

     //  设置图标
     setWindowIcon(QIcon(":/image/logol1.jpg"));
     //  设置标题
     setWindowTitle("请输入信息");

     // 设置输入框字体大小
     ui->lineEdit1->setFont(QFont("ui->lineEdit1->text()",12,QFont::Bold));
     ui->lineEdit2->setFont(QFont("ui->lineEdit2->text()",12,QFont::Bold));
     ui->lineEdit3->setFont(QFont("ui->lineEdit3->text()",12,QFont::Bold));
     ui->lineEdit->setFont(QFont("ui->lineEdit->text()",12,QFont::Bold));

     QIntValidator *validator1 = new QIntValidator;    // 限制借贷输入
     ui->lineEdit1->setValidator(validator1);

     QIntValidator *validator2 = new QIntValidator;    // 限制借贷输入
     ui->lineEdit2->setValidator(validator2);


     QRegExp regx3("[1-9]|1[0-9]|2[0-5]");   //限制输入按揭年数
     QValidator *validator3= new QRegExpValidator(regx3, this);
     ui->lineEdit3->setValidator( validator3);

//     QIntValidator *validator3 = new QIntValidator;    // 限制输入按揭年数
//     validator3->setRange(1,25);
//     ui->lineEdit3->setValidator(validator3);

     MyPushButton1  *btn1=new MyPushButton1;
     btn1->setParent(this);
     btn1->setText(" 等额本息");
     btn1->resize(180,50);
     btn1->move(this->width()*0.4-btn1->width()*0.5,this->height()*0.7);
     btn1->setFont(QFont("等额本息",15,QFont::Bold));

     MyPushButton1  *btn2=new MyPushButton1;
     btn2->setParent(this);
     btn2->setText(" 等额本金");
     btn2->resize(180,50);
     btn2->move(this->width()*0.6,this->height()*0.7);
     btn2->setFont(QFont("等额本金",15,QFont::Bold));

     MyPushButton1  *btn3=new MyPushButton1;
     btn3->setParent(this);
     btn3->setText(" 确定");
     btn3->resize(180,50);
     btn3->move(this->width()-btn3->width(),this->height()-btn3->height());
     btn3->setFont(QFont("确定",15,QFont::Bold));


     //   连接还款方式按钮与转换类型和显示利率
    connect(btn1,&MyPushButton1::clicked,[=](){
       turn1();
       change();
    });

    //   连接还款方式按钮与转换类型和显示利率
    connect(btn2,&MyPushButton1::clicked,[=](){
       turn2();
       change();
    });

     //   连接开始计算按钮与传送数据
     connect(btn3,&MyPushButton1::clicked,this,&Getinformation3::Pass);

     connect(btn3,&MyPushButton1::clicked,[=](){
         qDebug()<<"点击进入";
         //  进入输出信息的界面
      combine1=new Combine;
      combine2=new Combine2;
           //  延时进入下一个界面
       QTimer::singleShot(500,this,[=](){
          //  将上一个界面隐藏
       this->hide();
        // 显示接下来的界面
        if(ctype==1)      // 组合型贷款等额本息还款
               combine1->show();
        if(ctype==2)
               combine2->show();
         });
      });
}

// 设置背景图片
void Getinformation3:: paintEvent(QPaintEvent *)
{
    QPainter painter1(this);
    QPixmap pix;
    pix.load(":/image/base.jpg");
    painter1.drawPixmap(0,0,this->width(),this->height(),pix);
}

void Getinformation3::Pass()
{
   loan1 =ui->lineEdit1->text().toFloat();
   loan2 =ui->lineEdit2->text().toFloat();
   years=ui->lineEdit3->text().toInt();
   qDebug()<<loan1;
   qDebug()<<loan2;
   qDebug()<<years;
}

void Getinformation3::change()
{
    years=ui->lineEdit3->text().toInt();
    if(years<=5)
        ui->lineEdit->setText("2.75%");
    else
        ui->lineEdit->setText("3.25%");
}

void Getinformation3::turn1()
{
     ctype=1;
     qDebug()<<ctype;
}
void Getinformation3::turn2()
{
    ctype=2;
    qDebug()<<ctype;
}
Getinformation3::~Getinformation3()
{
    delete ui;
}
