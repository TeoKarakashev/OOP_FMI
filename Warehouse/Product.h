#pragma once
#include "MyString.h"
#include "MyDate.h"

class Product {
	MyString name;
	Date expireDate;
	Date entryDate;
	MyString manufacturer;
	size_t quantity;
	MyString location;
	//ToDo figure out how to store the location
	MyString comment;

};
