#include <iostream>
#include <string>
using namespace std;
int main(){
    // string strg1; // 매개변수 없는 생성자
    // if(strg1.empty() == true){
    //     cout << "strg1 is empty" << endl;
    // }
    // else{
    //     cout << "strg1 is not empty" << endl;
    // }
    // string strg2("Hello"); // 매개변수 있는 생성자
    // string strg3 = "Hello everybody"; // 매개변수 있는 생성자
    // string strg4(strg2); // 복사 생성자
    // //copy
    // strg1 = strg3;
    // if(strg1.empty() == true){
    //     cout << "strg1 is empty" << endl;
    // }
    // else{
    //     cout << "strg1 is not empty" << endl;
    // }
    // cout << "strg1: " << strg1 << endl;
    // cout << "strg2: " << strg2 << endl;
    // cout << "strg3: " << strg3 << endl;
    // cout << "strg4: " << strg4 << endl;
    // // 문자열 비교 및 연결
    // string strg5 = "Alpha Go";
    // bool b = (strg5 == strg3);
    // cout << b << endl;
    // cout << boolalpha << b << endl; // 변수로 비교
    // char A[] = "Grace";
    // cout << "strg5 == A: " << boolalpha << (strg5 == A) << endl; // 바로 비교 가능

    // // 사용자에게 first_name, last_name, middle_name 따로따로 받아서 결합하여 출력하기
    // string first, last;
    // char init;
    // cout << "first_name: ";
    // cin >> first;
    // cout << "last_name: ";
    // cin >> last;
    // cout << "middle_name: ";
    // cin >> init;

    // cout << first << last << init << endl;

    // string orig = first + " " + init + ", " + last;
    // cout << "name: " << orig << endl;

    //string strg6;
    // cout << "문자열을 입력하세요: ";
    // cin >> strg6;
    // cin.clear();
    // cin.ignore(numeric_limits<streamsize>::max(),'\n');
    // cout << "strg6: " << strg6 << endl;
    // cout << "한줄을 입력하세요: ";
    // getline(cin, strg6, '\n'); // default == '\n'
    // cout << "strg6: " << strg6 << endl;
    // 한줄 입력 받아서 출력하기 until enter only
    // getline(cin, strg6, 'd');
    // cout << "strg6: " << strg6 << endl;
    //string strg7;

    // while(true){
    //     if(strg7.empty()){
    //         cout << "한줄을 입력하세요: ";
    //         getline(cin, strg7);
    //     }
    //     else{
    //         break;
    //     }
    // }    
    // cout << strg6;

    string str1 = "asd";
    getline(cin, str1);

    cout << str1 << endl;

    return 0;
}