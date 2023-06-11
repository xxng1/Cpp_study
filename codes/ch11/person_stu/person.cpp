#include "person.h"
#include <iostream>
#include <cassert>
using namespace std;

Person::Person() {
    cout << "person 매개변수 없는 생성자" << endl;
    identity = 0;
    Date defaultDate;
    birthDate = defaultDate;
}

Person::Person(long id, const Date& bd) : birthDate(bd) {
    cout << "person 매개변수 있는 생성자" << endl;
    identity = id;
    assert(identity > 111111111 && identity < 999999999);
}

Person::Person(const Person& other) {
    cout << "person 복사 생성자" << endl;
    identity = other.identity;
    birthDate = other.birthDate;
}

Person::~Person() {
    cout << "person 소멸자" << endl;
}

void Person::print() const {
    cout << "Person Identity: " << identity << endl;
    cout << "Person date of birth: ";
    birthDate.print();
    cout << endl << endl;
}
