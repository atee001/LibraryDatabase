#ifndef LIBRARYSYSTEM_PERSON_HPP
#define LIBRARYSYSTEM_PERSON_HPP

#include <iostream>
using namespace std;
#pragma once

class Person{

protected:
    string name, pass; 
    bool admin;
public:
    Person() {}
    virtual bool getAdminStatus() = 0;
    Person(const string& name, const string& pass) : name(name), pass(pass){}
    string getName() const{ return name;}
    void setName(const string& name){ this->name = name;}
    string getPass() const{ return pass;}
    void setPass(const string& pass){ this->pass = pass;}

};

#endif //LIBRARYSYSTEM_PERSON_HPP
