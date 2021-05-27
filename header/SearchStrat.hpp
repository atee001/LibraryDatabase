#include "BookRepository.hpp"
#include <vector>
#include <algorithm>
#pragma once

class SearchStrat{
  public:
    virtual vector<Book*> search(const BookRepository*) = 0;

};

