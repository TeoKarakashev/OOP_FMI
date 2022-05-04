#include "Controller.h"

void Controller::addProduct(Storage& storage) {
	int* delimeters = new int[9];
	MyString name;
	std::cout << "enter product name: ";
	std::cin >> name;
	Date entryDate;
	std::cout << "enter product entry date in format \"YYYY-MM-DD\": ";
	std::cin >> entryDate;
	Date expireDate;
	std::cout << "enter product expire date in format \"YYYY-MM-DD\": ";
	std::cin >> expireDate;
	while (entryDate > expireDate){
		std::cout << "Warehouse don't accept spoiled products, enter new expire date om format \"YYYY-MM-DD\": ";
		std::cin >> expireDate;
	}
	MyString manufacturer;
	std::cout << "enter manufacturer name: ";
	std::cin >> manufacturer;
	size_t quantity;
	std::cout << "enter quantity: ";
	std::cin>>quantity;
	MyString comment;
	std::cout << "enter comment: ";
	std::cin >> comment;
	Product p(name, entryDate, expireDate, manufacturer, quantity, comment);
	storage.add(p);
}

void Controller::run() {
	Storage storage;
	storage.retrieveData();
	std::cout << storage;
	addProduct(storage);
	std::cout << storage;
}
