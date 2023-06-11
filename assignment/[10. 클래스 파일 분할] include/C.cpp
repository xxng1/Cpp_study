#include <iostream>
#include "A.h"
#include "C.h"
using namespace std;

void C::C1() {
    cout << "in C1()" << endl;
    A a;
    a.A1();
    a.A2();
}
