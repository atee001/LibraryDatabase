#ifndef LIBRARYSYSTEM_USER_HPP
#define LIBRARYSYSTEM_USER_HPP

#pragma once

#include "Person.hpp"
#include "BookItem.hpp"
#include "BookRepository.hpp"


#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

class User: public Person {

protected:

    double balance;
    vector<Book*> myBooks;
    map<BookItem*, Book*> *bookList;

private:
    //user should have private variable bool checkoutstatus
    bool getCheckoutStatus() {
        return setCheckoutStatus();
    }
    bool setCheckoutStatus() {
        return false;
    }

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



    bool checkout(Book* bk, const Date& today,const BookRepository*& b){
            
            if(!bk->getCheckoutStatus()) {
                myBooks.push_back(bk);
                bkBook* bk->setCheckoutStatus(true); 
		return true;
            }
              
		return false;
	    

    }

};
#endif //LIBRARYSYSTEM_USER_HPP
