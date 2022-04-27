#include "Product.h"

Product::Product() {
	quantity = 0;
}

Product::Product(const MyString& name, const MyString& entryDate, const MyString& expireDate, const MyString& manufacturer, size_t quantity, const MyString& comment) {
	this->entryDate.setDate(entryDate);
	this->expireDate.setDate(expireDate);
}
