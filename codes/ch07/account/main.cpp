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

class Account{
private:
    int id;
    int balance; // 잔고
    char *name; // rule3
public:
    //생성자(3)
    Account();
    Account(int i, int b, const char* n);
    Account(const Account& aobj);

    Account&  operator=(const Account & other);
    //소멸자(1)
    ~Account();
    //get set	
    int getid();
    void setid(const int i);
    int getbalance();
    void setbalance(const int b);
    char* getname();
    void setname(const char* i);
    //in out
    void inMoney(int val); // val 만큼 입금
    void outMoney(int val); // val 만큼 출금
    // ShowAllData(), OutMoney(bool)
    void ShowAllData() const;
};

Account::Account(){
    cout << "매개변수 없는 생성자" << endl;
    id = 0;
    balance = 0;
    name[0] = '\0';
};
Account::Account(int i, int b, const char* n){
    cout << "매개변수 있는 생성자" << endl;
    id = i;
    balance = b;
    strcpy_s(name, MAX, n);
};
Account::Account(const Account& aobj){
    cout << "복사 생성자" << endl;
    id = aobj.id;
    balance = aobj.balance;
    strcpy_s(name, MAX, aobj.name);
};
Account::~Account(){
    cout << "소멸자" << endl;
};
Account& Account::operator=(const Account & other){
    if (this != &other) {
        delete[] name;
        name = new char[MAX];
        id = other.id;
        balance = other.balance;
    }
    cout << "깊은 대입 연산자" << endl;
    return *this;
}
//get set
int Account::getid(){
    return id;
};
void Account::setid(const int i){
    id = i;
};
int Account::getbalance(){
    return balance;
};
void Account::setbalance(const int b){
    balance = b;
};
char* Account::getname(){
    return name;
};
void Account::setname(const char* i){
    strcpy_s(name, MAX, i);
};
void Account::inMoney(int val){
    balance += val;
};
void Account::outMoney(int val){
    balance -= val;
};
void Account::ShowAllData() const {
    cout << "id: "<< id << endl;
    cout << "balance: "<< balance << endl;
    cout << "name: "<< name << endl;
}
int main(){
    Account test1;
    Account test2(123,100000,"park");

    cout << test2.getid() << endl;
    cout << test2.getbalance() << endl;
    cout << test2.getname() << endl;
    test2.setid(2);
    test2.setbalance(10000000);
    test2.setname("kim");
    cout << test2.getid() << endl;
    cout << test2.getbalance() << endl;
    cout << test2.getname() << endl;
    test2.inMoney(30);
    cout << test2.getbalance() << endl;
    test2.outMoney(1);
    cout << test2.getbalance() << endl;
    cout << " --- " << endl;
    test2.ShowAllData();
    test2 = test1;
    test1.ShowAllData();
}