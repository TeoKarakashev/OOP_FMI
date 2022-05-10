#pragma once
#include "MyString.h"
#include "MyDate.h"
#include "Location.h"

//! Entity class for a product that are then stored in the storage
class Product {
	//! name of the product
	MyString name;
	//! entry date of the product
	Date entryDate;
	//! expire date of the product
	Date expireDate;
	//! manufacturer of the product
	MyString manufacturer;
	//! quantity of the product
	size_t quantity;
	//! location of the product
	Location location;
	//! comment of the product
	MyString comment;

public:
	//! Default constructor for the class
	Product();
	//! Constructor with parameters for the class
	Product(const MyString& name, const Date& entryDate, const Date& expireDate,
	const MyString& manufacturer, size_t quantity,const Location& location,  const MyString& comment);
	//! Constructor with parameters for the class
	Product(const MyString& name, const Date& entryDate, const Date& expireDate,
		const MyString& manufacturer, size_t quantity, const MyString& comment);

	//! Setter for name 
	void setName(const MyString& name);
	//! Setter for entry date
	void setEntryDate(const Date& entryDate);
	//! Setter for Expire date
	void setExpireDate(const Date& expireDate);
	//! setter for manufacturer
	void setManufacturer(const MyString& manufacturer);
	//! setter for quantity
	void setQuantity(size_t quantity);
	//! setter for location
	void setLocation(const Location& location);
	//! setter for comment
	void setComment(const MyString& comment);

	//! Getter for name
	const MyString getName() const;
	//! Getter for entry date
	const Date getEntryDate() const;
	//! Getter for expire date
	const Date getExpireDate() const;
	//! Getter for manufacturer
	const MyString getManufacturer() const;
	//! Getter for quantity
	const size_t getQuantity() const;
	//! Getter for location
	const Location getLocation() const;
	//! Getter for comment
	const MyString getComment() const;

	friend std::ostream& operator<<(std::ostream& stream, const Product& products);
};
