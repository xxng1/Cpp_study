#include "BBB.h"
#include <iostream>

using namespace std;

int main(){
    cout << "sizeof(AAA): " << sizeof(AAA) << endl;
    cout << "sizeof(BBB): " << sizeof(BBB) << endl;

    AAA a;
    a.pub = 1000;
    BBB b(100, "jeffery");
    cout << "sizeof(b): " << sizeof(b) << endl;
    b.pub = 200;
    b.Print();
    b.SetData();
    b.Print();

    return 0;
}