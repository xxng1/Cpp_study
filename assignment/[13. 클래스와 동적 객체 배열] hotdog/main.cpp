//201835656 박상웅
#include <iostream>

using namespace std;

class HotDogStand {
private:
    int id;
    int numSold;
    static int totalNumSold;
public:
    HotDogStand();
    ~HotDogStand() {}

    void JustSold() {
        numSold++;
        totalNumSold++;
    }
    int GetNumSold() const {
        return numSold;
    }
    void SetID(int standID) {
        id = standID;
    }
    static int GetTotalNumSold() {
        return totalNumSold;
    }
};
HotDogStand::HotDogStand(){
    id = 0;
    numSold = 0;
}

int HotDogStand::totalNumSold = 0;

int main() {
    int count;
    cout << "Stand count (3~10): ";
    cin >> count;
    HotDogStand* sList = new HotDogStand[count]; //4byte
    
    for (int i = 0; i < count; i++) {
        sList[i].SetID(i);
    }

    while (true) {
    cout << "ID: ";
    string input;
    cin >> input;

    if (input == "q") {
        break;
    }

    int id = stoi(input); // stoi 함수를 사용했습니다.

    if (id >= 0 && id < count) {
        sList[id].JustSold();
    }
}

    for (int i = 0; i < count; i++) {
        cout << "Stand " << i << " sold " << sList[i].GetNumSold() << endl;
    }

    cout << "Total sold = " << HotDogStand::GetTotalNumSold() << endl;

    delete[] sList;

    return 0;
}
