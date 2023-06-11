#ifndef TEMPORARY_H
#define TEMPORARY_H

#include "Employee.h"

class Temporary : public Employee {
private:
    int hours;
    double hourlyWage;

public:
    Temporary(string name, int hours, double hourlyWage);
    double GetPay() override;
    int GetHours();
    void SetHours(int hours);
    double GetHourlyWage();
    void SetHourlyWage(double hourlyWage);
};

#endif
