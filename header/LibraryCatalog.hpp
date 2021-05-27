#ifndef LIBRARYSYSTEM_LIBRARYCATALOG_H
#define LIBRARYSYSTEM_LIBRARYCATALOG_H
#include "BookRepository.hpp"
#include "SearchStrat.hpp"
#include <iostream>

class LibraryCatalog {

	SearchStrat* strat;

	public:

		void print_search(ostream& out);
		void set_search(SearchStrat* strat);
};


#endif //LIBRARYSYSTEM_LIBRARYCATALOG_H
