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

TEST(GenreTest,mystery){
	BookRepository* repo = new BookRepository();
	repo->populate("book.txt");
	SearchStrat* strat = new SearchContains("Genre", "Mystery");
	EXPECT_EQ(strat->search(repo).size(),9);

	delete repo;
	delete strat;

} 


TEST(GenreTest,nonfiction){
	BookRepository* repo = new BookRepository();
	repo->populate("book.txt");
	SearchStrat* strat = new SearchContains("Genre", "Nonfiction");
	EXPECT_EQ(strat->search(repo).size(),117);
	delete repo;
	delete strat;

}

TEST(GenreTest, Fiction){
	BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        SearchStrat* strat = new SearchContains("Genre", "Fiction");
        EXPECT_EQ(strat->search(repo).size(),120);
        delete repo;
	delete strat;

}

TEST(GenreTest, Romance){

	BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        SearchStrat* strat = new SearchContains("Genre", "Romance");
        EXPECT_EQ(strat->search(repo).size(),8);
	delete repo;
	delete strat;
}

TEST(GenreTest, Literature){


	BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        SearchStrat* strat = new SearchContains("Genre", "Literature");
        EXPECT_EQ(strat->search(repo).size(),12);
        delete repo;
	delete strat;
}


TEST(GenreTest, Manga){


	BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        SearchStrat* strat = new SearchContains("Genre", "Manga");
        EXPECT_EQ(strat->search(repo).size(),12);
        delete repo;
	delete strat;
}

TEST(GenreTest, Horror){

	BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        SearchStrat* strat = new SearchContains("Genre", "Horror");
        EXPECT_EQ(strat->search(repo).size(),12);
        delete repo;
	delete strat;

}

TEST(GenreTest, Science){

	
        BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        SearchStrat* strat = new SearchContains("Genre", "Science");
        EXPECT_EQ(strat->search(repo).size(),10);
        delete repo;
        delete strat;

}

TEST(GenreTest, Biography){

	
        BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        SearchStrat* strat = new SearchContains("Genre", "Biography");
        EXPECT_EQ(strat->search(repo).size(),37);
        delete repo;
        delete strat;


}
TEST(GenreTest, TravelGuides){
	
        BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        SearchStrat* strat = new SearchContains("Genre", "Travel Guides");
        EXPECT_EQ(strat->search(repo).size(),7);
        delete repo;
        delete strat;

}

TEST(GenreTest, Philosophy){

        BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        SearchStrat* strat = new SearchContains("Genre", "Philosophy");
        EXPECT_EQ(strat->search(repo).size(),9);
        delete repo;
        delete strat;

}
TEST(SearchContains, MispelledAuthor){
	stringstream ss;
	BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
	repo->display();
        SearchStrat* strat = new SearchContains("Genre", "Tom Bert" );
	LibraryCatalog* cat = new LibraryCatalog();
	cat->set_search(strat);
	cat->print_search(repo, ss);	
	EXPECT_EQ(ss.str(),"No Results!\n");
	delete repo;	
	delete cat;
}

TEST(AND, ScienceANDJKRowling){
	stringstream ss;
	BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        repo->display();
	LibraryCatalog* cat = new LibraryCatalog();
        SearchStrat* strat = new SearchAND(new SearchContains("Genre", "Science") , new SearchContains("Author", "J.K. Rowling" ));
	cat->set_search(strat);
	cat->print_search(repo,ss);	
        EXPECT_EQ(ss.str(),"No Results!\n");
        delete repo;
	delete cat;
}

TEST(AND,ScienceANDRomance){
	stringstream ss;
        BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        repo->display();
        LibraryCatalog* cat = new LibraryCatalog();
        SearchStrat* strat = new SearchAND(new SearchContains("Genre", "Science") , new SearchContains("Genre", "Romance" ));
        cat->set_search(strat);
        cat->print_search(repo,ss);
        EXPECT_EQ(ss.str(),"No Results!\n");
        delete repo;
        delete cat;

}

TEST(AND, RomanceANDFiction){
	stringstream ss;
        BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        repo->display();
        LibraryCatalog* cat = new LibraryCatalog();
        SearchStrat* strat = new SearchAND(new SearchContains("Genre", "Fiction") , new SearchContains("Genre", "Romance" ));
        cat->set_search(strat);
        cat->print_search(repo,ss);
        EXPECT_EQ(ss.str(),"No Results!\n");
        delete repo;
        delete cat;


}

TEST(GenreTest, Adventure){

        BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        SearchStrat* strat = new SearchContains("Genre", "Adventure");
        EXPECT_EQ(strat->search(repo).size(),5);
        delete repo;
        delete strat;

}

TEST(GenreTest, Thriller){
        BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        SearchStrat* strat = new SearchContains("Genre", "Thriller");
        EXPECT_EQ(strat->search(repo).size(),24);
        delete repo;
        delete strat;
}

TEST(



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
