#ifndef LIBRARYSYSTEM_BOOKREPOSITORY_HPP
#define LIBRARYSYSTEM_BOOKREPOSITORY_HPP

#include <iostream>
#include <map>
#include <utility>
#include <iterator>
#include <algorithm>
#include <string>
#include "BookItem.hpp"

class BookRepository  {
public:
    BookRepository();
    void display(Book* book);
    void AddBookByTitle(Book* book);
    void AddBookByAuthor(Book* book);
    void AddBookByGenre(Book* book);
    void CheckOut(Book* book, Date checkOutDate);
    void RemoveBook(Book* book);
    void populate();
    Book* GetBook(Book* book);
    const int DUE_DATE = 60; //A user can checkout a book for up to 60 days by default.
private:
    map<string, Book*> bookTitles;
    map<string, Book*> bookAuthors;
    map<string, Book*> bookGenres;
    map<BookItem*, Book*> bookList;
};


#endif //LIBRARYSYSTEM_BOOKREPOSITORY_HPP



