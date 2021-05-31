#ifndef LIBRARYSYSTEM_LIBRARIAN_HPP
#define LIBRARYSYSTEM_LIBRARIAN_HPP

#include "Person.hpp"
using namespace std;

class Librarian: public Person {
public:
    double balance;
    double fine = 0.10;
    int days;

    Librarian(string name, string pass);

    void chargeLateFee(double totalLateFee, int daysOverdue) {
        daysOverdue = days;
        cout << "Enter total days overdue: " << endl;
        cin >> days;

        totalLateFee = fine * daysOverdue;
        balance = balance + totalLateFee;
    }

};

#endif //LIBRARYSYSTEM_LIBRARIAN_HPP

