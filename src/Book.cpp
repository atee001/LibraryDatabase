#include "../header/Book.hpp"

Book::Book() {

}

Book::Book(const Book &book) {
    title = book.title;
    author = book.author;
    genre = book.genre;
    isbn = book.isbn;

}
void Book::display() {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Genre: " << genre << endl;
    cout << "ISBN: " << isbn << endl;
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

void Book::setISBN(const string& isbnCode) {
    isbn = isbnCode;
}

const string Book::getTitle() {
    return title;
}

const string Book::getAuthor()  {
    return author;
}

const string Book::getGenre()  {
    return genre;
}

const string Book:: getISBN() {
    return isbn;
}

NonFiction::NonFiction() {
    type = "Nonfiction";
}

Biographies::Biographies() {
    type = "Biographies";
}

Science::Science() {
    type = "Science";
}

travelGuides::travelGuides() {
    type = "Travel Guides";
}
