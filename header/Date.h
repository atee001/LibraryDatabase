#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date {
public:

    void printDate();
    Date(int d, int m, int y);
    Date();
    int getDay();
    void setDay(int day);
    int getMonth();
    void setMonth(int month);
    int getYear();
    void setYear(int year);

private:
    int day;
    int month;
    int year;
};



#endif //DATE_H

