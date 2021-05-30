#ifndef BOOKREPOSITORY_HPP
#define BOOKREPOSITORY_HPP
#include <vector>
#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <iterator>
#include <algorithm>
#include <string>
#include "BookItem.hpp"
#include <fstream>
using namespace std;

class BookRepository  {
public:
    ~BookRepository(){

	for(auto& it: this->bookList){

		cout << "Deleting..." << it.second->getTitle() << " " << it.second->getAuthor() << " " << it.second->getGenre() << " " << it.second->getISBN() << endl;
		delete it.first;
		delete it.second;
		
	}
/*		
	for(auto& it: this->bookTitles){
	
		for(auto& jt : it.second){

			if(jt != nullptr){ 
				cout << "Deleting title!!!!" << endl;
				delete jt;

		}		

	}

	for(auto& it: this->bookAuthors){
		 for(auto& jt : it.second){

                        if(jt != nullptr){ 
			cout << "Deleting Author!!!!" << endl;

			delete jt;
			}

                }

	}

	for(auto& it: this->bookGenres){

		 for(auto& jt : it.second){
			
                        if(jt != nullptr){

			cout << "Deleting Genre!!!" << endl;	
			 delete jt;
			}

                }
	}

*/
	bookList.clear();
	bookTitles.clear();
	bookAuthors.clear();
	bookGenres.clear();

    }

    
    BookRepository();
    BookRepository(const BookRepository& bookRepository);
    void display();
    void AddBookByTitle(Book* book);
    void AddBookByAuthor(Book* book);
    void AddBookByGenre(Book* book);
    void CheckOut(Book* book, Date checkOutDate);
    void RemoveBook(Book* book);
    void populate();
    void displayMapTitle();
    void displayMapAuthors();
    void displayBookGenres();
   // Book* GetBookByAuthor(string bookAuthor) const;
    //Book* GetBookByTitle(string bookTitle) const;
   // Book* GetBookByGenre(string bookGenre) const; 
    map<string, vector<Book*>> getMapAuthor() const;
    map<string, vector<Book*>> getMapTitle() const;
    map<string, vector<Book*>> getMapGenre() const;
    const int DUE_DATE = 60; //A user can checkout a book for up to 60 days by default.

private:
    map<string, vector<Book*>> bookTitles;
    map<string, vector<Book*>> bookAuthors;
    map<string, vector<Book*>> bookGenres;

    map<BookItem*, Book*> bookList;

};


#endif //LIBRARYSYSTEM_BOOKREPOSITORY_HPP


