//20183556 박상웅
#include <iostream>
using namespace std;

char* shiftRightString(char* orig, int len);

int main(){
    char A[13] = {'B','I','N','G','O','_','J','J','A','N','G','!','!'};
    char* ptr = A;

    for(int i=0; i<strlen(A); i++){ // 현재 문자열 출력
        cout << *(ptr+i) << ' ';
    }
    cout << endl;

    for(int count = 0; count<strlen(A); count++){ // 문자열 길이만큼 반복
        shiftRightString(ptr, strlen(A)); // 함수 실행
        for(int i=0; i<strlen(A); i++){
            cout << *(ptr+i) << ' ';
        }
        cout << endl;
    }
    return 0;
}

char* shiftRightString(char* orig, int len){
    char tmp;
    tmp = *(orig+len-1);
    for(int i=len-1; i>=0; i--){
        *(orig+i) = *(orig+i-1); // 문자열 위치 변경
    }
    *(orig) = tmp;
    return orig;
}