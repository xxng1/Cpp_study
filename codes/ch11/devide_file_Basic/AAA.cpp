#include "AAA.h"
#include <iostream>

using namespace std;

AAA::AAA(){
    pri = 0; pro = 0; pub = 0;
    cout << "AAA con w/o parameters" << endl;
}
AAA::AAA(int a, int b, int c){
    pri = c; pro = b; pub = c;
    cout << "AAA con with parameters" << endl;
}
AAA::~AAA(){
    cout << "AAA decon" << endl;
}