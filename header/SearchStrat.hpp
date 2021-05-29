#include "BookRepository.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#pragma once

class SearchStrat{
  public:
    virtual vector<Book*> search(const BookRepository*) = 0;
    virtual const string display(){
	return "No Search Chosen"; 
    }	
};

