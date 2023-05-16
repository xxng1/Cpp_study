#include <iostream>
using namespace std;

int main(){
	int k = 1000;
	int* pk = &k;
	int** ppk = &pk;

	cout << "k = " << k << " &k = " << &k << endl;
	cout << "pk = " << pk << " &pk = " << &pk << " *pk = " << *pk << endl;
	cout << "ppk = " << ppk << " &ppk = " << &ppk << " *ppk = " << *ppk << " **ppk = " << **ppk << endl;
	//pointer array
	double* D[5]; // Circle* D[5]; -> 요소 하나하나가 포인터 // 클래스명의 시작부분

}