//driver class
#include "../header/SearchAND.hpp"
#include "../header/SearchOR.hpp"
#include "../header/SearchContains.hpp"
#include "../header/SearchStrat.hpp"
#include "../header/BookItem.hpp"
#include "../header/BookRepository.hpp"
#include "../header/Book.hpp"
#include "../header/LibraryCatalog.hpp"
#include <iostream>
#include <fstream>
#include "../header/search_factory.hpp"
#include "../header/Date.hpp"
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
        cout << "\n   0.) Search For Books \n"
        << "   1.) Checkout Book by ISBN \n"
        << "   2.) Check Balance \n"
        << "   3.) Check Due Dates \n"
        << "   4.) Pay Balance \n"
	<< "   5.) Return Book by ISBN \n"
        << "   6.) Quit"
        << endl;

        cin >> userInput;

	
	if(userInput == "0") {
		BookRepository* repo = new BookRepository();
        	repo->populate("book.txt");
		LibraryCatalog* lib = new LibraryCatalog();		
		search_factory* fact = new search_factory();
		SearchStrat* search= fact->makeSearch();
		lib->set_search(search);
		lib->print_search(repo, cout);
	        delete lib;
		delete fact;	
		delete repo;
        }
        else if(userInput == "1") {

        }
        else if(userInput == "2") {

        }
        else if(userInput == "3") {

        }
        else if(userInput == "4") {

        }
	else if (userInput == "5") {
		
	}
        else if(userInput == "6") {
	
		//delete lib;
		break;
        }
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
