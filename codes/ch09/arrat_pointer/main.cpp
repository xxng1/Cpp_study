#include <iostream>
using namespace std;

int main(){
    int a = 67;
    int* p = &a;
    *p = 3;
    int b = 13;
    int c = 13;
    
    cout << *p << endl;
    cout << a << endl;
    cout << &p << endl;
    cout << &a << endl;
    cout << &b << endl;
    cout << &c << endl;

    cout << sizeof(double) << endl;
}