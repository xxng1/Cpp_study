#include "Rect.h"
#include <iostream>
using namespace std;

Rect::Rect() {
    cout << "rect 매개변수 없는 생성자" << endl;
}

Rect::Rect(int x1, int y1, int x2, int y2) : topLeft(x1, y1), bottomRight(x2, y2) {
    cout << "rect매개변수 있는 생성자" << endl;
}

Rect::Rect(const Point& topLeft, const Point& bottomRight) : topLeft(topLeft), bottomRight(bottomRight) {
    cout << "rect복사 생성자" << endl;
}

Rect::~Rect() {
    cout << "rect 소멸자" << endl;
}

void Rect::SetTopLeft(const Point& pt) {
    topLeft = pt;
}

void Rect::SetBottomRight(const Point& pt) {
    bottomRight = pt;
}

Point Rect::GetTopLeft() const {
    return topLeft;
}

Point Rect::GetBottomRight() const {
    return bottomRight;
}

void Rect::Print() const {
    cout << "Top Left: ";
    topLeft.Print();
    cout << "Bottom Right: ";
    bottomRight.Print();
    cout << endl;
}
