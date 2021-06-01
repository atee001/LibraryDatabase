#ifndef LIBRARYSYSTEM_BOOK_HPP
#define LIBRARYSYSTEM_BOOK_HPP
#include <iostream>
#include <string>
using namespace std;

class Book {
protected:
    string title;
    string author;
    string genre;
    string isbn;
    string type;
    bool checkOutFlag = false;    
   
public:
    Book() : title(""), author(""), genre(""), isbn(""), type(""){}
    Book(const string&, const string&, const string&, const string&);
    Book(const Book &book);
    void display();
    void setTitle(const string& nameOfBook);
    void setAuthor(const string& nameOfAuthor);
    void setGenre(const string& nameOfGenre);
    void setISBN(const string& isbnCode);
    bool isCheckedOut();
    void setCheckoutFlag(bool);
    const string getTitle();
    const string getAuthor();
    const string getGenre();
    const string getISBN();

};

class NonFiction : public Book {
public:
    NonFiction();
};

class Biographies : public NonFiction {
public:
    Biographies();
};

class Philosophy : public NonFiction {
public:
    Philosophy();
};

class travelGuides : public NonFiction {
public:
    travelGuides();
};

#endif //LIBRARYSYSTEM_BOOK_HPP
