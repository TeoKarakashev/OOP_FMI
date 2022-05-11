#pragma once
#include "Product.h"
#include "Vector.h"
#include "Log.h"

//! Main class that holds all the prodcuts and keeps track of all the updates
class Storage {
	//! List of all Products in the storage
	Product* products;
	//! size of all the products in the storage
	size_t size;
	//! capacity of the storage
	size_t capacity;

	//! List of all logs in the storage
	Log* log;
	//! size of all the logs
	size_t logSize;
	//! capacity of all the logs
	size_t logCapacity;

	//! copies the other storage to the current
	void copyFrom(const Storage& other);
	//! deletes the current storage
	void free();
	//! resizes the procut array if needed
	void resize();
	//! resizes the log array if needed
	void resizeLog();

	//! Pares a prodcut from the database to a value that can be stored 
	Product	parse(const MyString& str);
	//! Helper functuon for finding separators in the file
	Vector findAllDelimeters(const MyString& str) const;
	//! Assings location of the added product acordingly
	void assignLocation(Product& product, bool& wasAddedToAnotherProduct) const;
	//! finds all products by given other products name and expire date
	Vector findAll(const Product& products) const;
	//! finds all products by given name
	Vector findAll(const MyString& name) const;
	//! helper function that finds the next empty shelf in a section
	int nextEmptyShelf(char& section) const;
	//! updates the database after an update
	void flush();
	//! returns whether there is enough space on a given shelf or not
	bool hasEnoughSpaceOnShelf(const Location& location, const size_t quantity) const;
	//! sorts a vector by the expire dates of the products on the indexes
	void sortIndexesByExpireDate(Vector& indexes) const;
	//! returns the sum of procuts with the same name
	int sumOfProductsQuantity(Vector& indexes) const;


public:
	//! default constructor
	Storage();
	//! copy constuctor
	Storage(const Storage& other);
	//! operator =
	Storage& operator=(const Storage& other);
	//! destructor
	~Storage();

	//! adds valid product to the storage
	void add(Product& product);
	//! adds vaid product to the log
	void addToLog(const Log& product);
	//! gets all the data from the data base on load 
	void retrieveData();
	//! removes product by his name and quantity
	void retrieveProduct(const MyString& name, int quantity);
	//! displays all the products and their quantities in the storage
	void printData() const;
	//! removes procuts by its index
	void removeAt(int index);
	//! removes all spoiled products and adds them in an another file
	void cleanUp(Date& date);
	//! displays all the log in a certain period
	void viewLog(const Date& date1, const Date& date2) const;
	//! returns whether the storage is empty or not
	bool isStorageEmpty() const;
	//! returns whether the log is empty or not
	bool isLogEmpty() const;

	//! implementation for the << operator
	friend std::ostream& operator<<(std::ostream& stream, const Storage& products);
};