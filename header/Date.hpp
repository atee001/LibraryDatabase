
#ifndef DATE_HPP
#define DATE_HPP


#include <iostream>
using namespace std;

class Date {
public:


    Date();
    Date(int d, int m, int y);
    void printDate();

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

#endif //DATE_HPP


