#include <iostream>
#include "Rect.h"
using namespace std;

int main() {
    cout << "포인트 두 개 만들기" << endl;
    Point p1(10, 20);
    Point p2(30, 40);
    
    cout << "r1 객체 만들기 시작..." << endl;
    Rect r1(p1, p2);
    r1.Print();
    
    cout << "r2 객체 만들기 시작..." << endl;
    Rect r2(100, 200, 300, 400);
    r2.Print();
    
    Rect r3;
    r3.Print();

    Rect r4(r2);
    r4.Print();

    return 0;
}
