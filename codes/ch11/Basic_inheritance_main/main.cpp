#include <iostream>
#include <string>
using namespace std;

class AAA{
private: int pri;
protected: int pro;
public: int pub;
public:
    AAA();
    AAA(int a, int b, int c);
    ~AAA();
};

AAA::AAA(){
    pri = 0; pro = 0; pub = 0;
    cout << "AAA con w/o parameters" << endl;
}
AAA::AAA(int a, int b, int c){
    pri = c; pro = b; pub = c;
    cout << "AAA con with parameters" << endl;
}
AAA::~AAA(){
    cout << "AAA decon" << endl;
}
class BBB : public AAA{
private:
    int b;
    string name;
public:
    BBB();
    BBB(int bval, string s);
    ~BBB();
    void Print();
    void SetData();
};
BBB::BBB(){
    b = 0; name[0] = '\0';
    cout << "BBB con w/o parameters" << endl;
}
BBB::BBB(int bval, string s){
    b = bval; name = s;
    cout << "BBB con with parameters" << endl;
}
BBB::~BBB(){
    cout << "BBB decon" << endl;
}
void BBB::Print(){
    cout << "BBB print() b:" << b << " name: " << name << endl;
    cout << "pro: " << pro << " pub: " << pub << endl;
}
void BBB::SetData(){
    pro = 6; pub = 7;
}

int main(){
    cout << "sizeof(AAA): " << sizeof(AAA) << endl;
    cout << "sizeof(BBB): " << sizeof(BBB) << endl;

    AAA a;
    a.pub = 1000;
    BBB b(100, "jeffery");
    cout << "sizeof(b): " << sizeof(b) << endl;
    b.pub = 200;
    b.Print();
    b.SetData();
    b.Print();
    return 0;

}