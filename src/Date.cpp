#include "../header/Date.hpp"

Date::Date() {

}

Date::Date(Date &d) {
    month = d.getMonth();
    day = d.getDay();
    year = d.getYear();
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

void Date::increment() {
  int d = day;
  int m = month;
  int y = year;

  if(m == 12 && d == 31) {
    this->setDay(1);
    this->setMonth(1);
    this->setYear(++y);
  }
  else if((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10)
     && d == 31) {
    this->setMonth(++m);
    this->setDay(1);
  }
  else if((m == 4 || m == 6 || m == 9 || m == 11)
     && d == 30) {
    this->setMonth(++m);
    this->setDay(1);
  }
  else if(m == 2 && y%4 == 0 && d == 29) {
    this->setMonth(++m);
    this->setDay(1);
  }
  else if(m == 2 && d == 28 && y%4 != 0) {
    this->setMonth(++m);
    this->setDay(1);
  }
  else {
    this->setDay(++d);
  }


}

