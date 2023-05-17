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
class Account {
private:
    int id;
    int balance;
    char* name;

public:
    Account();
    Account(int i, int b, const char* n);
    Account(const Account& aobj);
    ~Account();

    Account& operator=(const Account& other);

    int getid();
    void setid(const int i);
    int getbalance();
    void setbalance(const int b);
    const char* getname();
    void setname(const char* i);

    void inMoney(int val);
    bool outMoney(int val);
    void ShowAllData() const;
};
Account::Account() {
    cout << "매개변수 없는 생성자" << endl;
    id = 0;
    balance = 0;
    name = new char[MAX];
    name[0] = '\0';
}

Account::Account(int i, int b, const char* n) {
    cout << "매개변수 있는 생성자" << endl;
    id = i;
    balance = b;
    name = new char[MAX];
    strcpy_s(name, MAX, n);
}

Account::Account(const Account& aobj) {
    cout << "복사 생성자" << endl;
    id = aobj.id;
    balance = aobj.balance;
    name = new char[MAX];
    strcpy_s(name, MAX, aobj.name);
}

Account::~Account() {
    cout << "소멸자" << endl;
    delete[] name;
}

Account& Account::operator=(const Account& other) {
    if (this != &other) {
        delete[] name;
        name = new char[MAX];
        id = other.id;
        balance = other.balance;
        strcpy_s(name, MAX, other.name);
    }
    cout << "깊은 대입 연산자" << endl;
    return *this;
}

int Account::getid() {
    return id;
}

void Account::setid(const int i) {
    id = i;
}

int Account::getbalance() {
    return balance;
}

void Account::setbalance(const int b) {
    balance = b;
}

const char* Account::getname() {
    return name;
}
void Account::setname(const char* i) {
    strcpy_s(name, MAX, i);
}

void Account::inMoney(int val) {
    balance += val;
}

bool Account::outMoney(int val) {
    if (balance >= val) {
        balance -= val;
        return true; // 출금 성공
    } else {
        return false; // 출금 실패
    }
}

void Account::ShowAllData() const {
    cout << "id: " << id << endl;
    cout << "balance: " << balance << endl;
    cout << "name: " << name << endl;
}

void printMenu();
int main() {
    while(true){
        cout << "1. 동적객체배열 방식" << endl;
        int size; // 사용자에게 물어봐서 동적 객체배열 생성
        
        printMenu();

    }
    return 0;
}
void printMenu(){
    cout << "---------------------------------" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입금" << endl;
    cout << "3. 출금" << endl;
    cout << "4. 전체조회" << endl;
    cout << "5. 종료" << endl;
}