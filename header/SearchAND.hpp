#include "SearchStrat.hpp"
#pragma once

class SearchAND : public SearchStrat {

  private:
	
  SearchStrat* lhs;
  SearchStrat* rhs;

  public:
    ~SearchAND(){
        delete lhs;
        delete rhs;
    }
    SearchAND(SearchStrat* lhs, SearchStrat* rhs) : lhs(lhs), rhs(rhs){}
    vector<Book*> search(const BookRepository*);

};

