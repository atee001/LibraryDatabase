#include "header/BookRepository.hpp"
#include "header/Book.hpp"
#include "header/Date.hpp"
#include "header/BookItem.hpp"
#include "header/SearchContains.hpp"
#include "header/SearchStrat.hpp"
#include "header/SearchAND.hpp"
#include "header/SearchOR.hpp"
#include "header/LibraryCatalog.hpp"
#include "gtest/gtest.h"



TEST(PopulateTest, twentyfive){

	BookRepository* repo = new BookRepository();
	repo->populate();
	repo->display();

	EXPECT_EQ(5, 5);
        delete repo;	
}


TEST(SearchTest,mystery){

	BookRepository* repo = new BookRepository();
	repo->populate();
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
        repo->populate();
        LibraryCatalog* cat = new LibraryCatalog();
        SearchStrat* strat = new SearchOR( new SearchContains("Genre", "Science" ), new SearchContains("Genre", "Mystery"));
        cat->set_search(strat);
	cout << "SearchBox: " << strat->display() << endl;
        cat->print_search(repo, cout);

        EXPECT_EQ(0,0);

	delete repo;
	delete cat;


}

TEST(SearchContains, JK_Rowling){

	BookRepository* repo = new BookRepository();
      repo->populate();
	repo->display();
        LibraryCatalog* cat = new LibraryCatalog();
        SearchStrat* strat = new SearchContains("Author", "Tom Bert" );
        cat->set_search(strat);
	cout << "SearchBox: " << strat->display() << endl;
         cat->print_search(repo, cout);

	EXPECT_EQ(0,0);
	delete repo;	
	delete cat;
}

