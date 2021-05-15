
#ifndef BOOKREPOSITORY_H
#define BOOKREPOSITORY_H

#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include "Book.h"
#include "BookItem.h"

using namespace std;

class BookRepository : public Book {
public:
    virtual void display() = 0;
    void AddBook(Book* book);
    void RemoveBook(Book* book);
    Book* GetBook(Book* book);

private:
    map<string, Book> bookTitles;
    map<string, Book> bookAuthors;
    map<string, Book> bookGenres;
    map<Book, BookItem> bookItemList;
};


#endif //BOOKREPOSITORY_H
