#include "Controller.h"

Product Controller::enterProduct() {
	MyString name;
	std::cout << "enter product name: ";
	std::cin >> name;
	Date entryDate;
	std::cout << "enter product entry date in format \"YYYY-MM-DD\": ";
	std::cin >> entryDate;
	Date expireDate;
	std::cout << "enter product expire date in format \"YYYY-MM-DD\": ";
	std::cin >> expireDate;
	while (entryDate > expireDate) {
		std::cout << "Warehouse don't accept spoiled products, enter new expire date in format \"YYYY-MM-DD\": ";
		std::cin >> expireDate;
	}
	MyString manufacturer;
	std::cout << "enter manufacturer name: ";
	std::cin >> manufacturer;
	MyString comment;
	std::cout << "enter comment: ";
	std::cin >> comment;
	size_t quantity;
	std::cout << "enter quantity: ";
	std::cin >> quantity;
	return Product(name, entryDate, expireDate, manufacturer, quantity, comment);
}

void Controller::addProduct(Storage& storage) {
	
	Product p = enterProduct();
	storage.add(p);
}

void Controller::retrieveProduct(Storage& storage) {
	MyString name;
	std::cout << "enter product name: ";
	std::cin >> name;
	size_t quantity;
	std::cout << "enter quantity: ";
	std::cin >> quantity;
	storage.retrieveProduct(name, quantity);
}

void Controller::run() {
	Storage storage;
	storage.retrieveData();
	std::cout << storage;
	addProduct(storage);
	std::cout << storage;
	//retrieveProduct(storage);
}
