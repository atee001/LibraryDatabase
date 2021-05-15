
#include "../header/Book.hpp"

void Book::display() {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Genre: " << genre << endl << endl;
}

void Book::setTitle(const string& aTitle) {
    title = aTitle;
}

void Book::setAuthor(const string& aAuthor) {
    author = aAuthor;
}

void Book::setGenre(const string& aGenre) {
    genre = aGenre;
}

void Book::setIsbn(const int& isbnNum) {
    isbn = isbnNum;
}
string Book::getTitle const() {
    return title;
}

string Book::getAuthor const() {
    return author;
}

string Book::getGenre const() {
    return genre;
}

int Book::getIsbn const() {
    return isbn;
}

