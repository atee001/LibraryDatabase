#include "BookComponent.hpp"
#pragma once

class SearchStrat{
  public:
    virtual bool search(const BookComponent*, const string& str) = 0;

};

