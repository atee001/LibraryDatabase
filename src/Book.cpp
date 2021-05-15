#include "Book.hpp"

Book::Book() {

}
void Book::display() {
    cout << "Title: " << title << "Author: " << author << "Genre: " << genre << "ISBN: " << isbn << endl;
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

long Book::setIsbn(long isbnNum) {
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
