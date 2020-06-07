#ifndef COMBINE_H
#define COMBINE_H

#include <QMainWindow>

namespace Ui {
class Combine;
}

class Combine: public QMainWindow
{
    Q_OBJECT

public:
     explicit Combine(QWidget *parent = nullptr);
     ~Combine();
      void paintEvent(QPaintEvent *);
      void  pass();  //传递参数
      void calculate(double Loan1,double Loan2,int period);
      double Loan1;    // 商业贷款额
      double Loan2;    // 公积金贷款额
      int period;        //按揭年数
private:
    Ui::Combine *ui;
    double rate1=0.0275/12;     //利率1
    double rate2=0.0325/12;     //利率2
    double totalloans;           //  贷款总额
    double monthsupply;         //月供
    double sumpaybacks;         //还款总额
    double sumrates;            // 支付总利息
    int month;                    // 还款月数
};

#endif // COMBINE_H
