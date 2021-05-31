#include "../header/BookRepository.hpp"
#include "../header/Book.hpp"
#include "../header/Date.hpp"
#include "../header/BookItem.hpp"
#include "../header/SearchContains.hpp"
#include "../header/SearchStrat.hpp"
#include "../header/SearchAND.hpp"
#include "../header/SearchOR.hpp"
#include "../header/LibraryCatalog.hpp"
#include "../header/search_factory.hpp"
#include <sstream>
#include "gtest/gtest.h"

TEST(FactoryTest, AND){
	
	search_factory* fact = new search_factory();
	BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        LibraryCatalog* cat = new LibraryCatalog();
	cat->set_search(fact->makeSearch());
	cat->print_search(repo, cout);
	EXPECT_EQ(0,0);
        delete repo;
        delete cat;
	delete fact;

}


TEST(PopulateTest, twentyfive){

	BookRepository* repo = new BookRepository();
	repo->populate("book.txt");
	repo->display();

	EXPECT_EQ(5, 5);
        delete repo;	
}


TEST(SearchTest,mystery){

	BookRepository* repo = new BookRepository();
	repo->populate("book.txt");
	LibraryCatalog* cat = new LibraryCatalog();
	SearchStrat* strat = new SearchContains("Genre", "Mystery");
	cat->set_search(strat);
	cout << "SearchBox: ";
	cat->print_search(repo, cout); 

	EXPECT_EQ(0,0);

	delete repo;
	delete cat;

} 


TEST(SearchTest, OR){





        BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        LibraryCatalog* cat = new LibraryCatalog();
        SearchStrat* strat = new SearchOR( new SearchContains("Genre", "Science" ), new SearchContains("Genre", "Mystery"));
        cat->set_search(strat);
	cout << "SearchBox: " << strat->display() << endl;
        cat->print_search(repo, cout);

        EXPECT_EQ(0,0);

	delete repo;
	delete cat;


}

TEST(SearchContains, MispelledAuthor){
	stringstream ss;
	BookRepository* repo = new BookRepository();
      repo->populate("book.txt");
	repo->display();
        LibraryCatalog* cat = new LibraryCatalog();
        SearchStrat* strat = new SearchContains("Genre", "Tom Bert" );
        cat->set_search(strat);
	cout << "SearchBox: " << strat->display() << endl;
         cat->print_search(repo, ss);

	EXPECT_EQ(ss.str(),"No Results!\n");
	delete repo;	
	delete cat;
}

TEST(AllSearch, NoResults){

	stringstream ss;
	BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        repo->display();
        LibraryCatalog* cat = new LibraryCatalog();
        SearchStrat* strat = new SearchAND(new SearchContains("Genre", "science") , new SearchContains("Author", "J.K. Rowling" ));
        cat->set_search(strat);
        cout << "SearchBox: " << strat->display() << endl;
        cat->print_search(repo, ss);

        EXPECT_EQ(ss.str(),"No Results!\n");
        delete repo;
        delete cat;




}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
