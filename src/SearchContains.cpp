#include "../header/SearchContains.hpp"

vector<Book*> SearchContains::search(const BookRepository* b){ //verifies it's a right searchBy && searchQuery is correct
    
    if(searchBy == "Author" && (b->getMapAuthor().find(searchQuery) != b->getMapAuthor().end())) return b->getMapAuthor().at(searchQuery); 
    
    else if (searchBy == "Title" && (b->getMapTitle().find(searchQuery) != b->getMapTitle().end())) return b->getMapTitle().at(searchQuery);
    
    else if (searchBy == "Genre"&& (b->getMapGenre().find(searchQuery) != b->getMapGenre().end())) return b->getMapGenre().at(searchQuery);
    
    return vector<Book*>();
        
    
}

