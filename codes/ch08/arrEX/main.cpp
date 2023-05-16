#include <iostream>
using namespace std;

int main(){
	int A[8]; // int 포인터 함수 & 배열
	double B[6];

	cout << "sizeof(int): " << sizeof(int) << endl;
	cout << "sizeof(double): " << sizeof(double) << endl;
	cout << "sizeof(A): " << sizeof(A) << endl;
	cout << "sizeof(B): " << sizeof(B) << endl;
	cout << "sizeof(A[3]): " << sizeof(A[3]) << endl;

	return 0;
}