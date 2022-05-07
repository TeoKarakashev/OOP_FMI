#include "Storage.h"
#include <fstream>
#include <iostream>

void Storage::copyFrom(const Storage& other) {
	products = new Product[other.capacity];
	for (int i = 0; i < other.size; i++) {
		add(other.products[i]);
	}
	size = other.size;
	capacity = other.capacity;
}

void Storage::free() {
	delete[] products;
}

void Storage::resize() {
	capacity *= 2;
	Product* temp = new Product[capacity];
	for (int i = 0; i < size; i++) {
		temp[i] = products[i];
	}
	free();
	products = temp;
}

Product Storage::parse(const MyString& str) {
	Vector delimeters = findAllDelimeters(str);;
	MyString name = str.substr(0, delimeters[0]);
	Date entryDate(str.substr(delimeters[0] + 1, delimeters[1]));
	Date expireDate(str.substr(delimeters[1] + 1, delimeters[2]));
	MyString manufacturer = str.substr(delimeters[2] + 1, delimeters[3]);
	size_t quantity = str.atoi(str.substr(delimeters[3] + 1, delimeters[4]));
	char section = str.substr(delimeters[4] + 1, delimeters[5])[0];
	unsigned shelf = str.atoi(str.substr(delimeters[5] + 1, delimeters[6]));
	unsigned startPos = str.atoi(str.substr(delimeters[6] + 1, delimeters[7]));//ToDO make it volume
	unsigned endPos = str.atoi(str.substr(delimeters[7] + 1, delimeters[8]));
	Location location(section, shelf, startPos, endPos);
	MyString comment = str.substr(delimeters[8] + 1, str.getSize());
	return Product(name, entryDate, expireDate, manufacturer, quantity, location, comment);
}

Vector Storage::findAllDelimeters(const MyString& str) {
	Vector delimeters;
	for (size_t i = 0; i < str.getSize(); i++) {
		if (str[i] == '|') {
			delimeters.add(i);
		}
	}
	return delimeters;
}

void Storage::assignLocation(Product& product, bool& wasAddedToAnotherProduct) {
	Vector indexes = findAll(product);
	if (!indexes.isEmpty()) {
		for (int i = 0; i < indexes.getSize(); i++) {
			if (hasEnoughSpaceOnShelf(products[indexes[i]].getLocation(), product.getQuantity())) {
				products[indexes[i]].setQuantity(products[indexes[i]].getQuantity() + product.getQuantity());
				wasAddedToAnotherProduct = true;
				break;
			}
		}
	}
	if (!wasAddedToAnotherProduct) {
		char section = product.getName().toUpper(product.getName()[0]);
		unsigned shelf = nextEmptyShelf(section);
		unsigned startPos = 1;
		unsigned endPos = product.getQuantity();
		Location loc(section, shelf, startPos, endPos);
		product.setLocation(loc);
	}
}

Vector Storage::findAll(const Product& product) {
	Vector indexes;
	for (int i = 0; i < size; i++) {
		if (products[i].getName().strcmp(product.getName()) == 0 &&
			products[i].getExpireDate() == product.getExpireDate()) {
			indexes.add(i);
		}
	}
	return indexes;
}


Vector Storage::findAll(const MyString& name) {
	Vector indexes;
	for (int i = 0; i < size; i++) {
		if (products[i].getName().strcmp(name) == 0) {
			indexes.add(i);
		}
	}
	return indexes;
}

int Storage::nextEmptyShelf(char& section)
{
	int count = 1;
	for (int i = 0; i < size; i++) {
		if (products[i].getLocation().getSection() == section) {
			count++;
		}
		if (count > MAX_SHLEFS_IN_SECTION) {
			count = 1;
			section++;
			i = 0;
		}
	}
	return count;
}

void Storage::flush() {
	std::ofstream database("storage.txt", std::ios::trunc);
	if (!database.is_open()) {
		throw "failed to open database";
	}
	for (int i = 0; i < size; i++) {
		database << products[i].getName() << "|" << products[i].getEntryDate() << "|"
			<< products[i].getExpireDate() << "|" << products[i].getManufacturer() << "|"
			<< products[i].getQuantity() << "|" << products[i].getLocation().getSection() << "|"
			<< products[i].getLocation().getShelf() << "|" << products[i].getLocation().getStartPosition() << "|"
			<< products[i].getLocation().getEndPosition() << "|" << products[i].getComment();
		if (i != size - 1) {
			database << std::endl;
		}
	}
}

bool Storage::hasEnoughSpaceOnShelf(const Location& location, const size_t quantity) {
	return quantity <= MAX_SHELF_SIZE - location.getEndPosition();
}

