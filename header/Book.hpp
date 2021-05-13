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
    void setTitle(const string& nameOfBook);
    void setAuthor(const string& nameOfAuthor);
    void setGenre(const string& nameOfGenre);
    void setIsbn(const int& isbnNum);
    string getTitle const();
    string getAuthor const();
    string getGenre const();
    int getIsbn const();
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


