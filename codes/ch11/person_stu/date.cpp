#include "date.h"
#include <iostream>
#include <cassert>
using namespace std;

Date::Date() {
    cout << "date 매개변수 없는 생성자" << endl;
    month = 1;
    day = 1;
    year = 1900;
}

Date::Date(int m, int d, int y) {
    cout << "date 매개변수 있는 생성자" << endl;
    month = m;
    day = d;
    year = y;

    if (month < 1 || month > 12) {
        cout << "Month is out of range. ";
        assert(false);
    }

    int daysInMonths[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day < 1 || day > daysInMonths[month]) {
        cout << "Day out of range! ";
        assert(false);
    }

    if (year < 1900 || year > 2099) {
        cout << "Year out of range! ";
        assert(false);
    }
}

Date::Date(const Date& other) {
    cout << "date 복사 생성자" << endl;
    month = other.month;
    day = other.day;
    year = other.year;
}

Date::~Date() {
    cout << "date 소멸자" << endl;
}

void Date::print() const {
    cout << month << "/" << day << "/" << year << endl;
}