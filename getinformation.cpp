#include "getinformation.h"
#include<QPainter>
GetInformation::GetInformation(QWidget *parent) : QMainWindow(parent)
{
   //  配置信息场景
    this->setFixedSize(800,600);

    //  设置图标
    setWindowIcon(QIcon(":/image/logol1.jpg"));
    //  设置标题
    setWindowTitle("请输入信息");
}
// 设置背景图片
void GetInformation:: paintEvent(QPaintEvent *)
{
    QPainter painter1(this);
    QPixmap pix;
    pix.load(":/image/base.jpg");
    painter1.drawPixmap(0,0,this->width(),this->height(),pix);
}
