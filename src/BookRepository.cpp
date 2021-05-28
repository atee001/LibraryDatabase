
#include "../header/BookRepository.hpp"
#include "../book.txt"

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

	int count = 0;
	
	ifstream infile("book.txt");
	if(infile.fail()) {
		cout << "failed to open book.txt" << endl;
		exit(1);
	}        

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

			AddBook(newBook);
			bookAuthors.insert(pair<string, Book*>(newBook->getAuthor(), newBook));
			bookGenres.insert(pair<string, Book*>(newBook->getGenre(), newBook));
			bookList.insert(pair<BookItem, Book*>(*newBook, newBook));

		}


	}

	infile.close();	
}

