#ifndef DATE_H
#define DATE_H

class Date {
private:
    int month;
    int day;
    int year;

public:
    Date();
    Date(int month, int day, int year);
    Date(const Date& other);
    ~Date();
    void print() const;
};

#endif