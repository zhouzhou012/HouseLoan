#include"commercial1.h"
#include "ui_commercial1.h"
int main()
{
    extern float price;
    extern float space;
    extern float percentage;
    extern int year;
    Commercial1 c;
    c.calculate(price, space,year, percentage);
    c. getpayment();
    c. gettotalloans();
    c. getmonthsupply();
    c.getsumpaybacks();
    c. getsumrates();
    c. getmonth();
}
