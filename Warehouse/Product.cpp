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

Product::Product(const MyString& name, const Date& entryDate, const Date& expireDate, const MyString& manufacturer, size_t quantity, const MyString& comment) {
	setName(name);
	setEntryDate(entryDate);
	setExpireDate(expireDate);
	setManufacturer(manufacturer);
	setQuantity(quantity);
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
	this->location.setEndPosition(quantity);
}

void Product::setLocation(const Location& location) {
	this->location = location;
}

void Product::setComment(const MyString& comment) {
	this->comment = comment;
}

const MyString Product::getName() const {
	return name;
}

const Date Product::getEntryDate() const {
	return entryDate;
}

const Date Product::getExpireDate() const {
	return expireDate;
}

const MyString Product::getManufacturer() const {
	return manufacturer;
}

const Location Product::getLocation() const {
	return location;
}

const MyString Product::getComment() const {
	return comment;
}

const size_t Product::getQuantity() const
{
	return quantity;
}
 
std::ostream& operator<<(std::ostream& stream, const Product& products) {
	stream << products.name << "|" << products.entryDate << "|" << products.expireDate << "|" << products.manufacturer << "|" << products.quantity << "|" << products.location << "|" << products.comment;
	return stream;
}
