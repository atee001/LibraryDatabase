
#pragma once 

#include "BookComponent.hpp"

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Fiction: public BookComponent {

	private:
		vector<BookComponent*> fic;
	
	public:
		void display();
		void AddBook(BookComponent* book);
		void RemoveBook(BookComponent* book);


};
