#include "../header/BookRepository.h"
#include <iostream>

void BookRepository::display() {

}

void BookRepository::AddBook(Book* book) {
    bookTitles.emplace(book->getTitle(), &book);
}

void BookRepository::RemoveBook(Book* book) {
    bookTitles.erase(book->getTitle());
}

Book* BookRepository::GetBook(Book* book) {
    map<string, Book>::iterator it = bookTitles.find(book->getTitle());
    if (it == bookTitles.end()) {
        return nullptr;
    } else {
        Book foundBook = it->second;
        return &foundBook;
    }
}

