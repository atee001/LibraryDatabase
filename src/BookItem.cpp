
#include "../header/BookItem.h"

BookItem::BookItem(Book book, Date checkOutDate, Date dueDate)  {
    this->book = book;
    this->checkoutDate = checkOutDate;
    this->dueDate = dueDate;
}

void BookItem::setCheckoutDate(Date aDate) {
    checkoutDate.setDay(aDate.getDay());
    checkoutDate.setMonth(aDate.getMonth());
    checkoutDate.setYear(aDate.getYear());
}

Date BookItem::getCheckoutDate() {
    return checkoutDate;
}


void BookItem::setDueDate(Date dueDate) {
    dueDate.setDay(dueDate.getDay());
    dueDate.setMonth(dueDate.getMonth());
    dueDate.setYear(dueDate.getYear());
}

