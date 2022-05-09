#pragma once
#include "Product.h"
#include "Vector.h"
#include "Log.h"
class Storage {
	Product* products;
	size_t size;
	size_t capacity;

	Log* log;
	size_t logSize;
	size_t logCapacity;

	void copyFrom(const Storage& other);
	void free();
	void resize();
	void resizeLog();

	Product	parse(const MyString& str);
	Vector findAllDelimeters(const MyString& str);
	void assignLocation(Product& product, bool& wasAddedToAnotherProduct);
	Vector findAll(const Product& products);
	Vector findAll(const MyString& name);
	int nextEmptyShelf(char& section);
	void flush();
	bool hasEnoughSpaceOnShelf(const Location& location, const size_t quantity);
	void sortIndexesByExpireDate(Vector& indexes);
	int sumOfProductsQuantity(Vector& indexes);

public:
	Storage();
	Storage(const Storage& other);
	Storage& operator=(const Storage& other);
	~Storage();

	void add(Product& product);
	void addToLog(const Log& product);
	void retrieveData();
	void retrieveProduct(const MyString& name, int quantity);
	void printData();
	void removeAt(int index);
	void cleanUp(Date& date);
	void viewLog(const Date& date1, const Date& date2) const;

	friend std::ostream& operator<<(std::ostream& stream, const Storage& products);
};