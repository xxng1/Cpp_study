#include "Sales.h"

Sales::Sales(string name, double basePay, double salesRevenue) : Employee(name), basePay(basePay), salesRevenue(salesRevenue) {}

double Sales::GetPay() {
    return basePay + (0.1 * salesRevenue);
}

double Sales::GetBasePay() {
    return basePay;
}

void Sales::SetBasePay(double basePay) {
    this->basePay = basePay;
}

double Sales::GetSalesRevenue() {
    return salesRevenue;
}

void Sales::SetSalesRevenue(double salesRevenue) {
    this->salesRevenue = salesRevenue;
}