#pragma once
#include "Storage.h"

class Controller {

	void printData();
	void addProduct(Storage& storage);
	void retrieveProduct(Storage& storage);
	void printProduct();
	void clearance();
	Product enterProduct();
public:
	void run();

};
