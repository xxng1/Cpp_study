#include <iostream>
using namespace std;

int main(){
    char pw[100] = {'C',' ','+','+'};
    char ans[100];
    bool check = false;

    while(true){
        cout << "암호를 입력하세요: ";
        cin.getline(ans,100);

        if(strlen(ans) == 0){
            cout << "입력중지. 프로그램을 정상 종료합니다." << endl;
            break;
        }

        for(int i=0; i<4; i++){
            if(pw[i]!=ans[i] || strlen(ans)!=4){
                cout << "암호가 틀립니다~~" << endl;
                check = false;
                break;
            }
            else{
                check = true;
            }
        }

        if(check == true){
            cout << "password is correct. 프로그램을 정상 종료합니다." << endl;
            break;
        }
    }
    return 0;
}