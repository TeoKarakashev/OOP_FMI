#pragma once
#include "Product.h"
#include "Vector.h"

class Storage {
	Product* products;
	size_t size;
	size_t capacity;
	friend class Controller;

	void copyFrom(const Storage& other);
	void free();
	void resize();
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
	void retrieveData();
	void retrieveProduct(const MyString& name, int quantity);
	void removeAt(int index);

	friend std::ostream& operator<<(std::ostream& stream, const Storage& products);
};