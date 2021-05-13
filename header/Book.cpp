
#include "Book.h"

void Book::display() {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Genre: " << genre << endl << endl;
}

string Book::setTitle(string aTitle) {
    title = aTitle;
}

string Book::setAuthor(string aAuthor) {
    author = aAuthor;
}

string Book::setGenre(string aGenre) {
    genre = aGenre;
}

int Book::setIsbn(int isbnNum) {
    isbn = isbnNum;
}
string Book::getTitle() {
    return title;
}

string Book::getAuthor() {
    return author;
}

string Book::getGenre() {
    return genre;
}

int Book::getIsbn() {
    return isbn;
}

