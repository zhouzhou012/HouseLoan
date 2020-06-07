#ifndef GETINFORMATION3_H
#define GETINFORMATION3_H

#include <QMainWindow>
#include"combine1.h"
#include"combine2.h"
extern float loan1;    //  商业贷款
extern float loan2;   //公积金贷款
extern int years;      //贷款年数
extern int ctype;     //还款方式

namespace Ui {
class Getinformation3;
}

class Getinformation3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Getinformation3(QWidget *parent = nullptr);
    ~Getinformation3();
    void paintEvent(QPaintEvent *);


     Combine *combine1 =NULL;
      Combine2 *combine2 =NULL;
    //  传送数据函数
    void Pass();
    //  转换还款类型
    void turn1();
    void turn2();
   //  设置贷款利率
    void change();
private:
    Ui::Getinformation3 *ui;
};

#endif // GETINFORMATION3_H
