

#pragma once

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class BookComponent {
	private:

	public:
		virtual void display() = 0;
		virtual void AddBook(BookComponent* book);
		virtual RemoveBook(BookComponent* book);
	
};
