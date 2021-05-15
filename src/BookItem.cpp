#include "BookItem.hpp"

BookItem::BookItem() {

}
BookItem::BookItem(Date checkOutDate, Date dueDate)  {
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


void BookItem::setDueDate(Date dDate) {
    dueDate.setDay(dDate.getDay());
    dueDate.setMonth(dDate.getMonth());
    dueDate.setYear(dDate.getYear());
}
