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
#include "../header/person_factory.hpp"
using namespace std;


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
 person_factory* pfact;
 Person* p = pfact->begin(f,filename);
 if(p->getAdminStatus()) cout << "Welcome Librarian: " << p->getName() << endl;
 else cout << "Welcome " << p->getName() << endl;



string userInput = "";

cout << "Please select what you wish to do" << endl;
BookRepository* repo = new BookRepository();
repo->populate("book.txt");
while(true) {
        cout << "\n   0.) Search For Books \n"
        << "   1.) Checkout Book by ISBN \n"
        << "   2.) Check Balance \n"
        << "   3.) Check Due Dates \n"
        << "   4.) Pay Balance \n"
        << "   5.) Quit"
        << endl;

        cin >> userInput;

	
	if(userInput == "0") {
		LibraryCatalog* lib = new LibraryCatalog();		
		search_factory* fact = new search_factory();
		SearchStrat* search= fact->makeSearch();
		lib->set_search(search);
		lib->print_search(repo, cout);
	        delete lib;
		delete fact;	
        }
        else if(userInput == "1") {
		string isbn;
		cout << "Enter an ISBN Code: " << endl;
		cin >> isbn;
		Book* bk = repo->getBookByISBN(isbn);
		while(!bk){ 
			cout << "No Book for " << isbn  << " found!" << endl;
			cout << "Enter an ISBN Code: " << endl;
			cin >> isbn;
			bk = repo->getBookByISBN(isbn);
		}
		BookItem* item = repo->getBookList().at(bk);
		cout << "Book Chosen: " << endl;
		bk->display();
		 				

        }
        else if(userInput == "2") {

        }
        else if(userInput == "3") {

        }
        else if(userInput == "4") {

        }
        else if(userInput == "5") {
		delete p;	
		delete repo;
		break;
        }
        else {
          cout << "\n Invalid input \n" << endl;
        }
        

}

	cout << "\n Have a nice day!" << endl;

 	return 0;

}


