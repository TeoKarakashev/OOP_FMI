#pragma once
#include "Storage.h"
#include "MyString.h"

class Controller {

	void printData(Storage& storage);
	void addProduct(Storage& storage);
	void retrieveProduct(Storage& storage);
	void clearance(Storage& storage);
	Product enterProduct();
	void viewLog(Storage& storage);
public:
	void run();

};
