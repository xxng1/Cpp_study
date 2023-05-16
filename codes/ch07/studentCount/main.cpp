#include <iostream>
using namespace std;
void strcpy_s(char *dest, size_t destsz, const char *src)
{
    if (dest == nullptr || destsz == 0) {
        throw std::invalid_argument("Destination string is null or size is zero.");
    }
    size_t srclen = strlen(src);
    if (destsz <= srclen) {
        throw std::invalid_argument("Destination buffer is too small to copy the source string.");
    }
    strcpy(dest, src); 
}

const int MAX = 100;

class Student{
private:
    char name[MAX];
    int sNum;
public:
    //생성자&소멸자 + getter&setter
    Student();
    Student(const char* n, int s);
    Student(const Student& s);
    ~Student();
    char* getName();
    void setName(const char* n);
    int getNum();
    void setNum(int s);
private:
    static int cnt; // 생성자&소멸자에서 증감
public:
    static void printCount();
    //getter
    static int getCnt();
};
int Student::cnt = 0; // static 멤버 데이터 초기화

Student::Student(){
    cout << "매개변수가 없는 생성자 호출" << endl;
    name[0] = '\0';
    sNum = 0;
    cnt++;
};
Student::Student(const char* n, int s){
    cout << "매개변수가 있는 생성자 호출" << endl;
    strcpy_s(this->name, MAX, n);
    this->sNum = s;
    cnt++;
};
Student::Student(const Student& s){
    cout << "복사 생성자 호출" << endl;
    strcpy_s(this->name, MAX, s.name);
    this->sNum = s.sNum;
    cnt++;
};
Student::~Student(){
    cout << "소멸자 호출" << endl;
    cnt--;
};
char* Student::getName(){
    return this->name;
};
void Student::setName(const char* n){
    strcpy_s(name, MAX, n);
};
int Student::getNum(){
    return this->sNum;
};
void Student::setNum(int s){
    sNum = s;
};

void Student::printCount(){
    cout << "Student 객체 수: "<< cnt << endl;
};
int Student::getCnt(){
    return cnt;
};
//application start
void Func(); // 함수 선언 or prototype
int main(){
    Student::printCount();
    Student s1("Jeffrey", 123);
    Student::printCount();
    // s1.printCount(); 추천 X. 되도록이면 클래스명으로 호출하기
    cout << "-------------Func() call--------------" << endl;
    Func();
    cout << "-------------Func() call--------------" << endl;
    Student::printCount();
    Student s2("Heffrey", 134);
    Student::printCount();
    return 0;
}
void Func(){ // 함수 정의
    Student std1("Bill", 587);
    Student std2("James", 247);
    Student::printCount();
}