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
    int isbn;
    
protected:
    string type;

public:  
    Book();
    void display();
    void setTitle(const string& nameOfBook);
    void setAuthor(const string& nameOfAuthor);
    void setGenre(const string& nameOfGenre);
    void setIsbn(const long& isbnNum);
    const string getTitle();
    const string getAuthor();
    const string getGenre();
    const int getIsbn();
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


