#include "getinformation2.h"
#include "ui_getinformation2.h"
#include<mypushbutton1.h>
#include<QPainter>
#include<QDebug>
#include <QTimer>
#include<QIntValidator>
#include<QDoubleValidator>
float percentage;
int year;
int type;
GetInformation2::GetInformation2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GetInformation2)
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
     ui->lineEdit->setFont(QFont("ui->lineEdit->text()",12,QFont::Bold));

      QRegExp regx1("[2-8]|[2-8][.]5");   //限制输入按揭成数
      QValidator *validator1= new QRegExpValidator(regx1, this);
      ui->lineEdit1->setValidator( validator1 );

      QRegExp regx2("[1-9]|1[0-9]|2[0-5]|");   //限制输入按揭年数
      QValidator *validator2= new QRegExpValidator(regx2, this);
      ui->lineEdit2->setValidator( validator2);

//     QDoubleValidator *validator1 = new QDoubleValidator;    //限制输入按揭成数
//     ui->lineEdit1->setValidator(validator1);

//     QIntValidator *validator2 = new QIntValidator;    // 限制输入按揭年数
//     validator2->setRange(1,25);
//     ui->lineEdit2->setValidator(validator2);

     MyPushButton1  *btn1=new MyPushButton1;
     btn1->setParent(this);
     btn1->setText(" 等额本息");
     btn1->resize(180,50);
     btn1->move(this->width()*0.4-btn1->width()*0.5,this->height()*0.65);
     btn1->setFont(QFont("等额本息",15,QFont::Bold));

     MyPushButton1  *btn2=new MyPushButton1;
     btn2->setParent(this);
     btn2->setText(" 等额本金");
     btn2->resize(180,50);
     btn2->move(this->width()*0.6 ,this->height()*0.65);
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

     connect(btn3,&MyPushButton1::clicked,[=](){
         qDebug()<<"点击进入";

         //  进入输出信息的界面
      commercial1=new Commercial1;
      commercial2=new Commercial2;
         //  延时进入下一个界面
      QTimer::singleShot(500,this,[=](){
        //  将上一个界面隐藏
       this->hide();
       // 显示接下来的界面
        if(type==1)      //  将商业贷款跟公积金贷款写在一起
             commercial1->show();
        if(type==2)
               commercial2->show();
         });
      });

     //   连接开始计算按钮与传送数据
     connect(btn3,&MyPushButton1::clicked,this,&GetInformation2::Pass);
}
// 设置背景图片
void GetInformation2:: paintEvent(QPaintEvent *)
{
    QPainter painter1(this);
    QPixmap pix;
    pix.load(":/image/base.jpg");
    painter1.drawPixmap(0,0,this->width(),this->height(),pix);
}

void GetInformation2::Pass()
{
   percentage =ui->lineEdit1->text().toFloat();
   year=ui->lineEdit2->text().toInt();
   qDebug()<<percentage;
   qDebug()<<year;
}

void GetInformation2::turn1()
{
    type=1;
    qDebug()<<type;
}
void GetInformation2::turn2()
{
     type=2;
    qDebug()<<type;
}

void GetInformation2::change()
{
    extern int variety;
    year=ui->lineEdit2->text().toInt();
    if(year<=5&&variety==1)
        ui->lineEdit->setText("4.05%");
    else if(year>5&&variety==1)
        ui->lineEdit->setText("4.75%");
    else if(year<=5&&variety==2)
        ui->lineEdit->setText("2.75%");
    else if(year>5&&variety==2)
        ui->lineEdit->setText("3.25%");
}
GetInformation2::~GetInformation2()
{
    delete ui;
}
