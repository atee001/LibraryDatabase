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
    BookRepository();
    BookRepository(BookRepository& bookRepository);
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


