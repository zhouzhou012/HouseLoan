#ifndef COMMERCIAL2_H
#define COMMERCIAL2_H

#include <QMainWindow>

namespace Ui {
class Commercial2;
}

class Commercial2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Commercial2(QWidget *parent = nullptr);
    ~Commercial2();
    float unit_price, area,  percentage1;
    int period;       // 传参中间接收者
    void calculate(double unit_price, double area,int period, float percentage1);     // 计算及显示结果
    void  pass();      //传递参数
    void paintEvent(QPaintEvent *);
private:
    double rate1=0.0405/12;    //月利率1
    double rate2=0.0475/12;    // 月利率2
    double rate3=0.0275/12;    //月利率3
    double rate4=0.0325/12;    // 月利率4
    double sumprice;           //  总价
    double payment;            // 首付
    double totalloans;          //  贷款总额
    double fmonthsupply;         //首月月供
    double smonthsupply;         //次月月供
    double cha;                      // 每月递减
    double sumpaybacks;         //还款总额
    double sumrates;            // 支付总利息
    int month;                      // 还款月数
    Ui::Commercial2 *ui;
};

#endif // COMMERCIAL2_H
