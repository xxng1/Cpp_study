#include <iostream>
using namespace std;
const int DEFAULT_ARRAY_SIZE = 4;
class DA{
public:
    int* arr;
    int size;
public:
    DA();
    DA(int s);
    DA(const DA& d);
    ~DA();
    DA& operator = (const DA& other); // 깊은 대입 연산자 overloading, return by reference
};
DA::DA(){
    this->size = DEFAULT_ARRAY_SIZE;
    arr = new int(this->size);
    for(int i=0; i<this->size; i++){
        arr[i] = 0;
    }
    cout << "con(structor) without parameter" << endl;
}
DA::DA(int s){
    this->size = s;
    arr = new int(this->size);
    for(int i=0; i<this->size; i++){
        arr[i] = 0;
    }
    cout << "con(structor) with parameter" << endl;
}
DA::DA(const DA& d){
    this->size = d.size;
    arr = new int(this->size);
    for(int i=0; i<this->size; i++){
        arr[i] = d.arr[i];
    }
    cout << "deep copy con(structor)" << endl;
}
DA::~DA(){
    if(arr){ // arr != NULL;
        delete[] arr; arr = NULL;
    }
    cout << "decon(structor)" << endl;
}
DA&::DA operator = (const DA& other){
    if(this != &other){
        delete[] arr;
        arr = new int[other.size];
        sisze = other.size;
        for(int i=0; i<size; i++){
            arr[i] = other.arr[i];
        }
    }
    return *this;
}
int func1(DA d);
int func2(DA& d);
int main(){
    // DA obj3(10);
    // cout << "pass-by-value" << endl;
    // int m = func1(obj3);
    // cout << m << endl;

    // cout << "pass-by-reference" << endl;
    // int k = func2(obj3);
    // cout << k << endl;
    
    cout << "-----------------------------" << endl;
    cout << "몇 개의 정수를 입력하시겠소?: ";
    int n;
    cin >> n;
    DA obj1(n);
    for (int i=0; i<n; i++){
        cout << "입력 ";
        cin >> obj1.arr[i];
    }
    cout << "역순으로 출력" << endl;
    for(int i=n-1; i>=0; i--){
        cout << obj1.arr[i] << ' '; //kind of getter
    }
    cout << endl;
    //deep copy con
    DA obj2(obj1);
    cout << "obj2 출력" << endl;
    for( int i=0; i<obj2.size; i++){
        cout << obj2.arr[i] << ' ';
    }
    cout << endl;

    DA obj4(10);
    for (int i=0; i<10; i++){
        cout << "입력 ";
        cin >> obj4.arr[i]; // kind of setter needed
    }
    obj2 = obj4; // obj2.operator = obj4 ;


    return 0;
}
int func1(DA d){
    cout << "in func1()" << endl;
    return d.size;
}

int func2(DA& d){
    cout << "in func2()" << endl;
    return d.size;
}