// 201835656 박상웅
#include <iostream>
using namespace std;

class One {
private:
    int x;
    int y;

public:
    One();
    One(int a, int b);
    One(const One& a);
    ~One();
    int getX() const;
    int getY() const;  
};
One::One() {
    x = 0;
    y = 0;
}
One::One(int a, int b){
    x = a;
    y = b;
}
One::One(const One& a){
    x = a.x;
    y = a.y;
}
One::~One(){}
int One::getX() const {
    return x;
}
int One::getY() const {
    return y;
}
int main() {
    One obj1;
    One obj2(2,3);
    One obj3(obj2);
    cout << "[obj1] x: " << obj1.getX() << ", y: " << obj1.getY() << endl;
    cout << "[obj2] x: " << obj2.getX() << ", y: " << obj2.getY() << endl;
    cout << "[obj3] x: " << obj3.getX() << ", y: " << obj3.getY() << endl;
    return 0;
}