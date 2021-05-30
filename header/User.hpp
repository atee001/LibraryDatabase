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


    Book* getBookByISBN(const string& isbn){
        map<string, Book*> bookList;
        for(auto it : bookList){
            if(it.second->getISBN() == isbn){
                return it.second; //returns Book* of the specified isbn
            }
        }
        return nullptr;
    }

        void checkout(const string& isbn){
            Book* mybook = getBookByISBN(isbn); //iterate through bookLists
            if(mybook->getCheckoutStatus() == false) {
                myBooks.push_back(mybook);
                mybook->setCheckoutStatus() == true;
            }
            else {
                cout << "Already Checked out!";
            }

        }

};
#endif //LIBRARYSYSTEM_USER_HPP
