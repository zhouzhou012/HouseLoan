#include "mypushbutton.h"
#include<QDebug>
#include<QPropertyAnimation>
 MyPushButton::MyPushButton(QString  normalImg,QString  pressImg )
 {
     this->normalImagPath=normalImg;
     this->prsssImgPath=pressImg;
     QPixmap  pix;
    bool  ret=pix.load(normalImg);
    if(!ret)
    {
        qDebug()<<"图片加载失败！";
    }
    //  设置图片固定大小

    this->setFixedSize(pix.width(),pix.height());

    // 不规则图片的样式

    this->setStyleSheet("QPushButton{border:none;}");  //  有缺陷！！！  图片边框没扣掉
    //  设置图标

    this->setIcon(pix);

    // 设置图标大小
    this->setIconSize(QSize(pix.width()*0.5,pix.height()*0.9));
 }
 void MyPushButton::zoom1()  //  向下跳
 {
     //  创建动态对象
    QPropertyAnimation* animation=new QPropertyAnimation(this,"geometry");
     //  设置时间间隔
    animation->setDuration(200);
    //  起始位置

    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));

    //  设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    // 执行动画
    animation->start();
 }
 void MyPushButton::zoom2()  //  向上跳
 {
     //  创建动态对象
    QPropertyAnimation* animation=new QPropertyAnimation(this,"geometry");
     //  设置时间间隔
    animation->setDuration(200);
    //  起始位置

    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));

    //  设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    // 执行动画
    animation->start();
 }

