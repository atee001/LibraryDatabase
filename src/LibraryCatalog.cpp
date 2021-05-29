#include "../header/LibraryCatalog.hpp"

void LibraryCatalog::print_search(const BookRepository* b, ostream& out){
               
        vector<Book*> result = strat->search(b);
        
        if(result.size() == 0) out << "No Results!" << endl;
        
        else{
            
            for(auto it : result){
            
                out << it->getTitle() << endl;
            
            }
        
        }
        
        delete b;
    
}
    
void LibraryCatalog::set_search(SearchStrat* strat){
        
        this->strat = strat;
        
}
   
 
