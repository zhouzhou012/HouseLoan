#include "mainscene.h"
#include "ui_mainscene.h"
#include<QPainter>
#include<QDebug>
#include<mypushbutton.h>
#include <QTimer>
MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    //  主背景

    // 固定窗口大小
    setFixedSize(800,600);
    //  设置图标
    setWindowIcon(QIcon(":/image/logol1.jpg"));
    //  设置标题
    setWindowTitle("一起买房吧");

    // 进入按钮

    MyPushButton  *enterbtn=new MyPushButton(":/image/button.jpg");
    enterbtn->setParent(this);
    enterbtn->move(this->width()*0.5-enterbtn->width()*0.5,this->height()*0.4);

//   enterbtn->setStyleSheet("border:none");   //！！！去除进入图片的边框，但是没有实现效果

//    enterbtn->setStyleSheet("border:2px groove gray;border-radius :10px;padding:2px 4px;");
   // enterbtn->setFlat(true);

    connect(enterbtn,&MyPushButton::clicked,[=](){
        qDebug()<<"点击进入";

        // 做一个按钮弹起的特效
        enterbtn->zoom1();
        enterbtn->zoom2();

        //  进入用户选择贷款类型的界面的界面
         choosetype=new ChooseType;

        //  延时进入下一个界面
        QTimer::singleShot(500,this,[=](){
            //  将上一个界面隐藏
            this->hide();
            // 显示接下来的界面
            choosetype->show();
        });
    });


}
    // 设置背景图片
    void MainScene:: paintEvent(QPaintEvent *)
    {
        QPainter painter(this);
        QPixmap pix;
        pix.load(":/image/base.jpg");
        painter.drawPixmap(0,0,this->width(),this->height(),pix);
    }

MainScene::~MainScene()
{
    delete ui;
}

