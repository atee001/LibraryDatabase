#ifndef LIBRARYSYSTEM_BOOK_H
#define LIBRARYSYSTEM_BOOK_H

#include "BookComponent.h"

class book: public BookComponent {
private:
    string title;
    string author;
    string genre;
    bool checkout;
public:

    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl << endl;
    }

    string setTitle(string nameOfBook) {
        title = nameOfBook;
    }

    string setAuthor(string nameOfAuthor) {
        author = nameOfAuthor;
    }

    string setGenre(string nameOfGenre) {
        genre = nameOfGenre;
    }

    string getTitle() {
        return title;
    }

    string getAuthor() {
        return author;
    }

    string getGenre() {
        return genre;
    }
};


#endif //LIBRARYSYSTEM_BOOK_H

