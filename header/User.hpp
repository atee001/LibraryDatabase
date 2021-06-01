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
    //string name, pass;
    double balance;
    vector<Book*> myBooks;
    map<BookItem*, Book*> *bookList;

private:
     bool getAdminStatus(){ return false;} 
 
    //user should have private variable bool checkoutstatus
    bool getCheckoutStatus() {
        return setCheckoutStatus();
    }
    bool setCheckoutStatus() {
        return false;
    }

public:

    User(const string& name, const string& pass) : Person(){
	this->name = name;
	this->pass = pass;
    }

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
                bk->setCheckoutStatus(true);
		myBooks.push_back(bk);
		return true;
            }
              
		return false;
	    

    }

};
#endif //LIBRARYSYSTEM_USER_HPP
