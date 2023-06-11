// 201835656_박상웅
#include <iostream>
using namespace std;

void addMul(int num1, int num2, int& add, int& mul);
void addMul(int num1, int num2, int* add, int* mul);

int main(){
    int x, y;
    int result1, result2;
    cout << "두 수를 입력하세요: ";
    cin >> x >> y;
    
    addMul(x, y, result1, result2);
    cout << "pass_by_reference" << endl;
    cout << "두 수의 합: " << result1 << endl;
    cout << "두 수의 곱: " << result2 << endl;
    cout << "현재 두 결과 [ result1: " << result1 << ", result2: " << result2 << " ]" << endl;

    cout << "pass_by_pointer" << endl;
    addMul(x, y, &result1, &result2);
    cout << "두 수의 합: " << result1 << endl;
    cout << "두 수의 곱: " << result2 << endl;
    cout << "현재 두 결과 [ result1: " << result1 << ", result2: " << result2 << " ]" << endl;
    
}

void addMul(int num1, int num2, int& add, int& mul){
    add = num1 + num2;
    mul = num1 * num2;
}

void addMul(int num1, int num2, int* add, int* mul){
    *add = num1 + num2;
    *mul = num1 * num2;
}