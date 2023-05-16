#include <iostream>
using namespace std;
class WhoAmI{
private:
    int id;
public:
    WhoAmI();
    WhoAmI(int value);
    
    void showYourSelf();
};
WhoAmI::WhoAmI(){
    id = 0;
}
WhoAmI::WhoAmI(int value){
    id = value;  
}
//인스턴스 멤버함수
void WhoAmI::showYourSelf(){ // WhoAmI* this
// 정적 멤버함수에서는 정적데이터만 접근가능
    cout << "this->id: " << this->id << " , this: " << this << endl;
}



int main(){
    WhoAmI obj;
    WhoAmI obj1(1);
    WhoAmI obj2(2);
    WhoAmI obj3(3);
    cout << "&obj1: " << &obj1 << endl;
    cout << "&obj2: " << &obj2 << endl;
    cout << "&obj3: " << &obj3 << endl;
    obj1.showYourSelf();
    obj2.showYourSelf();
    obj3.showYourSelf();
    cout << sizeof(WhoAmI) << endl;

    return 0;
}