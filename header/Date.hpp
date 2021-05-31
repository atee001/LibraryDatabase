#ifndef LIBRARYSYSTEM_DATE_HPP
#define LIBRARYSYSTEM_DATE_HPP

#include <iostream>
using namespace std;

class Date {
public:

    Date();
    Date(int d, int m, int y);
    Date(Date &d);
    void printDate();
    int getDay();
    void setDay(int day);
    int getMonth();
    void setMonth(int month);
    int getYear();
    void increment(); 
    void setYear(int year);

private:
    int day = 1;
    int month = 1;
    int year = 2021;
};

#endif //LIBRARYSYSTEM_DATE_HPP
