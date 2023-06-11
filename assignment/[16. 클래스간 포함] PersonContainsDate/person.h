#ifndef PERSON_H
#define PERSON_H

#include "date.h"

class Person {
private:
    long identity;
    Date birthDate;

public:
    Person();
    Person(long id, const Date& bd);
    Person(const Person& other);
    ~Person();
    void print() const;
};

#endif