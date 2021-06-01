#ifndef LIBRARYSYSTEM_LIBRARIAN_HPP
#define LIBRARYSYSTEM_LIBRARIAN_HPP
#include "Person.hpp"
using namespace std;

class Librarian: public Person {
private:
    string name, pass;
    double balance;
    double fine = 0.10;
    int days;
public:

     bool getAdminStatus() {return true;} 

    Librarian(string name, string pass) : Person() { 
	this-> name= name; 
	this->pass = pass;
        admin = true;
}

    
    void chargeLateFee(double totalLateFee, int daysOverdue) {
        daysOverdue = days;
        cout << "Enter total days overdue: " << endl;
        cin >> days;

        totalLateFee = fine * daysOverdue;
        balance = balance + totalLateFee;
    }

};

#endif //LIBRARYSYSTEM_LIBRARIAN_HPP

