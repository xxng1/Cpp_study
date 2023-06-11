//201835656 박상웅

#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;
public:
    Person();
    Person(const string& name, int age);
    Person(const Person& p);
    ~Person();
    void setName(const string name);
    void setAge(int age);
    string getName() const;
    int getAge() const;
};
Person::Person(){
    name = " ";
    age = 0;
};
Person::Person(const string& name, int age) {
    this->name = name;
    this->age = age;
}
Person::Person(const Person& p){
    name = p.name;
    age = p.age;
};
Person::~Person() {}
void Person::setName(const string name) {
    this->name = name;
}
void Person::setAge(int age) {
    this->age = age;
}
string Person::getName() const {
    return name;
}
int Person::getAge() const {
    return age;
}
int main() {
    Person p1;
    Person p2("woong", 26);
    Person p3(p2);

    cout << "p1 Name: " << p1.getName() << endl;
    cout << "p1 Age: " << p1.getAge() << endl;
    cout << "p2 Name: " << p2.getName() << endl;
    cout << "p2 Age: " << p2.getAge() << endl;
    cout << "p3 Name: " << p3.getName() << endl;
    cout << "p3 Age: " << p3.getAge() << endl;

    p1.setName("won");
    p1.setAge(25);

    cout << "p1 Name: " << p1.getName() << endl;
    cout << "p1 Age: " << p1.getAge() << endl;

    return 0;
}
