//201835656 박상웅
#include <iostream>
using namespace std;

const int DEFAULT_ARRAY_SIZE = 4;

class DA {
private:
    int* arr;
    int size;
public:
    DA();
    DA(int s);
    DA(const DA& d);
    ~DA();
    // getter&setter
    int getArr(int index) { return arr[index]; }
    void setArr(int index, int val) { arr[index] = val; }
    int getSize() { return size; }
};

DA::DA() {
    this->size = DEFAULT_ARRAY_SIZE;
    arr = new int[this->size];
    for(int i=0; i<this->size; i++){
        arr[i] = 0;
    }
    cout << "con(structor) without parameter" << endl;
}

DA::DA(int s) {
    this->size = s;
    arr = new int[this->size];
    for(int i=0; i<this->size; i++){
        arr[i] = 0;
    }
    cout << "con(structor) with parameter" << endl;
}

DA::DA(const DA& d) {
    this->size = d.size;
    arr = new int[this->size];
    for(int i=0; i<this->size; i++){
        arr[i] = d.arr[i];
    }
    cout << "deep copy con(structor)" << endl;
}

DA::~DA() {
    if(arr){ // arr != NULL;
        delete[] arr; arr = NULL;
    }
    cout << "decon(structor)" << endl;
}

int main() {
    cout << "몇 개의 정수를 입력하시겠소?: ";
    int n;
    cin >> n;
    DA obj1(n);
    cout << "입력: ";
    for (int i=0; i<n; i++){
        int num;
        cin >> num;
        obj1.setArr(i, num);
    }

    cout << "배열의 2번째 인덱스 값: " << obj1.getArr(2) << endl;
    cout << "배열의 사이즈: " << obj1.getSize() << endl;
    obj1.setArr(0,0); // 배열의 0번째 인덱스값 지정
    
    cout << "역순으로 출력" << endl;
    for(int i=n-1; i>=0; i--){
        cout << obj1.getArr(i) << ' '; //kind of getter
    }
    cout << endl;

    return 0;
}
