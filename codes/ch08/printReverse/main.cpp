#include <iostream>
using namespace std;

int funcMin(int B[], int size);
int funcMin_ptr(int* B, int size);

int main(){
	int A[5] = {2,3,1,5,7};
	cout << funcMin(A, 5) << endl;
	return 0;
}

int funcMin(int B[], int size){
	int min = B[0];
	for(int i=0; i<size; i++){
		if(min > B[i]){
			min = B[i];
		}
	}
	return min;
}

int funcMin_ptr(int* B, int size){
	int min = *B;
	for(int i=0; i<size; i++){
		if(min > *(B+i)){
			min = *(B+i);
		}
	}
	return min;
}