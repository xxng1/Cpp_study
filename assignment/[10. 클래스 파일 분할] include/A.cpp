#include <iostream>
#include "A.h"
#include "B.h"
using namespace std;

void A::A1() {
    cout << "in A1()" << endl;
    B b;
    b.B1();
    b.B2();
}
void A::A2() {
    cout << "in A2()" << endl;
}
void A::A3() {
    cout << "in A3()" << endl;
}