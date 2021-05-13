#pragma once

#include "Person.hpp"


#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

class User: public Person {

  private:

    double balance;
  //  vector<Book*> myBooks;
 
   public:
  
    User(string name, string pass);
	
    double getBalance() {
        return balance;
      }
    
    void setBalance(double amount) {
      balance = amount;
    }

    void payBalance(double amount) {
      balance = fabs(balance - amount);
    }

    void checkout(const string& title, const string& author);
    
    void chargeLateFee();



};
