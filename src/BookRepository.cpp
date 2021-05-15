#include "BookRepository.hpp"
using namespace std;
BookRepository::BookRepository() {
    return;
}

void BookRepository::display(Book* book) {
    map<BookItem, Book>::iterator it = bookList.begin();
    while(it != bookList.end()) {
        Book b = it->second;
        b.display();
    }

    cout << endl;

}

void BookRepository::AddBook(Book* book) {
    bookTitles.insert(pair<string, Book>(book->getTitle(), *book));
}

void BookRepository::RemoveBook(Book* book) {
    bookTitles.erase(book->getTitle());
}

Book* BookRepository::GetBook(Book* book) {
    map<string, Book>::iterator it = bookTitles.find(book->getTitle());
    if (it == bookTitles.end()) {
        return nullptr;
    } else {
        Book* ptr = new Book();
        *ptr = it->second;
        return ptr;
    }
}
