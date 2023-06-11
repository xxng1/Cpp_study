#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
private:
    string name;

public:
    Employee(string name);
    double GetPay();
    string GetName();
    void SetName(string name);
};

#endif