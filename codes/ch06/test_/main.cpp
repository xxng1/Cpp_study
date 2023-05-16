#include <iostream>
using namespace std;

int max(int num1, int num2);
int max(int num1, int num2, int num3);
int max(int num1, int num2, int num3, int num4);

int main(){
    cout << "max(5,7): " << max(5,7) << endl;
    cout << "max(5,7,4): " << max(15,7,9) << endl;
    cout << "max(5,7,4,33): " << max(15,7,9,33) << endl;
    return 0;
}

int max(int num1, int num2){
    return (num1 > num2) ? num1 : num2;
}
int max(int num1, int num2, int num3){
    int large = (num1 > num2) ? num1 : num2 ;
    return large > num3 ? large : num3 ;
}
int max(int num1, int num2, int num3, int num4){
    int _large = (num1 > num2) ? num1 : num2 ;
    int large = _large > num3 ? _large : num3;
    return  large > num4 ? large : num4;
}