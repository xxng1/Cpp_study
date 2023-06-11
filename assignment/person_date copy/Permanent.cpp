#include "Permanent.h"

Permanent::Permanent(string name, double salary) : Employee(name), salary(salary) {}

double Permanent::GetPay() {
    return salary;
}

double Permanent::GetSalary() {
    return salary;
}

void Permanent::SetSalary(double salary) {
    this->salary = salary;
}