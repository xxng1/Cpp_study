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
    Account* accountArray = nullptr; // 동적 객체 배열을 가리키는 포인터
    int size = 0; // 사용자에게 입력받을 동적 객체 배열 크기

    while (true) {
        cout << "1. 동적객체배열 방식" << endl;
        cout << "2. 종료" << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "동적 객체배열 크기를 입력하세요: ";
            cin >> size;

            accountArray = new Account[size]; // 동적 객체 배열 생성

            while (true) {
                printMenu();
                int menuChoice;
                cin >> menuChoice;

                if (menuChoice == 1) {
                    // 계좌 개설
                    if (size > 0) {
                        int id, balance;
                        char name[MAX];
                        cout << "계좌 ID: ";
                        cin >> id;
                        //Account[1].setid(id);
                        cout << "잔액: ";
                        cin >> balance;
                        cout << "이름: ";
                        cin >> name;

                        accountArray[size - 1] = Account(id, balance, name);
                        size--;
                    } else {
                        cout << "더 이상 계좌를 개설할 수 없습니다." << endl;
                    }
                } else if (menuChoice == 2) {
                    // 입금
                    int id, amount;
                    cout << "계좌 ID: ";
                    cin >> id;
                    cout << "입금할 금액: ";
                    cin >> amount;

                    for (int i = 0; i < size; i++) {
                        if (accountArray[i].getid() == id) {
                            accountArray[i].inMoney(amount);
                            break;
                        }
                    }
                } else if (menuChoice == 3) {
                    // 출금
                    int id, amount;
                    cout << "계좌 ID: ";
                    cin >> id;
                    cout << "출금할 금액: ";
                    cin >> amount;

                    for (int i = 0; i < size; i++) {
                        if (accountArray[i].getid() == id) {
                            if (accountArray[i].outMoney(amount)) {
                                cout << "출금이 완료되었습니다." << endl;
                            } else {
                                cout << "잔액이 부족하여 출금할 수 없습니다." << endl;
                            }
                            break;
                        }
                    }
                } else if (menuChoice == 4) {
                    // 전체 조회
                    for (int i = 0; i < size; i++) {
                        accountArray[i].ShowAllData();
                    }
                } else if (menuChoice == 5) {
                    // 종료
                    break;
                } else {
                    cout << "잘못된 선택입니다. 다시 선택하세요." << endl;
                }
            }

            delete[] accountArray; // 동적 객체 배열 메모리 해제
            accountArray = nullptr;
        } else if (choice == 2) {
            // 종료
            break;
        } else {
            cout << "잘못된 선택입니다. 다시 선택하세요." << endl;
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