#pragma once
#include "MyString.h"
#include "MyDate.h"
#include "Location.h"

class Product {
	MyString name;
	Date entryDate;
	Date expireDate;
	MyString manufacturer;
	size_t quantity;
	Location location;
	MyString comment;

public:
	Product();
	Product(const MyString& name, const Date& entryDate, const Date& expireDate,
	const MyString& manufacturer, size_t quantity,const Location& location,  const MyString& comment);

	Product(const MyString& name, const Date& entryDate, const Date& expireDate,
		const MyString& manufacturer, size_t quantity, const MyString& comment);

	void setName(const MyString& name);
	void setEntryDate(const Date& entryDate);
	void setExpireDate(const Date& expireDate);
	void setManufacturer(const MyString& manufacturer);
	void setQuantity(size_t quantity);
	void setLocation(const Location& location);
	void setComment(const MyString& comment);

	MyString getName() const;
	Date getEntryDate() const;
	Date getExpireDate() const;
	MyString getManufacturer() const;
	size_t getQuantity() const;
	Location getLocation() const;
	MyString getComment() const;

	friend std::ostream& operator<<(std::ostream& stream, const Product& products);
};
