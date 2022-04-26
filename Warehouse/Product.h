#pragma once
#include "MyString.h"
#include "MyDate.h"
#include "Location.h"

class Product {
	MyString name;
	Date entryDate;
	Date expireDate;
	MyString manufacturer;
	size_t quantity;
	Location location;
	//ToDo figure out how to store the location
	MyString comment;

public:
	Product();
	Product(const MyString& name, const MyString& entryDate, const MyString& expireDate, const MyString& manufacturer, size_t quantity, const MyString& comment);
};
