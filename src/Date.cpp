#include "../header/Date.hpp"

Date::Date() {

   day = 1;
   month = 1;
   year = 2021;
}

Date::Date(const Date &d) {
    month = d.getMonth();
    day = d.getDay();
    year = d.getYear();
}

Date::Date(const int& d, const int& m, const int& y) {
    day = d;
    month = m;
    year = y;
}

void Date::printDate() {
    cout << "Due date: " << month << "/" << day << "/" << year << endl;
}

int Date::getDay() const{
    return day;
}
void Date::setDay(const int& d) {
    day = d;
}
int Date::getMonth() const {
    return month;
}
void Date::setMonth(const int& m) {
    month = m;
}

int Date::getYear() const{
    return year;
}
void Date::setYear(const int& y) {
    year = y;
}
