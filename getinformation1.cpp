#include "getinformation1.h"
#include "ui_getinformation1.h"
#include<QPainter>
#include<QDebug>
#include<mypushbutton1.h>
#include <QTimer>
#include<QDoubleValidator>
float price;    //  cpp文件中需要再次定义
float space;
GetInformation1::GetInformation1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GetInformation1)
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

    QDoubleValidator *validator1 = new QDoubleValidator;    //限制输入房屋单价为数字（double型）
    ui->lineEdit1->setValidator(validator1);

   QDoubleValidator *validator2 = new QDoubleValidator;    // 限制输入房屋面积为数字 （double型）
   ui->lineEdit2->setValidator(validator2);

     //  创建确定按钮
     MyPushButton1  *btn=new MyPushButton1;
     btn->setParent(this);
     btn->setText(" 确定");
     btn->resize(180,50);
     btn->move(this->width()*0.5-btn->width()*0.5,this->height()*0.7);
     btn->setFont(QFont("确定",15,QFont::Bold));

     connect(btn,&MyPushButton1::clicked,[=](){
         qDebug()<<"点击进入";
         //  进入用户输入信息的界面
        information2=new GetInformation2;
         //  延时进入下一个界面
         QTimer::singleShot(500,this,[=](){
             //  将上一个界面隐藏
         this->hide();
             // 显示接下来的界面
         information2->show();
         });
     });

     //   连接确定按钮与传送数据
     connect(btn,&MyPushButton1::clicked,this,&GetInformation1::Pass);
}
// 设置背景图片
void GetInformation1:: paintEvent(QPaintEvent *)
{
    QPainter painter1(this);
    QPixmap pix;
    pix.load(":/image/base.jpg");
    painter1.drawPixmap(0,0,this->width(),this->height(),pix);
}

//  传送数据函数的实现
void GetInformation1::Pass()
{
price =ui->lineEdit1->text().toFloat();
space=ui->lineEdit2->text().toFloat();
qDebug()<<price;
qDebug()<<space;
}
GetInformation1::~GetInformation1()
{
    delete ui;
}
