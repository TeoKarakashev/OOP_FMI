#include "Log.h"

Log::Log() {
	quantity = 0;
}

Log::Log(const MyString& name, const Date& date, const Location& location, const size_t& quantity, const MyString& command) {
	setName(name);
	setDate(date);
	setLocation(location);
	setQuantity(quantity);
	setCommand(command);
}

void Log::setName(const MyString& name) {
	this->name = name;
}

void Log::setDate(const Date& date) {
	this->date = date;
}

void Log::setLocation(const Location& location) {
	this->location = location;
}

void Log::setQuantity(const size_t& quantity) {
	this->quantity = quantity;
}

void Log::setCommand(const MyString& command) {
	if (command.strcmp("add") == 0 || command.strcmp("remove") == 0) {
		this->command = command;
	}
	else {
		this->command = "unknown";
	}
}

const Date& Log::getDate() const {
	return date;
}

std::ostream& operator<<(std::ostream& stream, const Log& log) {
	stream << log.name << "|" << log.command << "|" << log.quantity << "|" << log.location << "|" << log.date;

	return stream;
}
