#include "Controller.h"

void Controller::clearance(Storage& storage) {
	Date cleanUpDate;
	std::cout << "enter date in format \"YYYY-MM-DD\": ";
	std::cin >> cleanUpDate;
	storage.cleanUp(cleanUpDate);

}

Product Controller::enterProduct() {
	Date entryDate;
	std::cout << "enter product entry date in format \"YYYY-MM-DD\": ";
	std::cin >> entryDate;
	MyString name;
	std::cout << "enter product name: ";
	std::cin >> name;
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
	size_t quantity;
	std::cout << "enter quantity: ";
	std::cin >> quantity;
	MyString comment;
	std::cout << "enter comment: ";
	std::cin >> comment;
	return Product(name, entryDate, expireDate, manufacturer, quantity, comment);
}

void Controller::viewLog(Storage& storage) {
	Date dateBefore;
	std::cout << "enter first date in format \"YYYY-MM-DD\": ";
	std::cin >> dateBefore;
	Date dateAfter;
	std::cout << "enter second date in format \"YYYY-MM-DD\": ";
	std::cin >> dateAfter;
	storage.viewLog(dateBefore, dateAfter);
}

void Controller::printData(Storage& storage) {
	std::cout << storage;
}

void Controller::addProduct(Storage& storage) {

	Product p = enterProduct();
	storage.add(p);
	Log l(p.getName(), p.getEntryDate(), p.getLocation(), p.getQuantity(), "add");
	storage.addToLog(l);
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
	try {
		storage.retrieveData();
	}
	catch (const std::exception& er) {
		std::cout << "failed to load db";
		return;
	}
	std::cout << "storage was successfully loaded!" << std::endl;
	MyString command;
	std::cout << "Possible commands:" << std::endl;
	std::cout << "add - adds product to the warehouse" << std::endl;
	std::cout << "remove - removes product from the warehouse by quantity" << std::endl;
	std::cout << "clearence - removes all spoiled products and those who are close to expirining" << std::endl;
	std::cout << "print - gives you information about everything in the warehouse" << std::endl;
	std::cout << "log - gives you information about all changes between two dates" << std::endl;
	std::cout << "close - shut downs the application" << std::endl;
	std::cin >> command;
	while (!(command == "close")) {
		try {
			if (command == "add") {
				addProduct(storage);
				std::cout << "product was added successfully!" << std::endl;
			}
			else if (command == "remove") {
				retrieveProduct(storage);
				std::cout << "products were removed successfully!" << std::endl;
			}
			else if (command == "clearence") {
				clearance(storage);
			}
			else if (command == "print") {
				printData(storage);
			}
			else if (command == "log") {
				viewLog(storage);
			}
			else {
				std::cout << "Inalid command!" << std::endl;
			}
		}
		catch (const std::exception& er) {
			std::cout << er.what() << std::endl;
			std::cout << "command was not executed!" << std::endl;
		}
		std::cout << "enter new command: ";
		std::cin >> command;
	}


}
