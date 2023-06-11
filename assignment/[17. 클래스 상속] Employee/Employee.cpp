#include "Employee.h"
using namespace std;

Employee::Employee(string name) : name(name) {}

double Employee::GetPay() {
    return 0;
}

string Employee::GetName() {
    return name;
}

void Employee::SetName(string name) {
    this->name = name;
}