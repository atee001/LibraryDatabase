#include <iostream>
#include <fstream>
#include "BookItem.hpp"
#include "BookRepository.hpp"
#include "Book.hpp"
using namespace std;

int main() {
   Book book;
   book.setAuthor("Jessica Dunham");
   book.setTitle("The Open Road: 50 Best Road Trips in the USA");
   book.setGenre("Travel guides");
   book.setIsbn(9781640499300);
  book.display();

}
