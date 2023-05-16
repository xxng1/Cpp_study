//201835656 박상웅
#include <iostream>
using namespace std;

class Two {
private:
    int x;
    char a;
public:
    Two();
    Two(int testx, char testa);
    Two(const Two& t);
    ~Two();
    void setX(int value);
    void setA(char value);
    int getX() const;
    char getA() const;
};
Two::Two() {
    x = 0;
    a = ' ';
}
Two::Two(int testx, char testa){
    x = testx;
    a = testa;
}
Two::Two(const Two& t){
    x = t.x;
    a = t.a;
}
Two::~Two(){}
void Two::setX(int value) {
    x = value;
}
void Two::setA(char value) {
    a = value;
}
int Two::getX() const {
    return x;
}

char Two::getA() const {
    return a;
}

int main() {
    Two obj1;
    Two obj2(2,'F');
    Two obj3(obj2);
    cout << "[obj1] x: " << obj1.getX() << ", a: " << obj1.getA() << endl;
    cout << "[obj2] x: " << obj2.getX() << ", a: " << obj2.getA() << endl;
    cout << "[obj3] x: " << obj3.getX() << ", a: " << obj3.getA() << endl;
    return 0;
}