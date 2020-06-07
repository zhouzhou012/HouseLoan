#ifndef GETINFORMATION2_H
#define GETINFORMATION2_H

#include <QMainWindow>
#include"commercial1.h"
#include"commercial2.h"
extern float percentage;  // 全局变量  贷款成数
extern int year;               //贷款年数
extern  int type;           //还款方式

namespace Ui {
class GetInformation2;
}

class GetInformation2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit GetInformation2(QWidget *parent = nullptr);
    ~GetInformation2();
     void paintEvent(QPaintEvent *);

     Commercial1 *commercial1 =NULL;
     Commercial2 *commercial2 =NULL;

     //  传送数据函数
     void Pass();

     //  转换还款类型
     void turn1();
     void turn2();

   //  设置贷款利率
     void change();

private:
    Ui::GetInformation2 *ui;
};

#endif // GETINFORMATION2_H
