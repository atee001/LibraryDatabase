#include "Date.h"

Date::Date() {

}

Date::Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

void Date::printDate() {
    cout << "Due date: " << month << "/" << day << "/" << year << endl;
}

int Date::getDay() {
    return day;
}
void Date::setDay(int d) {
    day = d;
}
int Date::getMonth() {
    return month;
}
void Date::setMonth(int m) {
    month = m;
}

int Date::getYear() {
    return year;
}
void Date::setYear(int y) {
    year = y;
}

