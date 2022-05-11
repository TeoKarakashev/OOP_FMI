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

	log = new Log[other.logCapacity];
	for (int i = 0; i < other.logSize; i++) {
		addToLog(other.log[i]);
	}
	logSize = other.logSize;
	logCapacity = other.logCapacity;
}

void Storage::free() {
	delete[] products;
	delete[] log;
}

void Storage::resize() {
	capacity *= 2;
	Product* temp = new Product[capacity];
	for (int i = 0; i < size; i++) {
		temp[i] = products[i];
	}
	delete[] products;
	products = temp;
}

void Storage::resizeLog() {
	logCapacity *= 2;
	Log* temp = new Log[logCapacity];
	for (int i = 0; i < logSize; i++) {
		temp[i] = log[i];
	}
	delete[] log;
	log = temp;
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
	unsigned startPos = str.atoi(str.substr(delimeters[6] + 1, delimeters[7]));
	unsigned endPos = str.atoi(str.substr(delimeters[7] + 1, delimeters[8]));
	Location location(section, shelf, startPos, endPos);
	MyString comment = str.substr(delimeters[8] + 1, str.getSize());
	return Product(name, entryDate, expireDate, manufacturer, quantity, location, comment);
}

Vector Storage::findAllDelimeters(const MyString& str) const {
	Vector delimeters;
	for (size_t i = 0; i < str.getSize(); i++) {
		if (str[i] == '|') {
			delimeters.add(i);
		}
	}
	return delimeters;
}

