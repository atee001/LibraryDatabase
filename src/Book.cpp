
#include "../header/Book.hpp"

Book::Book() {

}
void Book::display() {
    cout << "Title: " << title << "Author: " << author << "Genre: " << genre << "ISBN: " << isbn << endl;
}

string Book::setTitle(const string& aTitle) {
    title = aTitle;
}

string Book::setAuthor(const string& aAuthor) {
    author = aAuthor;
}

string Book::setGenre(const string& aGenre) {
    genre = aGenre;
}

long Book::setISBN(const long& isbnNum) {
    isbn = isbnNum;
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

const long Book:: getISBN() {
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


