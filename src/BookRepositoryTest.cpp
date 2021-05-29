#include <iostream>
#include <fstream>
#include "../header/BookItem.hpp"
#include "../header/BookRepository.hpp"
#include "../header/Book.hpp"
using namespace std;

int main() {
   Book *book1 = new Book();
   book1->setAuthor("Jessica Dunham");
   book1->setTitle("The Open Road: 50 Best Road Trips in the USA");
   book1->setGenre("Travel guides");
   book1->setISBN("9781640499300");
    cout << "Book 1" << endl;
    book1->display();

    Book *book2 = new Book();
    book2->setAuthor("Lenna Stuart");
    book2->setTitle("The Break of Dawn");
    book2->setGenre("Romance");
    book2->setISBN("0000000000001");
    cout << endl;
    cout << "Book 2" << endl;

    book2->display();

  BookRepository bookRepository;
  bookRepository.AddBookByTitle(book1);
 // cout << "Book 1 added: The Open Road" << endl;
  bookRepository.AddBookByAuthor(book2);
 // cout << "Book 2 added: The Break of Dawn" << endl;
 // Book *retbook1 = bookRepository.GetBook(book1);
 // cout << "Before listing" << endl;
 // if (book1->getTitle().compare(retbook1->getTitle()) == false){
   //   cout << "Found book with title : " << book1->getTitle() << endl;
 // }
 // else {
  //    cout << "Book with title " << book1->getTitle() << " not found " << endl;
 // }

  cout << endl;
  cout << "End of BookRepository Test" << endl;

}
