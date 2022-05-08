#pragma once
#include "MyString.h"
#include "MyDate.h"
#include "Location.h"

class Log {

	MyString name;
	Date date;
	Location location;
	size_t quantity;
	MyString command;

public:
	Log();
	Log(const MyString& name, const Date& date, const Location& location, const size_t& quantity, const MyString& command);

	void setName(const MyString& name);
	void setDate(const Date& date);
	void setLocation(const Location& location);
	void setQuantity(const size_t& quantity);
	void setCommand(const MyString& command);

	friend std::ostream& operator<<(std::ostream& stream, const Log& log);
};

