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
	int* delimeters = new int[9];
	findAllDelimeters(str, delimeters);
	MyString name = str.substr(0, delimeters[0]);
	Date entryDate(str.substr(delimeters[0] + 1, delimeters[1]));
	Date expireDate(str.substr(delimeters[1] + 1, delimeters[2]));
	MyString manufacturer = str.substr(delimeters[2] + 1, delimeters[3]);
	size_t quantity = str.atoi(str.substr(delimeters[3] + 1, delimeters[4]));
	char section = str.substr(delimeters[4] + 1, delimeters[5])[0];
	unsigned shelf = str.atoi(str.substr(delimeters[5] + 1, delimeters[6]));
	unsigned startPos = str.atoi(str.substr(delimeters[6] + 1, delimeters[7]));
	unsigned endPos = str.atoi(str.substr(delimeters[7] + 1, delimeters[8]));
	Location location(section, shelf, startPos, endPos);
	MyString comment = str.substr(delimeters[8] + 1, str.getSize());
	delete[] delimeters;
	return Product(name, entryDate, expireDate, manufacturer, quantity, location, comment);
}

int* Storage::findAllDelimeters(const MyString& str, int*& arr) {
	int arrSize = 0;
	for (size_t i = 0; i < str.getSize(); i++) {
		if (str[i] == '|') {
			arr[arrSize++] = i;
		}
		if (arrSize == 9) {
			return arr;
		}
	}
	return arr;
}

void Storage::assignLocation(Product& product, bool& wasAddedToAnotherProduct) {
	int index = contains(product);
	if (index != -1 && hasEnoughSpaceOnShelf(products[index].getLocation(), product.getQuantity())) {
		products[index].setQuantity(products[index].getQuantity() + product.getQuantity());
		wasAddedToAnotherProduct = true;
	}
	else {
		char section = product.getName().toUpper(product.getName()[0]);
		unsigned shelf = nextEmptyShelf(section);
		unsigned startPos = 1;
		unsigned endPos = product.getQuantity();
		Location loc(section, shelf, startPos, endPos);
		product.setLocation(loc);
	}
}
//should find last one
int Storage::contains(const Product& product) {
	for (int i = 0; i < size; i++) {
		if (products[i].getName().strcmp(product.getName()) == 0) {
			if (products[i].getExpireDate() == product.getExpireDate()) {
				return i;
			}
		}
	}
	return -1;
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
	//ToDo
}

bool Storage::hasEnoughSpaceOnShelf(const Location& location, const size_t quantity) {
	return quantity <= MAX_SHELF_SIZE - location.getEndPosition();
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
		throw "failed to load data from data base";
	}
	char buffer[1024];
	while (!database.eof()) {
		database.getline(buffer, 1024);
		Product p = parse(buffer);
		add(p);
	}
}

std::ostream& operator<<(std::ostream& stream, const Storage& storage) {
	for (int i = 0; i < storage.size; i++) {
		stream << storage.products[i] << std::endl;
	}
	return stream;
}
