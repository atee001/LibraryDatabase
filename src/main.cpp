//driver class
#include <iostream>
#include <fstream>
#include "../header/Person.hpp"
using namespace std;

Person* begin(fstream &, const string&);
bool corr_name(fstream&, const string&, const string&, string&);
bool corr_pass(fstream&, const string&, string&);

int main(int argc, char* argv[]){

  if(argc != 2){
   cerr << "Usage error: expected <executable> <input>" << endl;
   exit(1);
 }

 fstream f(argv[1], ios::in | ios::out | ios::app);

 if(!f){
   cerr << "Input file not found" << endl;
   exit(1);
 }
 
 string filename = argv[1];
 Person* p = begin(f,filename);
 cout << "Welcome " << p->getName() << endl;
 delete p;

string userInput = "";

cout << "Please select what you wish to do" << endl;
while(userInput != "9") {
        cout << "\n   0.) Search by Author \n"
        << "   1.) Search by Genre \n"
        << "   2.) Search by Title \n"
        << "   3.) Search Or Author/Genre/Title \n"
        << "   4.) Search And Author/Genre/Title \n" 
        << "   5.) Checkout Book by ISBN \n"
        << "   6.) Check Balance \n"
        << "   7.) Check Due Dates \n"
        << "   8.) Pay Balance \n"
        << "   9.) Quit"
        << endl;

        cin >> userInput;

        if(userInput == "0") {

        }
        else if(userInput == "1") {

        }
        else if(userInput == "2") {

        }
        else if(userInput == "3") {

        }
        else if(userInput == "4") {

        }
        else if(userInput == "5") {

        }
        else if(userInput == "6") {

        }
        else if(userInput == "7") {

        }
        else if(userInput == "8") {

        }
        else if(userInput == "9") {}
        else {
          cout << "\n Invalid input \n" << endl;
        }
        

}

cout << "\n Have a nice day!" << endl;

 return 0;

}


Person* begin(fstream& f, const string& filename){

  string name, ans, pass;
  int tries = 3;
  pass = " ";
  cout << "Welcome to our Library System!" << endl;
  cout << "Are you a new user? (Y/N)" << endl;
  cin >> ans;
  cin.ignore();

  if(ans == "Y" ||  ans == "y" || ans == "YES" || ans == "Yes"){
    
    cout << "Enter your full name with first and last seperated by a space: ";
    getline(cin, name);
    cout << "Enter a password: ";
    getline(cin, pass);
    f << name << "|" << pass << endl;

}

  else{

    string corrPass = "";
    cout << "Enter your name: " << endl;
    getline(cin, name, '\n');

    while(!corr_name(f, filename, name, corrPass) && tries > 0){

      --tries;
      cout << "No users found! " << tries << " attempts remaining!" << endl;

      if(tries == 0){

        cout << "Too many attempts! Exiting..." << endl;
        exit(1);

      }

      cout << "Enter your name: " << endl;
      getline(cin, name, '\n');


    }

    tries = 3;

    cout << "Enter your password: " << endl;

    getline(cin, pass, '\n');

    while(tries > 0 && corrPass != pass){

      --tries;
      cout << "Incorrect Password! " << tries << " attempts remaining!" << endl;

      if(tries == 0){

        cout << "Too many attempts! Exiting..." << endl;
        exit(1);

      }

      cout << "Enter your password: " << endl;
      getline(cin, pass, '\n');

    }

  }

  f.close();
  return new Person(name,pass);

}

bool corr_name(fstream& f, const string& filename, const string& name, string& corrPass){

  string user;

  while(getline(f, user)){

    if(name == user.substr(0,user.find('|'))){

      corrPass = user.substr(user.find('|')+1, user.size()-user.find('|'));
      return true;

    }

}

return false;

}
