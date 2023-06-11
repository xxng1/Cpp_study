#include "BBB.h"
#include <iostream>

using namespace std;

BBB::BBB(){
    b = 0; name[0] = '\0';
    cout << "BBB con w/o parameters" << endl;
}
BBB::BBB(int bval, string s){
    b = bval; name = s;
    cout << "BBB con with parameters" << endl;
}
BBB::~BBB(){
    cout << "BBB decon" << endl;
}
void BBB::Print(){
    cout << "BBB print() b:" << b << " name: " << name << endl;
    cout << "pro: " << pro << " pub: " << pub << endl;
}
void BBB::SetData(){
    pro = 6; pub = 7;
}