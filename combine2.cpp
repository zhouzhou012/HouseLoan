#include "combine2.h"
#include "ui_combine2.h"
#include"getinformation3.h"
#include<qmath.h>
#include<QPainter>
#include<QDebug>
#include<mypushbutton1.h>
#include<QString>
Combine2::Combine2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Combine2)
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

     //  用信号和槽的机制调用计算函数
  connect(btn,&MyPushButton1::clicked,[=](){
      pass();
      calculate( Loan1,Loan2, period );
  });
}

// 设置背景图片
void Combine2:: paintEvent(QPaintEvent *)
{
    QPainter painter1(this);
    QPixmap pix;
    pix.load(":/image/base.jpg");
    painter1.drawPixmap(0,0,this->width(),this->height(),pix);
}

 void Combine2::calculate(double Loan1,double Loan2,int period)
 {
    double  fmonthsupply1;          //商业贷款首月月供
    double  smonthsupply1;         //商业贷款次月月供
    double  sumrates1;                 //商业贷款还款总利息
    double fmonthsupply2;        //公积金贷款首月月供
    double  smonthsupply2;       //公积金贷款次月月供
    double sumrates2;                  //公积金贷款还款总利息
    totalloans=Loan1+Loan2;      //贷款总额
    month=period*12;                  //还款月数
    if(period<=5)
     { fmonthsupply1=(Loan1/month)+Loan1*rate1;
       smonthsupply1=(Loan1/month)+(Loan1-Loan1/month)*rate1;
       sumrates1=(month+1)*Loan1*rate1/2;}
      if(period<=5)
     { fmonthsupply2=(Loan2/month)+Loan2*rate1;
       smonthsupply2=(Loan2/month)+(Loan2-Loan2/month)*rate1;
       sumrates2=(month+1)*Loan2*rate1/2;}
      if(period>5)
     { fmonthsupply1=(Loan1/month)+Loan1*rate2;
       smonthsupply1=(Loan1/month)+(Loan1-Loan1/month)*rate2;
       sumrates1=(month+1)*Loan1*rate2/2;}
      if(period>5)
     { fmonthsupply2=(Loan2/month)+Loan2*rate2;
       smonthsupply2=(Loan2/month)+(Loan2-Loan2/month)*rate2;
       sumrates2=(month+1)*Loan2*rate2/2;}

      fmonthsupply=fmonthsupply1+fmonthsupply2;    //首月月供
      smonthsupply=smonthsupply1+smonthsupply2;   //次月月供
      cha=fmonthsupply-smonthsupply;                         //每月递减
      sumrates=sumrates1+sumrates2;                          //还款总利息
      sumpaybacks=sumrates+totalloans;                     //还款总额

      //显示
      ui->lineEdit1->setText(QString::number((int)round(fmonthsupply)));
      ui->lineEdit2->setText(QString::number((int )round(cha)));
      ui->lineEdit3->setText(QString::number((int )round(totalloans)));
      ui->lineEdit4->setText(QString::number((int )round(sumrates)));
      ui->lineEdit5->setText(QString::number((int)round(sumpaybacks)));
      ui->lineEdit6->setText(QString::number((int)month));
 }

 void  Combine2::pass()
 {
     extern float loan1;
     extern float loan2;
     extern int years;
     Loan1=loan1*10000;
     Loan2=loan2*10000;
     period=years;

 }

Combine2::~Combine2()
{
    delete ui;
}
