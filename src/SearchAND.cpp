#include "../header/SearchAND.hpp"


vector<Book*> SearchAND::search(const BookRepository* b){
    
    vector<Book*> anded;
    
    for(auto it : lhs->search(b)){
        
        if(find(rhs->search(b).begin(), rhs->search(b).end(), it) == rhs->search(b).end()){
                
            anded.emplace_back(it);
            

                
        }
            
    }
    
    
    return anded;

}
