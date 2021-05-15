#ifndef LIBRARYSYSTEM_BOOK_HPP
#define LIBRARYSYSTEM_BOOK_HPP


#include <iostream>
#include <string>
#include "BookItem.hpp"
using namespace std;

class Book : public BookItem {
private:
    string title;
    string author;
    string genre;
    long isbn;
    
protected:
    string type;
public:
    Book();
    void display();
    string setTitle(const string& nameOfBook);
    string setAuthor(const string& nameOfAuthor);
    string setGenre(const string& nameOfGenre);
    long setISBN(const long &isbnNum);
    const string getTitle();
    const string getAuthor();
    const string getGenre();
    const long getISBN();

};

class NonFiction : public Book {
public:
    NonFiction();
};

class Biographies : public NonFiction {
public:
    Biographies();
};

class Science : public NonFiction {
public:
    Science();
};

class travelGuides : public NonFiction {
public:
    travelGuides();
};

#endif //LIBRARYSYSTEM_BOOK_HPP


