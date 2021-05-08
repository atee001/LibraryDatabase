#include "BookComponent"
#include "SearchStrat.hpp"
#pragma once

class SearchAND{

  SearchStrat* lhs;
  SearchStrat* rhs;

  public:
    ~SearchAnd(){
        delete lhs;
        delete rhs;
    }
    SearchAND(Searchstrat* lhs, SearchStrat* rhs) : lhs(lhs), rhs(rhs){}
    bool search const(const BookComponent*, const string&);

};
