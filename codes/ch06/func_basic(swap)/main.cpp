#include <iostream>
using namespace std;

void func(int y, int& z);

//매개변수의 스택메모리 삽입은 오른쪽 변수부터

void swap_pass_by_value(int i, int j);
void swap_pass_by_reference(int& rI, int& rJ);
void func(int y, int &z, int*p){
    y++;
    z = 5000;
    *p = -800;
}
void swap_pass_by_pointer(int* pi, int* pj){
    int tmp = *pi;
    *pi = *pj;
    *pj = tmp;
    cout << *pi << ' ' << *pj << endl;   
}

int main(){
    /*basic
    int x = 10;
    int a = 5;
    func(x, a);
    cout << "x : " << x << endl; // 안바뀜
    cout << "a : " << a << endl; // 바뀜
*/
    
    int q = 10;
    int w = 20;

    cout << q << ' ' << w << endl; //출력1

    swap_pass_by_value(q,w); //출력2
    cout << q << ' ' << w << endl; //출력3

    swap_pass_by_reference(q,w); //출력4
    cout << q << ' ' << w << endl; //출력5

    int* pI = &q;
    int* pJ = &w;
    swap_pass_by_pointer(pI, pJ); // 출력6
    cout << q << ' ' << w << endl; // 출력7

    int x = 10, a = 5, n = 8;
    func(x,a,&n);
    cout << x << ' ' << a << ' ' << n << endl;

    return 0;
}

void func(int y, int& z){ // 지역변수 => stack memory 에서 push -> pop
    y++;
    z++;
    cout << "y : " << y << endl;
    cout << "z : " << z << endl;
}

void swap_pass_by_value(int i, int j){
    int tmp;
    tmp = i;
    i = j;
    j = tmp;
    cout << i << ' ' << j << endl;
}
void swap_pass_by_reference(int& rI, int& rJ){
    int tmp;
    tmp = rI;
    rI = rJ;
    rJ = tmp;
    cout << rI << ' ' << rJ << endl;
}