#pragma once
#include "Storage.h"
#include "MyString.h"

//! class that controls the whole warehouse 
class Controller {

	//! Prints all available information from the storage
	void printData(Storage& storage);
	//! adds valid product to the storage
	void addProduct(Storage& storage);
	//! Removes product by name and quantity
	void retrieveProduct(Storage& storage);
	//! Removes all spoiled products and creates new file with them
	void clearance(Storage& storage);
	//! User has to enter a product
	Product enterProduct();
	//! Displayes all the changes to the storage in a given period of time
	void viewLog(Storage& storage);
public:
	//! starts the application
	void run();

};
