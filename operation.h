#ifndef OPERATION_H
#define OPERATION_H

#include <QObject>

class Operation
{
public:
    Operation();

    /**
     * 计算贷款每期需还多少
     * @param amount 贷款总额（万元）
     * @param period 期数，以月为单位
     * @param annualizedInterestRate 年化利率（%）
     * @param type 1表示等额本金，2表示等额本息
     */
    void calculate(double amount, int period, double annualizedInterestRate, int type);

private:
    void calEquPrincipal(double amount, int period, double monthlyInterestRate);
    void calEquPrincipalAndInterest(double amount, int period, double monthlyInterestRate);
};




#endif // OPERATION_H
