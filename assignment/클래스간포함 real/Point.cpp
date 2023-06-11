#include "Point.h"
#include <iostream>
using namespace std;

Point::Point() : x(0), y(0) {
    cout << "point 매개변수 없는 생성자" << endl;
}

Point::Point(int initialX, int initialY) : x(initialX), y(initialY) {
    cout << "point 매개변수 있는 생성자" << endl;
}

Point::Point(const Point& pt) : x(pt.x), y(pt.y) {
    cout << "point 복사 생성자" << endl;
}

Point::~Point() {
    cout << "point 소멸자" << endl;
}

void Point::SetX(int value) {
    x = value;
}

void Point::SetY(int value) {
    y = value;
}

int Point::GetX() const {
    return x;
}

int Point::GetY() const {
    return y;
}

void Point::Print() const {
    cout << "Point(" << x << ", " << y << ")" << endl;
}