void Storage::assignLocation(Product& product, bool& wasAddedToAnotherProduct) const {
	Vector indexes = findAll(product);
	if (!indexes.isEmpty()) {
		for (int i = 0; i < indexes.getSize(); i++) {
			if (hasEnoughSpaceOnShelf(products[indexes[i]].getLocation(), product.getQuantity())) {
				products[indexes[i]].setQuantity(products[indexes[i]].getQuantity() + product.getQuantity());
				product.setLocation(products[indexes[i]].getLocation());
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

Vector Storage::findAll(const Product& product) const {
	Vector indexes;
	for (int i = 0; i < size; i++) {
		if (products[i].getName().strcmp(product.getName()) == 0 &&
			products[i].getExpireDate() == product.getExpireDate()) {
			indexes.add(i);
		}
	}
	return indexes;
}


Vector Storage::findAll(const MyString& name) const {
	Vector indexes;
	for (int i = 0; i < size; i++) {
		if (products[i].getName().strcmp(name) == 0) {
			indexes.add(i);
		}
	}
	return indexes;
}

int Storage::nextEmptyShelf(char& section) const {
	Vector shelfs;
	int count = 1;
	for (int i = 0; i < size; i++) {
		if (products[i].getLocation().getSection() == section) {
			shelfs.add(products[i].getLocation().getShelf());
			count++;
		}
		if (count > MAX_SHLEFS_IN_SECTION) {
			shelfs.deleteAll();
			count = 1;
			section++;
			i = 0;
		}
	}
	if (shelfs.isEmpty()) {
		return 1;
	}
	shelfs.sort();
	for (int i = 0; i < shelfs.getSize(); i++) {
		if (shelfs[i] != i + 1) {
			return (i + 1);
		}
	}
	return shelfs.getSize() + 1;
}

void Storage::flush() {
	std::ofstream database("storage.txt", std::ios::trunc);
	if (!database.is_open()) {
		throw std::exception("failed to open database");
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

bool Storage::hasEnoughSpaceOnShelf(const Location& location, const size_t quantity) const {
	return quantity <= MAX_SHELF_SIZE - location.getEndPosition();
}

void Storage::sortIndexesByExpireDate(Vector& indexes) const {
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

int Storage::sumOfProductsQuantity(Vector& indexes) const {
	int sum = 0;
	for (int i = 0; i < indexes.getSize(); i++) {
		sum += products[indexes[i]].getQuantity();
	}
	return sum;
}

bool Storage::isStorageEmpty() const {
	return size == 0;
}

bool Storage::isLogEmpty() const {
	return logSize == 0;
}


Storage::Storage() {
	products = new Product[2];
	size = 0;
	capacity = 2;

	log = new Log[2];
	logSize = 0;
	logCapacity = 2;

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
	if (product.getQuantity() > MAX_SHELF_SIZE) {
		throw std::exception("Product is too big and cannot be added");
	}
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

void Storage::addToLog(const Log& curr) {
	if (logSize == logCapacity) {
		resizeLog();
	}
	log[logSize++] = curr;
}

void Storage::retrieveData() {
	std::ifstream database("storage.txt");
	if (!database.is_open()) {
		throw std::exception("failed to load data from database");
	}
	char buffer[1024];
	while (!database.eof()) {
		database.getline(buffer, 1024);
		if (buffer[0] != '\0') {
			Product p = parse(buffer);
			if (size == capacity) {
				resize();
			}
			products[size++] = p;
		}
	}
}

void Storage::retrieveProduct(const MyString& name, int quantityToTakeOut) {
	Vector indexes = findAll(name);
	if (indexes.isEmpty()) {
		throw std::exception("no product with such name!");
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
				Log l(products[indexes[i]].getName(), products[indexes[i]].getExpireDate(),
					products[indexes[i]].getLocation(), products[indexes[i]].getQuantity(), "remove");
				addToLog(l);
				products[indexes[i]].setQuantity(0);
			}
		}
	}
	else {
		int currentProduct = 0;
		while (quantityToTakeOut > 0) {
			if (products[indexes[currentProduct]].getQuantity() <= quantityToTakeOut) {
				Log l(products[indexes[currentProduct]].getName(), products[indexes[currentProduct]].getExpireDate(),
					products[indexes[currentProduct]].getLocation(), products[indexes[currentProduct]].getQuantity(), "remove");
				addToLog(l);
				quantityToTakeOut -= products[indexes[currentProduct]].getQuantity();
				products[indexes[currentProduct]].setQuantity(0);
				command = true;
			}
			else {
				Log l(products[indexes[currentProduct]].getName(), products[indexes[currentProduct]].getExpireDate(),
					products[indexes[currentProduct]].getLocation(), quantityToTakeOut, "remove");
				addToLog(l);
				size_t newQuantity = products[indexes[currentProduct]].getQuantity() - quantityToTakeOut;
				quantityToTakeOut -= products[indexes[currentProduct]].getQuantity();
				products[indexes[currentProduct]].setQuantity(newQuantity);
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
	}
	flush();
}

void Storage::printData() const {
	Vector* indexesWithSameNames = new Vector[size];
	int sizeOfArray = 0;
	for (int i = 0; i < size; i++) {
		bool wasAdded = false;
		for (int j = 0; j < sizeOfArray; j++) {
			if (products[i].getName() == products[indexesWithSameNames[j][0]].getName()) {
				indexesWithSameNames[j].add(i);
				wasAdded = true;
			}
		}
		if (!wasAdded) {
			indexesWithSameNames[sizeOfArray++].add(i);
		}
	}

	for (int i = 0; i < sizeOfArray; i++) {
		std::cout << products[indexesWithSameNames[i][0]].getName() << "|" << sumOfProductsQuantity(indexesWithSameNames[i]) << std::endl;
	}

	delete[] indexesWithSameNames;
}

void Storage::removeAt(int index) {
	if (index < 0 || index >= size)
		throw std::exception("no such index");
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
		throw std::exception("failed to open file");
	}
	for (int i = 0; i < indexes.getSize(); i++) {
		database << products[indexes[i]] << std::endl;;
	}
	for (int i = indexes.getSize() - 1; i >= 0; i--) {
		Log l(products[indexes[i]].getName(), products[indexes[i]].getExpireDate(),
			products[indexes[i]].getLocation(), products[indexes[i]].getQuantity(), "remove");
		addToLog(l);
		removeAt(indexes[i]);
	}
	flush();
	std::cout << "expiring products were removed and saved in file with name: " << name << std::endl;

}
void Storage::viewLog(const Date& date1, const Date& date2) const {
	for (int i = 0; i < logSize; i++) {
		if (log[i].getDate() >= date1 && date2 >= log[i].getDate()) {
			std::cout << log[i] << std::endl;
		}
	}
}
std::ostream& operator<<(std::ostream& stream, const Storage& storage) {
	if (storage.isStorageEmpty()) {
		throw std::exception("Storage is empty!");
	}
	for (int i = 0; i < storage.size; i++) {
		stream << storage.products[i] << std::endl;
	}
	return stream;
}