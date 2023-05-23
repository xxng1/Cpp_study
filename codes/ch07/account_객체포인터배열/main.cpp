#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 20;
enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
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
    cout << "----------------------" << endl;
    cout << "[id]     : " << id << endl;
    cout << "[balance]: " << balance << endl;
    cout << "[name]   : " << name << endl;
    cout << "----------------------" << endl;
}
//-----------------------------function------------------------------------
void printMenu();
void MakeAccount(Account** AA, int& currentindex, int maxAccount);
void Deposit(Account** AA, int id, int maxAccount, int val); // id를 입력받아서 id의 존재유무 확인 후 입금!
void Withdraw(Account** AA, int id, int maxAccount, int val); // 잔액확인
void Inquire(Account** AA, int currentindex);
void Cleanup(Account** AA, int currentindex);
//-----------------------------function------------------------------------
const int ACCOUNT_MAX = 10;
int main() {
    cout << "객체 포인터 배열 방식" << endl;
    Account* C[ACCOUNT_MAX];
    int size = ACCOUNT_MAX;
    int choice;
    int index = 0;
    while(true){
        printMenu();
        cout << "선택: ";
        cin >> choice;

        switch(choice){
            case MAKE:
                cout << "계좌개설을 선택하였습니다." << endl;
                MakeAccount(C, index, size);
                break;
            case DEPOSIT:
                cout << "입금을 선택하였습니다." << endl;
                cout << "입금할 계좌와 금액을 입력하세요.";
                int num, money;
                cin >> num >> money;
                Deposit(C, num, size, money);
                break;
            case WITHDRAW:
                cout << "출금을 선택하였습니다." << endl;
                cout << "출금할 계좌와 금액을 입력하세요.";
                int numm, moneyy;
                cin >> numm >> moneyy;
                Withdraw(C, numm, size, moneyy);
                break;
            case INQUIRE:
                cout << "전체조회를 선택하였습니다." << endl;
                Inquire(C, index);
                break;
            case EXIT:
                Cleanup(C, index);
                return 0;
            default:
                cout << "잘못된 선택입니다." << endl;
                break;
        }
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

void MakeAccount(Account** AA, int& currentindex, int maxAccount){
    //size와 index크기 비교 => full 상태면 개설 불가
    if(maxAccount > currentindex){
        int i, b;
        char n[MAX];
        cout << "id, balance, name을 한 줄에 입력하세요";
        cin >> i >> b >> n;
        AA[currentindex] = new Account;

        AA[currentindex]->setid(i); // (*(AA+currentindex))->setid(i); // (**(AA+currentindex)).setid(i);
        AA[currentindex]->setbalance(b);
        AA[currentindex]->setname(n);
        currentindex++;
    }
    else{
        cout << "계좌개설이 불가능합니다." << endl;
        cout << "최대" << maxAccount << " 개 가능합니다." << endl;
    }
}

void Deposit(Account** AA, int id, int maxAccount, int val){
    int check = 0;
    for(int i=0; i<maxAccount; i++){
        if(AA[i]->getid() == id){
            check = i+1;
            break;
        }
    }
    if(check != 0){
        int newval = AA[check-1]->getbalance() + val;
        AA[check-1]->setbalance(newval);
    }
    else{
        cout << "목록에 계좌가 없습니다." << endl;
    }
}

void Withdraw(Account** AA, int id, int maxAccount, int val){
    int check = 0;
    for(int i=0; i<maxAccount; i++){
        if(AA[i]->getid() == id){
            check = i+1;
            break;
        }
    }
    if(check != 0){
        if(AA[check-1]->getbalance()==0){
            cout << "잔액이 없습니다." << endl;
        }
        else{
            int newval = AA[check-1]->getbalance() - val;
            AA[check-1]->setbalance(newval);
        }
    }
    else{
        cout << "목록에 계좌가 없습니다." << endl;
    }
}

void Inquire(Account** AA, int currentindex){
    for(int i=0; i<currentindex; i++){
        AA[i]->ShowAllData();
        //*(AA+i)->ShowAllData();
        //**(AA+i).ShowAllData();
    }   
}

void Cleanup(Account** AA, int currentindex){
    for(int i=0; i<currentindex; i++){
        delete AA[i]; AA[i] = NULL;
    }
}