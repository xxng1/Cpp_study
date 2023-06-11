#ifndef SALES_H
#define SALES_H

#include "Employee.h"

class Sales : public Employee {
private:
    double basePay;
    double salesRevenue;

public:
    Sales(string name, double basePay, double salesRevenue);
    double GetPay() override;
    double GetBasePay();
    void SetBasePay(double basePay);
    double GetSalesRevenue();
    void SetSalesRevenue(double salesRevenue);
};

#endif
