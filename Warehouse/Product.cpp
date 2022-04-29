#include "Product.h"

Product::Product() {
	quantity = 0;
}

Product::Product(const MyString& name, const Date& entryDate, const Date& expireDate,
	const MyString& manufacturer, size_t quantity, const Location& location,  const MyString& comment) {
	setName(name);
	setEntryDate(entryDate);
	setExpireDate(expireDate);
	setManufacturer(manufacturer);
	setQuantity(quantity);
	setLocation(location);
	setComment(comment);
}

void Product::setName(const MyString& name) {
	this->name = name;
}

void Product::setEntryDate(const Date& entryDate) {
	this->entryDate = entryDate;
}

void Product::setExpireDate(const Date& expireDate) {
	this->expireDate = expireDate;
}

void Product::setManufacturer(const MyString& manufacturer) {
	this->manufacturer = manufacturer;
}

void Product::setQuantity(size_t quantity) {
	this->quantity = quantity;
}

void Product::setLocation(const Location& location) {
	this->location = location;
}

void Product::setComment(const MyString& comment) {
	this->comment = comment;
}
 
std::ostream& operator<<(std::ostream& stream, const Product& products) {
	stream << products.name << "|" << products.entryDate << "|" << products.expireDate << "|" << products.manufacturer << "|" << products.quantity << "|" << products.location << "|" << products.comment;
	return stream;
}
