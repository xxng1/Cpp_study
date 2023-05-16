#include <iostream>
using namespace std;

void printarray(int* B, int size);
int main(){
    int A[10] = { -999 , 3, 5};
    cout << "sizeof(A) = " << sizeof(A) << endl << endl;
    int i = 10;
    int* q = &i;
    cout << "q: " << q << endl;
    cout << "++q: " << ++q << endl;
    q = &i;
    
    cout << "q: " << q << endl;
    cout << "q++: " << q++ << endl;
    cout << "q: " << q << endl;
    
    int* p = A;
    cout << *p << endl;
    cout << "---------------" << endl;
    // ①  배열명을 사용한 index표현, i로 대입
    // for(int i=0; i<10; i++){
    //     A[i] = i;
    // }
    // printarray(A,10);
    // cout << endl;
    // ②  배열명을 사용한 포인터표현, i*i로 대입


    // ③  배열명을 저장한 포인터변수를 사용한 포인터표현, i*i*i로 대입
    // for(int i=0; i<10; i++){
    //     A[i] = i*i*i;
    // }
    // printarray(A,10);
    // cout << endl;
    // ③-1 배열명을 저장한 포인터변수를 사용한 포인터표현, i*i*i로 대입


    for(int i=0; i<10; i++){
        *p++=i;
        
    }
    printarray(A,10);
    cout << endl << p << endl;

    for(int i=0; i<10; i++){
        *++p=i;   
    }
    printarray(A,10); // 배열이 corrupted 되었다.
    cout << endl << p << endl;

    // ④  배열명을 저장한 포인터변수를 사용한 index표현 , i*i*i*i로 대입
    // for(int i=0; i<10; i++){
    //     A[i] = i*i*i*i;
    // }
    // printarray(A,10);
    // cout << endl;
 


    return 0;    
}

void printarray(int* B, int size){
    for(int i=0; i<size; i++){
        cout << *(B+i) << ' ';
    }
}