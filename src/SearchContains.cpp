#include "../header/SearchContains.hpp"

vector<Book*> SearchContains::search(const BookRepository* b){ //verifies it's a right searchBy && searchQuery is correct
    
    if(searchBy == "Author" && (b->getMapAuthor().find(searchQuery) != b->getMapAuthor().end())) return b->getMapAuthor().second; 
    
    else if (searchBy == "Title" && (b->getMapTitle().find(searchQuery) != b->getMapTitle().end())) return b->getMapTitle().second;
    
    else if (searchBY == "Genre"&& (b->getMapGenre().find(searchQuery) != b->getMapGenre().end())) return b->getMapGenre().second;
    
    else vector<string>();
        
    
}

