#include "Temporary.h"

Temporary::Temporary(string name, int hours, double hourlyWage) : Employee(name), hours(hours), hourlyWage(hourlyWage) {}

double Temporary::GetPay() {
    return hours * hourlyWage;
}

int Temporary::GetHours() {
    return hours;
}

void Temporary::SetHours(int hours) {
    this->hours = hours;
}

double Temporary::GetHourlyWage() {
    return hourlyWage;
}

void Temporary::SetHourlyWage(double hourlyWage) {
    this->hourlyWage = hourlyWage;
}
