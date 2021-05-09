
#pragma once 

#include "BookComponent.hpp"

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class NonFiction: public BookComponent {

	private:
		vector<BookComponent*> nfic;
	
	public:
		void display();
		void AddBook(BookComponent* book);
		void Remove(BookComponent* book);


};

