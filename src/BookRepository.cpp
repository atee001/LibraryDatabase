
#include "../header/BookRepository.hpp"
#include "../book.txt"

using namespace std;
BookRepository::BookRepository() {
    return;
}

void BookRepository::display() {
    map<BookItem, Book>::iterator it = bookList.begin();
    while(it != bookList.end()) {
        Book b = it->second;
        b.display();
    }

    cout << endl;
}

void BookRepository::AddBook(Book* book) {

    bookTitles.insert(pair<string, Book>(book->getTitle(), book));
 
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
void BookRepository::populate() {//Title | Author * Genre / ISBN

    string word = "";
    string Title = "";
    string Author = "";
    string Genre = "";
    string ISBN = "";


    ifstream infile("book.txt");
    if(infile.fail()) {
        cout << "failed to open book.txt" << endl;
        exit(1);
    }

    while(!infile.eof()) {
      int count = 0;
      string line = "";

      getline(infile, line);
      //cout << line << endl;

      for(int i = 0; i < line.size(); i++) {
        if(line.at(i) != '|' && count == 0) {
          Title += line.at(i); 
          //cout << line.at(i) << " " << count << endl;
        }
        if(line.at(i) == '|') {
          count++;
          i++;
          //cout << "hi" << endl;
        }
        if(line.at(i) != '*' && count == 1) {
          Author += line.at(i);
        } 
        if(line.at(i) == '*') {
          count++;
          i++;
          //cout << "hello" << endl;
        }
        if(line.at(i) != '/' && count == 2) {
           Genre += line.at(i);
        } 
        if(line.at(i) == '/') {
          count++;
          i++;
          //cout << "hola" << endl;
        }
        if(line.at(i) != '\n' && count == 3) {
           ISBN += line.at(i);
        } 

      }
      
      // while(infile >> word) {
      //     if(word != "|" && count == 0) {
      //         Title += word + " ";
      //         //cout << Title << count << endl;
      //     }
      //     else {
      //         count++;
      //     }
      //     if(count == 1 && word != "*") {
      //         Author += word + " ";
      //         //cout << Author << count << endl;
      //     }
      //     else {
      //         count++;
      //     }
      //     if(count == 2 && word != "/") {
      //         Genre += word + " ";
      //         //cout << Genre << count << endl;
      //     }
      //     else {
      //         count++;
      //     }
      //     if(count == 3) { //&& word != "\n"
      //         ISBN += word;
      //         //cout << ISBN << count << endl;
      //     }

      // }
      

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
      infile.close();

}
