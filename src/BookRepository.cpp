
#include "../header/BookRepository.hpp"




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

BookRepository::BookRepository(BookRepository& bookRepository) {
    bookRepository.bookTitles = bookRepository.bookTitles;
    bookRepository.bookAuthors = bookRepository.bookAuthors;
    bookRepository.bookGenres = bookRepository.bookGenres;
    bookRepository.bookList = bookRepository.bookList;
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

// <<<<<<< rbehe002/Book
// Book* BookRepository::GetBookByTitle(string bookTitle) const {
//     map<string, Book*>::iterator it = bookTitles.find(bookTitle);
// =======
// vector<Book*> BookRepository::GetBook(Book* book) {
//     map<string, Book*>::iterator it = bookTitles.find(book->getTitle());
// >>>>>>> master
//      while (it != bookTitles.end()) {
//          string title = it->first;
//          if (title == bookTitle)
//              return it->second;
//          else
//              return NULL;
//     }
// }

// Book* BookRepository::GetBookByAuthor(string bookAuthor) const {
//     map<string, Book*>::iterator it = bookAuthors.find(bookAuthor);
//     while (it != bookAuthors.end()) {
//         string author = it->first;
//         if (author == bookAuthor)
//             return it->second;
//         else
//             return NULL;
//     }
// }

// Book* BookRepository::GetBookByGenre(string bookGenre) const {
//     map<string, Book*>:: iterator it  = bookGenres.find(bookGenre);
//     while (it != bookGenres.end()) {
//         string genre = it->first;
//         if (genre == bookGenre)
//             return it->second;
//         else
//             return NULL;
//     }
// }


void BookRepository::populate() {//Title | Author * Genre / ISBN


    string Title;
    string Author;
    string Genre;
    string ISBN;
    string line;

    ifstream infile("../book.txt");

    if(!infile){
	cerr << "Invalid Txt file" << endl;
    }

    while(getline(infile,line)){

	size_t one = line.find('|');
	size_t two = line.find('*');
	size_t three = line.find('/');
    
	Title = line.substr(0,one);
	Author = line.substr(one+1, two-one-1);
	Genre = line.substr(two+1, three-two-1);
	ISBN = line.substr(three+1);



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
