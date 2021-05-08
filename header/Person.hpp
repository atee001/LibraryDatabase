using namespace std;
#pragma once

class Person{

    string name, pass;

  public:

    Person(const string& name, const string& pass) : name(name), pass(pass){}
    string getName() const{ return name;}
    void setName(const string& name){ this->name = name;}
    string getPass() const{ return pass;}
    void setPass(const string& pass){ this->pass = pass;}

};
