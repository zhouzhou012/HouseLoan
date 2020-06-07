#include "choosetype.h"
#include "ui_choosetype.h"
#include<mypushbutton1.h>
#include<QPainter>
#include<QDebug>
#include <QTimer>
int variety;
ChooseType::ChooseType(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChooseType)
{
     //  配置信息场景
     ui->setupUi(this);
     this->setFixedSize(800,600);

     //  设置图标
     setWindowIcon(QIcon(":/image/logol1.jpg"));
     //  设置标题
     setWindowTitle("请选择贷款类型");

     //  设置贷款类型按钮
     MyPushButton1  *btn1=new MyPushButton1;
     btn1->setParent(this);
     btn1->setText(" 商业贷款");
     btn1->resize(180,50);
     btn1->move(this->width()*0.5-btn1->width()*0.5,this->height()*0.2);
     btn1->setFont(QFont("商业贷款",15,QFont::Bold));   //设置了按钮文字大小

     MyPushButton1  *btn2=new MyPushButton1;
     btn2->setParent(this);
     btn2->setText("公积金贷款");
     btn2->resize(180,50);
     btn2->move(this->width()*0.5-btn2->width()*0.5,this->height()*0.4);
     btn2->setFont(QFont("公积金贷款",15,QFont::Bold));

     MyPushButton1  *btn3=new MyPushButton1;
     btn3->setParent(this);
     btn3->setText(" 组合型贷款");
     btn3->resize(180,50);
     btn3->move(this->width()*0.5-btn3->width()*0.5,this->height()*0.6);
     btn3->setFont(QFont("组合型贷款",15,QFont::Bold));


     //   连接贷款类型按钮与转换类型
     connect(btn1,&MyPushButton1::clicked,this,&ChooseType::turn1);
     connect(btn2,&MyPushButton1::clicked,this,&ChooseType::turn2);
     connect(btn3,&MyPushButton1::clicked,this,&ChooseType::turn3);

     connect(btn1,&MyPushButton1::clicked,[=](){
         qDebug()<<"点击进入";
         //  进入用户输入商业贷款信息的界面
         information1=new GetInformation1;
         //  延时进入下一个界面
         QTimer::singleShot(500,this,[=](){
             //  将上一个界面隐藏
             this->hide();
             // 显示接下来的界面
             information1->show();
         });
     });
         connect(btn2,&MyPushButton1::clicked,[=](){
             qDebug()<<"点击进入";
             //  进入用户输入公积金贷款信息的界面
             information1=new GetInformation1;
             //  延时进入下一个界面
             QTimer::singleShot(500,this,[=](){
                //  将上一个界面隐藏
             this->hide();
               // 显示接下来的界面
              information1->show();
             });
          });
             connect(btn3,&MyPushButton1::clicked,[=](){
                 qDebug()<<"点击进入";
                 //  进入用户输入组合型贷款信息的界面
                 information3=new Getinformation3;
                 //  延时进入下一个界面
                 QTimer::singleShot(500,this,[=](){
                     //  将上一个界面隐藏
                  this->hide();
                     // 显示接下来的界面
                  information3->show();
                 });
           });
}

// 设置背景图片
void ChooseType:: paintEvent(QPaintEvent *)
{
    QPainter painter1(this);
    QPixmap pix;
    pix.load(":/image/base.jpg");
    painter1.drawPixmap(0,0,this->width(),this->height(),pix);
}

void ChooseType::turn1()
{
    variety=1;
    qDebug()<<variety;
}
void ChooseType::turn2()
{
    variety=2;
    qDebug()<<variety;
}
void ChooseType::turn3()
{
   variety=3;
    qDebug()<<variety;
}
ChooseType::~ChooseType()
{
    delete ui;
}
