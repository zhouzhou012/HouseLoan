#ifndef CHOOSETYPE_H
#define CHOOSETYPE_H

#include <QMainWindow>
#include"getinformation1.h"
#include"getinformation3.h"
extern int variety;  //全局变量  贷款类型
namespace Ui {
class ChooseType;
}

class ChooseType : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChooseType(QWidget *parent = nullptr);
    ~ChooseType();
    void paintEvent(QPaintEvent *);

    GetInformation1  *information1=NULL;
    Getinformation3 *information3 =NULL;


    // 转换借贷类型
    void turn1();
    void turn2();
    void turn3();


private:
    Ui::ChooseType *ui;
};

#endif // CHOOSETYPE_H
