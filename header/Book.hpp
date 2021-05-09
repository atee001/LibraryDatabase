#ifndef LIBRARYSYSTEM_BOOK_H
#define LIBRARYSYSTEM_BOOK_H

#include "BookComponent.hpp"

class book: public BookComponent {
private:
    string title;
    string author;
    string genre;
    bool checkout;
public:

    void display(){
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl << endl;
    }

    void setTitle (const string& nameOfBook) {
        title = nameOfBook;
    }

    void setAuthor (const string& nameOfAuthor) {
        author = nameOfAuthor;
    }

    void setGenre (const string& nameOfGenre) {
        genre = nameOfGenre;
    }

    string getTitle const() {
        return title;
    }

    string getAuthor const() {
        return author;
    }

    string getGenre const() {
        return genre;
    }
};


#endif //LIBRARYSYSTEM_BOOK_H

