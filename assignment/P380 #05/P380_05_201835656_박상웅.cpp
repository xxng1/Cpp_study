#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int findMin(int* arr, int size);
int findMax(int* arr, int size);
void removeElement(int A[], int a, int& arrSize);

int main(){
    int size = 10;
    int arrA[10];
    srand((unsigned int)time(NULL));

    for(int i=0; i<size; i++){
        arrA[i] = rand()%100 + 1;
    }

    cout << "Original Array: " << endl;
    for(int i=0; i<size; i++){
        cout << arrA[i] << ' ';
    }

    removeElement(arrA, findMin(arrA, size), size);
    removeElement(arrA, findMax(arrA, size), size);
    
    cout << endl << "Resulting array: " << endl;
    for(int i=0; i<size; i++){
        cout << arrA[i] << ' ';
    }
    cout << endl;
    return 0;
}

int findMin(int* arr, int size){
    int min = *arr;
    for(int i=0; i<size; i++){
        if(min > arr[i]){
            min = *(arr+i);
        }
    }
    return min;
}

int findMax(int* arr, int size){
    int max = *arr;
    for(int i=0; i<size; i++){
        if(max < arr[i]){
            max = *(arr+i);
        }
    }
    return max;
}

void removeElement(int A[], int a, int& arrSize){
    int index;
    for(int i=0; i<arrSize; i++){
        if(A[i] == a){
            index=i;
            break;
        }
    }
    for(int i=index; i<arrSize; i++){
        A[i] = A[i+1];
    }
    arrSize--;
}