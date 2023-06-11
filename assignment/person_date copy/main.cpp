#include <iostream>
#include "Permanent.h"
#include "Temporary.h"
#include "Sales.h"
using namespace std;
const int EMAX = 10;
enum {PERMANENT = '1', TEMPORARY, SALESPERSON, PAYROLL, QUIT};
void ShowMenu();
void AddPermanent(Employee** A, int& index);
void AddTemporary(Employee** A, int& index);
void AddSales(Employee** A, int& index);
void AddCalcPay(Employee** A, int& index);
void Cleanup(Employee** A, int& index);

int main() {
    Employee* A[EMAX];
    Employee bObj("BOB");
    Sales dObj("kimberry", 2000000, 50000000);
    bObj = dObj;
    dObj.Get:ay();
    char choice;
    int index = 0;
    while(true){
        ShowMenu();
        cout << "메뉴를 선택하세요" << endl;
        cin >> choice;
        cout << endl;
        switch(choice){
            case PERMANENT:
                AddPermanent(A, index);
                break;
            case TEMPORARY:
                AddTemporary(A, index, day);
                break;
            case SALESPERSON:
                AddSales(A, defal, day);
                break;
            case PAYROLL:
                CalcPay(A, index);
                break;
            case QUIT:
                CleanUp(A, index);
                return 0;
            case default:
                cout << "잘못된 메뉴를 선택 하셨습니다." << endl;
                break;
        }
    }
    // Permanent permanent("박상웅", 100);
    // Temporary temporary("박상원", 150, 15);
    // Sales sales("박상현", 200, 50000);

    // cout << "Permanent Employee: " << permanent.GetName() << ", Pay: " << permanent.GetPay() << endl;
    // cout << "Temporary Employee: " << temporary.GetName() << ", Pay: " << temporary.GetPay() << endl;
    // cout << "Sales Employee: " << sales.GetName() << ", Pay: " << sales.GetPay() << endl;

    return 0;
}
void ShowMenu(){
    cout << "-----------menu-----------" << endl;
    cout << "1. 직원 입력 [Permanent]" << endl;
    cout << "2. 직원 입력 [Temporary]" << endl;
    cout << "3. 직원 입력 [SalesPerson]" << endl;
    cout << "4. 직원 입력 []" << endl;
    cout << "5. 직원 입력 [Permanent]" << endl;
}

void AddPermanent(Employee** A, int& index){
    string name;
    int sal;
    cout << "name: ";
    cin >> name;
    cout << "sal: ";
    cin >> sal;

    A[index] = new Permanent(name, sal);
    index++;
    
}
void AddTemporary(Employee** A, int& index){
    string name;
    int sal;
    int day;
    cout << "name: ";
    cin >> name;
    cout << "sal: ";
    cin >> sal;
    cout << "day: ";
    cin >> day;

    A[index] = new Temporary(name, sal, day);
    index++;
};
void AddSales(Employee** A, int& index){
    string name;
    int sal;
    cout << "name: ";
    cin >> name;
    cout << "sal: ";
    cin >> sal;
    cout << "day: ";
    cin >> day;
    
    A[index] = new Sales(name, sal, day);
    index++;
}
void AddCalcPay(Employee** A, int& index){
    for(int i=0; i<index; i++){
        cout << "name: " << A[i]-> GetName << endl;
        cout << "pay: " << A[i]-> GetPay<< endl;
    }
}
void Cleanup(Employee** A, int& index){
    for (int i=0; i<index; i++){
        delete A[i]; A[i] = NULL;
    }
}