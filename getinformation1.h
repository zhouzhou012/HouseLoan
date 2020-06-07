#ifndef GETINFORMATION1_H
#define GETINFORMATION1_H

#include <QMainWindow>
#include"getinformation2.h"
extern float price;   //  房屋单价   （在.h头文件中声明成全局变量  之后就能在其他文件中调用了）
extern float space;   // 房屋面积

namespace Ui {
class GetInformation1;
}

class GetInformation1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit GetInformation1(QWidget *parent = nullptr);
    ~GetInformation1();

     void paintEvent(QPaintEvent *);
     GetInformation2  *information2=NULL;

     //  传送数据函数
     void Pass();

private:
    Ui::GetInformation1 *ui;
};

#endif // GETINFORMATION1_H
