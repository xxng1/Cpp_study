#include <iostream>
#include "A.h"
#include "B.h"
using namespace std;

void B::B1() {
    cout << "in B1()" << endl;
}

void B::B2() {
    cout << "in B2()" << endl;
    A a;
    a.A2();
    B1();
}