

#ifndef BOOKREPOSITORY_HPP
#define BOOKREPOSITORY_HPP

#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <iterator>
#include <algorithm>
#include <string.h>
#include "Book.hpp"

using namespace std;

class BookRepository {
public:
    BookRepository();
    virtual void display() = 0;
    void AddBook(Book* book);
    void RemoveBook(Book* book);
    Book* GetBook(Book* book);
    void populate();

private:
    map<string, vector<Book*>> bookTitles;
    map<string, vector<Book*>> bookAuthors;
    map<string, vector<Book*>> bookGenres;
    map<BookItem, Book*> bookList;
};


#endif //BOOKREPOSITORY_HPP

