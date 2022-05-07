#pragma once
#include "Storage.h"

class Controller {

	void printData();
	void addProduct(Storage& storage);
	void retrieveProduct(Storage& storage);
	void printProduct();
	void clearance(Storage& storage);
	Product enterProduct();
public:
	void run();

};
