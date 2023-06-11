#ifndef PERMANENT_H
#define PERMANENT_H

#include "Employee.h"

class Permanent : public Employee {
private:
    double salary;

public:
    Permanent(string name, double salary);
    double GetPay() override;
    double GetSalary();
    void SetSalary(double salary);
};

#endif