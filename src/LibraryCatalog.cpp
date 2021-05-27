#include "../header/LibraryCatalog.hpp"

void LibraryCatalog::print_search(ostream& out){
        
        BookRepository* b = new BookRepository();
        
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
    
