#include <fstream>
#include "../header/BookRepository.hpp"

using namespace std;


BookRepository::BookRepository() {

}

BookRepository::BookRepository(BookRepository& bookRepository) {
    bookRepository.bookTitles = bookRepository.bookTitles;
    bookRepository.bookAuthors = bookRepository.bookAuthors;
    bookRepository.bookGenres = bookRepository.bookGenres;
    bookRepository.bookList = bookRepository.bookList;
}
void BookRepository::AddBookByTitle(Book* book) {
    bookTitles[book->getTitle()] = book;
}

void BookRepository::AddBookByAuthor(Book* book) {
    bookAuthors[book->getAuthor()] = book;
}

void BookRepository::AddBookByGenre(Book* book) {
    bookGenres[book->getGenre()] = book;
}

void BookRepository::CheckOut(Book* book, Date checkOutDate) {
    BookItem *bookItem = new BookItem();
    bookItem->setCheckoutDate(checkOutDate);
    int dueMonth = checkOutDate.getMonth() + 2;
    if (dueMonth > 12) {
        int newDueMonth = dueMonth - 12;
        bookItem->getDueDate().setMonth(newDueMonth);
        int newDueYear = bookItem->getDueDate().getYear();
        Date* dueDate = new Date(checkOutDate.getDay(), newDueMonth, newDueYear);
        bookItem->setDueDate(*dueDate);
    } else {
        Date *dueDate = new Date(checkOutDate.getDay(), dueMonth, checkOutDate.getYear());
        bookItem->setCheckoutDate(*dueDate);
    }
    bookItem->setTitle(book->getTitle());
    bookItem->setAuthor(book->getAuthor());
    bookItem->setGenre(book->getGenre());
    bookItem->setISBN(book->getISBN());
    bookList[bookItem] = book;
}

void BookRepository::RemoveBook(Book* book) {
    bookTitles.erase(book->getTitle());
}

void BookRepository::display(Book* book) {
    std::map<BookItem*, Book *>::iterator it;
    for (it = bookList.begin(); it != bookList.end(); it++) {
        BookItem* bookItem = it->first;
        Book* book = (Book*)it->second;
        bookItem->display();
        book->display();
    }
    cout << endl;
}

Book* BookRepository::GetBookByTitle(string bookTitle) const {
    map<string, Book*>::iterator it = bookTitles.find(bookTitle);
     while (it != bookTitles.end()) {
         string title = it->first;
         if (title == bookTitle)
             return it->second;
         else
             return NULL;
    }
}

Book* BookRepository::GetBookByAuthor(string bookAuthor) const {
    map<string, Book*>::iterator it = bookAuthors.find(bookAuthor);
    while (it != bookAuthors.end()) {
        string author = it->first;
        if (author == bookAuthor)
            return it->second;
        else
            return NULL;
    }
}

Book* BookRepository::GetBookByGenre(string bookGenre) const {
    map<string, Book*>:: iterator it  = bookGenres.find(bookGenre);
    while (it != bookGenres.end()) {
        string genre = it->first;
        if (genre == bookGenre)
            return it->second;
        else
            return NULL;
    }
}


void BookRepository::populate() {//Title | Author * Genre / ISBN

    string word = "";
    string Title = "";
    string Author = "";
    string Genre = "";
    string ISBN = "";

    int count = 0;

    ifstream infile("book.txt");

    while(infile >> word) {
        if(word != "|" && count == 0) {
            Title += word;
        }
        else {
            count++;
        }
        if(count == 1 && word != "*") {
            Author += word;
        }
        else {
            count++;
        }
        if(count == 2 && word != "/") {
            Genre += word;
        }
        else {
            count++;
        }
        if(count == 3 && word != "\n") {
            ISBN += word;
        }
        else {
            count = 0;

            Book* newBook = new Book();

            newBook->setTitle(Title);
            newBook->setAuthor(Author);
            newBook->setGenre(Genre);
            newBook->setISBN(ISBN);

            Title = "";
            Author = "";
            Genre = "";
            ISBN = "";
            Date currDate(1,1,2021);
            Date dueDate(3, 1, 2021);
            BookItem* bookItem = new BookItem(currDate, dueDate);

            AddBookByGenre(newBook);
            AddBookByAuthor(newBook);
            AddBookByTitle(newBook);
            bookList[bookItem] = newBook;

        }

    }

}
