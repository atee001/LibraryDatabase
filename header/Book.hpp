#ifndef LIBRARYSYSTEM_BOOK_H
#define LIBRARYSYSTEM_BOOK_H

#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string genre;
    string type;
    int isbn;

public:

    void display();
    string setTitle(string nameOfBook);
    string setAuthor(string nameOfAuthor);
    string setGenre(string nameOfGenre);
    int setIsbn(string isbnNum);
    string getTitle();
    string getAuthor();
    string getGenre();
    int getIsbn();


};

class NonFiction : public Book {

};

class Biographies : NonFiction {

};

class Science : NonFiction {

};

class travelGuides : NonFiction {

};

#endif //LIBRARYSYSTEM_BOOK_H


