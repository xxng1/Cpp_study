//201835656 박상웅
#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 20;
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

class Person {
private:
    char* name;
    char* phone;
    int age;
public:
    Person();
    Person(char* _name, char* _phone, int _age);
    Person(const Person& p);
    ~Person();
    void ShowData();
};
Person::Person(){
    name = new char[MAX];
    phone = new char[MAX];
    strcpy_s(name, MAX, "");
    strcpy_s(phone, MAX, "");
    age = 0;
    cout << "매개변수 없는 생성자" << endl;
}
Person::Person(char* _name, char* _phone, int _age){
    name = new char[MAX];
    phone = new char[MAX];
    strcpy_s(name, MAX, _name);
    strcpy_s(phone, MAX, _phone);
    age = _age;
    cout << "매개변수 있는 생성자" << endl;
}
Person::Person(const Person& p) {
    name = new char[MAX];
    phone = new char[MAX];
    strcpy_s(name, MAX, p.name);
    strcpy_s(phone, MAX, p.phone);
    age = p.age;
    cout << "깊은 복사생성자" << endl;
}
Person::~Person() {
    delete[] name; name = NULL;
    delete[] phone; phone = NULL;
    cout << "소멸자 실행" << endl;
}
void Person::ShowData(){
    cout <<"name: " << this->name << endl;
    cout <<"phone: " << this->phone << endl;
    cout <<"age: " << this->age << endl;
}

int main() {
    Person Bobby;
    Bobby.ShowData();
    Person p1("KIM", "013-333-5555", 22);
    p1.ShowData ();
    Person p2(p1);
    p2.ShowData ();

    return 0;
}
