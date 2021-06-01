#ifndef LIBRARYSYSTEM_PERSON_HPP
#define LIBRARYSYSTEM_PERSON_HPP

#include <iostream>
#include <vector>
#include "Book.hpp"

using namespace std;
#pragma once

class Person{

protected:
    string name, pass; 
public:
    Person() {}
    virtual bool getAdminStatus() = 0;
    virtual vector<Book*> getVec() = 0;
    Person(const string& name, const string& pass) : name(name), pass(pass){}
    string getName() const{ return name;}
    void setName(const string& name){ this->name = name;}
    string getPass() const{ return pass;}
    void setPass(const string& pass){ this->pass = pass;}
    void checkout(Book* bk, Date& today, BookRepository*& b);
};

#endif //LIBRARYSYSTEM_PERSON_HPP
