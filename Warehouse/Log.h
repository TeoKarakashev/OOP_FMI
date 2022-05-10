#pragma once
#include "MyString.h"
#include "MyDate.h"
#include "Location.h"

//! Entity class for the updates on the storage during the lifespan of the application
class Log {

	//! Name of the updated product
	MyString name;
	//! Date of the update
	Date date;
	//! Locatuon of the updated product
	Location location;
	//! Quantity of the updated product
	size_t quantity;
	//! action  of the update add/remove
	MyString command;

public:

	//! Default constructor of the class
	Log();

	//! Constructor with parameters of the class
	Log(const MyString& name, const Date& date, const Location& location, const size_t& quantity, const MyString& command);


	//! Setter for name 
	void setName(const MyString& name);
	//! Setter for Date
	void setDate(const Date& date);
	//! Setter for Location
	void setLocation(const Location& location);
	//! Setter for Quantity
	void setQuantity(const size_t& quantity);
	//! Setter for command
	void setCommand(const MyString& command);

	//! Getter for Date
	const Date& getDate() const;

	//! Implementation for the << operator
	friend std::ostream& operator<<(std::ostream& stream, const Log& log);
};

