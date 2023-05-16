#include <iostream>
using namespace std;
const int MAX = 100;

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
void func();

class Student{
    private:
        char name[MAX];
        int sNo;
    public:
        Student();
        Student(const char* n, int s);
        Student(const Student& sobj);
        ~Student();
        char* getName();
        void setName(const char* n);
        int getSNo();
        void setSNO(int s);
};
Student::Student(){
    cout << "매개변수 없는 생성자" << endl;
    sNo = 0;
    name[0] = '\0';
};
Student::Student(const char* n, int s){
    cout << "매개변수 있는 생성자" << endl;
    sNo = s;
    strcpy_s(name,MAX,n);
};
Student::Student(const Student& sobj){
    cout << "복사 생성자" << endl;
    this->sNo = sobj.sNo;
    strcpy_s(name,MAX,sobj.name);
};
Student::~Student(){

};
char* Student::getName(){
    return name;
};
void Student::setName(const char* n){
    strcpy_s(name,MAX,n);
};
int Student::getSNo(){
    return sNo;
};
void Student::setSNO(int s){
    sNo = s;
};

int main(){
    Student std1;
    // Student std2("psw", 123);
    // Student std3(std1);
    cout << std1.getName() << endl;
    cout << "before func() call" << endl;
    func();
    cout << std1.getName() << endl;
    //Student std2("Heffrey",321);
    cout << "sizeof(std1): " << sizeof(std1) << endl;
    
    cout << "sizeof(Student): " << sizeof(Student) << endl;
    return 0;
}

void func(){
    Student std1("Bill", 342);
    std1.setName("William");
    cout << std1.getName() << endl;
    Student std2("James", 214);

}