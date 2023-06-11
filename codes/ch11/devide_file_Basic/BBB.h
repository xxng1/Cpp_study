#ifndef BBB_H
#define BBB_H

#include <string>
#include "AAA.h"

using namespace std;

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


#endif