#include <iostream>
#include <cstring>

using namespace std;

char* reverse_str(char* org, int len){ // dynamic
    char* r = new char[len+1]; 
    for(int i =0; i<len; i++){
        r[i] = org[len-i-1];
    }
    r[len] = '\0';
    return r;
}

char* reverse_str_static(char* org, int len){ // static -> 이렇게 하면 안됨 ! 배열에선 항상 dynamic..
    char A[10] = {0,};
    for(int i =0; i<len; i++){
        A[i] = org[len-i-1];
    }
    A[len] = '\0';
    return A;
}

int main(){
    char org[] = "abcde"; // len = 5, size = 6
    int len = strlen(org);

    char* rev = reverse_str(org, len);

    for(int i=0; i<len; i++){
        cout << rev[i] << endl;
    }

    // rev = reverse_str_static(org, len);
    cout << len << endl;

    for(int i=0; i<len; i++){
        cout << rev[i] << endl;
    }

    delete[] rev; rev = NULL; // 필수

    for(int i=0; i<len; i++){
        cout << rev[i] << endl;
    }
    cout << "----" << endl;
    cout << rev << endl;
    cout << *(rev+2) << endl;


    //reverse string main에서 만들어보자
    // char* rev = new char[len+1];
    // //문자열을 역순으로 복사한다.
    // for(int i =0; i<len; ++i){
    //     rev[i] = org[len-i-1];
    // }
    // rev[len] = '\0';
    // cout << org[5] << endl;
    // cout << len << endl;

    // for(int i=0; i<len; ++i){
    //     cout << rev[i] << endl;
    // }
    return 0;
}