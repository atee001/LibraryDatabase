#include "../header/SearchAND.hpp"
#include "../header/SearchOR.hpp"
#include "../header/SearchContains.hpp"
#include "../header/SearchStrat.hpp"
#include "../header/BookItem.hpp"
#include "../header/BookRepository.hpp"
#include "../header/Book.hpp"
#include "../header/LibraryCatalog.hpp"
int main(){

	BookRepository* repo = new BookRepository();
	repo->populate("book.txt");
	LibraryCatalog* lib= new LibraryCatalog();
	SearchStrat* strat = new SearchOR( new SearchContains("Title", "Back To The Future"), new SearchContains("Author", "J.K. Rowling"));
	lib->set_search(strat);
	cout << "SearchBox: " << strat->display() << endl;
	lib->print_search(repo,cout);

	delete repo;
	delete lib;



	return 0;

}
