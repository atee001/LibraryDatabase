
#ifndef LIBRARYSYSTEM_BOOKITEM_H
#define LIBRARYSYSTEM_BOOKITEM_H
#include "Book.h"
#include "Date.h"

class BookItem : public Date {
private:
    Book book;
    Date checkoutDate;
    Date dueDate;
public:
    BookItem(Book book, Date checkOutDate, Date dueDate);
    Date getCheckoutDate();
    void setCheckoutDate(Date checkoutDate);
    Date getDueDate();
    void setDueDate(Date dueDate);
};


#endif //LIBRARYSYSTEM_BOOKITEM_H
