#ifndef COMBINE2_H
#define COMBINE2_H

#include <QMainWindow>

namespace Ui {
class Combine2;
}

class Combine2 : public QMainWindow
{
    Q_OBJECT

public:
     explicit Combine2(QWidget *parent = nullptr);
     ~Combine2();
     void paintEvent(QPaintEvent *);
     void  pass();  //传递参数
     void calculate(double Loan1,double Loan2,int period);
     double Loan1;
     double Loan2;
     int period;

private:
    Ui::Combine2 *ui;
    double rate1=0.0275/12;
    double rate2=0.0325/12;
    long long totalloans;            //  贷款总额
    long long fmonthsupply;         //首月月供
    long  long smonthsupply;      //次月月供
    float cha;                             //每月递减
    long long sumpaybacks;         //还款总额
    long long sumrates;            // 支付总利息
    int month;                         // 还款月数
};

#endif // COMBINE2_H