void Storage::sortIndexesByExpireDate(Vector& indexes) {
	for (int i = 0; i < indexes.getSize(); i++) {
		int minIndex = i;
		for (int j = i; j < indexes.getSize(); j++) {
			if (products[indexes[minIndex]].getExpireDate() > products[indexes[j]].getExpireDate()) {
				minIndex = j;
			}
		}
		indexes.swap(indexes[i], indexes[minIndex]);
	}
}

int Storage::sumOfProductsQuantity(Vector& indexes) {
	int sum = 0;
	for (int i = 0; i < indexes.getSize(); i++) {
		sum += products[indexes[i]].getQuantity();
	}
	return sum;
}




Storage::Storage() {
	products = new Product[2];
	size = 0;
	capacity = 2;
}

Storage::Storage(const Storage& other) {
	copyFrom(other);
}

Storage& Storage::operator=(const Storage& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Storage::~Storage() {
	free();
}

void Storage::add(Product& product) {
	bool wasAddedToAnotherProduct = false;

	if (size == capacity) {
		resize();
	}
	if (product.getLocation().getSection() == '-') {
		assignLocation(product, wasAddedToAnotherProduct);
	}
	if (!wasAddedToAnotherProduct) {
		products[size++] = product;
	}
	flush();
}

void Storage::retrieveData() {
	std::ifstream database("storage.txt");
	if (!database.is_open()) {
		throw "failed to load data from database";
	}
	char buffer[1024];
	while (!database.eof()) {
		database.getline(buffer, 1024);
		Product p = parse(buffer);
		if (size == capacity) {
			resize();
		}
		products[size++] = p;
	}
}

void Storage::retrieveProduct(const MyString& name, int quantityToTakeOut) {
	Vector indexes = findAll(name);
	if (indexes.isEmpty()) {
		throw "no product with such name!";
	}
	sortIndexesByExpireDate(indexes);
	int sumOfProductsQuantity = this->sumOfProductsQuantity(indexes);
	bool command = false;
	if (sumOfProductsQuantity < quantityToTakeOut) {
		std::cout << "There are only " << sumOfProductsQuantity << " products left of this type: " << std::endl;
		for (int i = 0; i < indexes.getSize(); i++) {
			std::cout << products[indexes[i]] << std::endl;
		}
		std::cout << "Do you want to take out whats left?" << std::endl;
		std::cout << "type: 1 - yes		type: 0 - no" << std::endl;
		std::cin >> command;
		if (command) {
			for (int i = 0; i < indexes.getSize(); i++) {
				products[indexes[i]].setQuantity(0);
			}
		}
	}
	else {
		int currentProduct = 0;
		while (quantityToTakeOut > 0) {
			if (products[indexes[currentProduct]].getQuantity() <= quantityToTakeOut) {
				quantityToTakeOut -= products[indexes[currentProduct]].getQuantity();
				products[indexes[currentProduct]].setQuantity(0);
			}
			else {
				products[indexes[currentProduct]].setQuantity(products[indexes[currentProduct]].getQuantity() - quantityToTakeOut);
				quantityToTakeOut -= products[indexes[currentProduct]].getQuantity();
			}
			currentProduct++;
		}
	}
	if (command) {
		for (int i = size - 1; i >= 0; i--) {
			if (products[i].getQuantity() == 0) {
				removeAt(i);
			}
		}
		flush();
	}
}

void Storage::removeAt(int index) {
	if (index < 0 || index >= size)
		throw "no such index";
	for (int i = index; i < size - 1; i++) {
		products[i] = products[i + 1];
	}
	size--;
}

void Storage::cleanUp(Date& date) {
	Vector indexes;
	for (int i = 0; i < size; i++) {
		if (date > products[i].getExpireDate() || products[i].getExpireDate().isComingUp(date)) {
			indexes.add(i);
		}
	}
	MyString name("cleanup-");
	name.strcat(date.toString());
	name.strcat(".txt");
	std::ofstream database(name.getVals());
	if (!database.is_open()) {
		throw "failed to open file";
	}
	for (int i = 0; i < indexes.getSize(); i++) {
		database << products[indexes[i]] << std::endl;;
	}
	for (int i = indexes.getSize() - 1; i >= 0; i--) {
		removeAt(indexes[i]);
	}
	flush();
	std::cout << "expiring products were removed and saved in file with name: " << name << std::endl;

}
std::ostream& operator<<(std::ostream& stream, const Storage& storage) {
	for (int i = 0; i < storage.size; i++) {
		stream << storage.products[i] << std::endl;
	}
	return stream;
}
