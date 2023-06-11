#include <iostream>
#include "Permanent.h"
#include "Temporary.h"
#include "Sales.h"
using namespace std;

int main() {
    Permanent permanent("박상웅", 100);
    Temporary temporary("박상원", 150, 15);
    Sales sales("박상현", 200, 50000);

    cout << "Permanent Employee: " << permanent.GetName() << ", Pay: " << permanent.GetPay() << endl;
    cout << "Temporary Employee: " << temporary.GetName() << ", Pay: " << temporary.GetPay() << endl;
    cout << "Sales Employee: " << sales.GetName() << ", Pay: " << sales.GetPay() << endl;

    return 0;
}