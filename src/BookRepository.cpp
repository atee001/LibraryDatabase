#include <fstream>
#include "../header/BookRepository.hpp"

using namespace std;

BookRepository::BookRepository() {

}


map<string, vector<Book*>> BookRepository::getMapAuthor() const{


	return this->bookAuthors;
}

map<string, vector<Book*>> BookRepository::getMapTitle() const{

	return this->bookTitles;

}

map<string, vector<Book*>> BookRepository::getMapGenre() const{

	return this->bookGenres;
}

map<string, Book*> BookRepository::getMapIsbn() const {
    return this->bookISBN;
}

BookRepository::BookRepository(const BookRepository& bookRepository) {
    bookTitles = bookRepository.bookTitles;
    bookAuthors = bookRepository.bookAuthors;
    bookGenres = bookRepository.bookGenres;
    bookList = bookRepository.bookList;
}
void BookRepository::AddBookByTitle(Book* book) {
    bookTitles[book->getTitle()].push_back(book);
}

void BookRepository::AddBookByAuthor(Book* book) {
    bookAuthors[book->getAuthor()].push_back(book);
}

void BookRepository::AddBookByGenre(Book* book){ 
    bookGenres[book->getGenre()].push_back(book);

}

void BookRepository::AddBookByIsbn(Book* book) {
	bookISBN.insert(pair<string,Book*>(book->getISBN(), book));

}

void BookRepository::displayMapTitle(){

	for(map<string, vector<Book*>>::iterator it = bookTitles.begin(); it != bookTitles.end(); it++){		
		for(auto x : it->second){
			cout << x->getTitle() << endl;
		}
	}

}
void BookRepository::displayMapAuthors(){
	for(map<string, vector<Book*>>::iterator it = bookAuthors.begin(); it != bookAuthors.end(); it++){

                for(auto x : it->second){
                        cout << x->getAuthor() << endl;
                }
        
	}

}

void BookRepository::displayBookGenres(){
for(map<string, vector<Book*>>::iterator it = bookGenres.begin(); it != bookGenres.end(); it++){
                for(auto x : it->second){
                        cout << x->getGenre() << endl;
                }
        }

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

void BookRepository::display() {
    std::map<BookItem*, Book *>::iterator it;
    for (it = bookList.begin(); it != bookList.end(); it++) {
        BookItem* bookItem = it->first;
        Book* book = (Book*)it->second;
       // bookItem->display();
        book->display();
    }
    cout << endl;
}

void BookRepository::populate(const string &s) {//Title | Author * Genre / ISBN


    string Title;
    string Author;
    string Genre;
    string ISBN;
    string line;

    ifstream infile(s);

    if(!infile){
	
	cerr << "Invalid Txt file" << endl;
	exit(1);
    }

    
    Book* newBook = nullptr;
    BookItem* bookItem = nullptr;
    while(getline(infile,line, '\n')){

	size_t one = line.find('|');
	size_t two = line.find('*');
	size_t three = line.find('/');
    
	Title = line.substr(0,one);
	Author = line.substr(one+1, two-one-1);
	Genre = line.substr(two+1, three-two-1);
	ISBN = line.substr(three+1);

        newBook = new Book(Title, Author,Genre, ISBN);

        Date currDate(1,1,2021);
        Date dueDate(3, 1, 2021);
        bookItem = new BookItem(currDate, dueDate);

        AddBookByGenre(newBook);
        AddBookByAuthor(newBook);
        AddBookByTitle(newBook);
	AddBookByIsbn(newBook);
        bookList[bookItem] = newBook;

    }
       
      infile.close();
}
