#include "../header/SearchAND.hpp"
#include "../header/SearchOR.hpp"
#include "../header/SearchContains.hpp"
#include "../header/SearchStrat.hpp"
#include "../header/BookItem.hpp"
#include "../header/BookRepository.hpp"
#include "../header/Book.hpp"
#include "../header/LibraryCatalog.hpp"
int main(){

	Book* book1 = new Book();
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


	Book* book3 = new Book();
        book3->setAuthor("Jessica Dunham");
        book3->setTitle("The Open Road: 50 Best Road Trips in the USA");
        book3->setGenre("Travel guides");
        book3->setISBN("9781640499300");
        cout << "Book 3" << endl;
        book1->display();

	BookRepository* repo = new BookRepository();
	repo->AddBookByAuthor(book1);
	repo->AddBookByAuthor(book2);
	repo->AddBookByAuthor(book3);
	LibraryCatalog* lib = new LibraryCatalog();
	
 	lib->set_search(new SearchAND(new SearchContains("Author", "Jessica Dunham"), new SearchContains("Author", "Lenna Stuart")));
	lib->print_search(repo, cout);
 	SearchStrat* root = new SearchAND(new SearchContains("Author", "Jessica Dunham"), new SearchContains("Author", "Lenna Stuart"));
	cout << "SearchBox:" << root->display();
	return 0;

}
