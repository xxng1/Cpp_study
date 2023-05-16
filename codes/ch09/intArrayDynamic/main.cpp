#include <iostream>
using namespace std;

void func(int* A, int size){
    int sum = 0;
    for(int i=0; i<size; i++){
        sum += *(A+i);
   }
   cout << "합은: " << sum << endl;
   float avg = float(sum) / (float)size;
   cout << "평균은: " << avg << endl;
}

int funct(int* A, int size){
    int sum = 0;
    for(int i=0; i<size; i++){
        sum += *(A+i);
   }
   cout << "합은: " << sum << endl;
   float avg = float(sum) / (float)size;
   cout << "평균은: " << avg << endl;
   return 0;
}

int funcreturn(int num){
    int* arr = new int[num];
    return *arr;
}

int main(){
    /** test
    int* p = new int;
    int size = 10;
    int* A = new int[size];
    
    cout << A[2] << endl;
    *p = 50;
    cout << *p << endl;


    delete A;
    delete p;
    **/
   cout << "몇 개의 정수를 입력 하겠소?: ";
   int size;
   cin >> size;
   
   int* ip = new int[size]; // dynamic memory allocation

   cout << "정수를 입력하시오" << endl;
   for(int i=0; i<size; i++){
        cin >> *(ip + i);
   }

    
   cout << "정수를 입력하시오" << endl;
   for(int i=0; i<size; i++){
        cin >> *(ip + i);
   }

   func(ip, size);
   funct(ip, size);
   

//    cout << "delete전 ip: " << ip << endl;
//    cout << "delete전 *ip: " << *ip << endl;
   delete[] ip;
//    cout << "delete후 ip: " << ip << endl;
//    cout << "delete후 *ip: " << *ip << endl;
   ip = NULL;
//    cout << "ip = NULL후 ip: " << ip << endl;
//    cout << "ip = NULL후 *ip: " << *ip << endl;

    return 0;
}