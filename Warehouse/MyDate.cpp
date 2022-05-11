#include "MyDate.h"

bool Date::isNumber(const char ch)
{
	return ch >= '0' && ch <= '9';
}

int Date::getIndex(const char ch) {
	for (int i = 0; i < 10; i++) {
		if (numbersList[i] == ch) {
			return i;
		}
	}
	return -1;
}

bool Date::isValidDate(int year, int month, int day) {
	if (year % 4 == 0) {
		monthList[1] = 29;
	}
	if (month > 12) {
		return false;
	}
	if (day > monthList[month - 1]) {
		return false;
	}
	return true;
}

Date::Date() {
	year = 0;
	month = 0;
	day = 0;
}

Date::Date(const MyString& date) {
	year = 0;
	month = 0;
	day = 0;
	setDate(date);
}

void Date::setDate(const MyString& date) {
	int year = 0;
	int month = 0;
	int day = 0;

	parseDate(date, year, month, day);

	if (isValidDate(year, month, day)) {
		this->year = year;
		this->month = month;
		this->day = day;
	}
	else {
		throw std::exception("date must be valid");
	}
}

MyString Date::toString() const {
	MyString str("YYYY-MM-DD");
	int holder = year;
	for (int i = 3; i >= 0; i--){
		str.replaceAt(i ,numbersList[holder % 10]);
		holder /= 10;
	}
	holder = month;
	for (int i = 6; i >= 5; i--) {
		str.replaceAt(i, numbersList[holder % 10]);
		holder /= 10;
	}
	holder = day;
	for (int i = 9; i >= 8; i--) {
		str.replaceAt(i, numbersList[holder % 10]);
		holder /= 10;
	}
	return str;
}

bool Date::isComingUp(Date date) const {
	date += 5;
	if (date > *this) {
		return true;
	}
	return false;
}



bool Date::operator>(const Date& other) const{
	if (this->year > other.year) {
		return true;
	}
	else if (this->year < other.year) {
		return false;
	}
	else {
		if (this->month > other.month) {
			return true;
		}
		else if (this->month < other.month) {
			return false;
		}
		else {
			if (this->day > other.day) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

bool Date::operator>=(const Date& other) const{
	if (this->year > other.year) {
		return true;
	}
	else if (this->year < other.year) {
		return false;
	}
	else {
		if (this->month > other.month) {
			return true;
		}
		else if (this->month < other.month) {
			return false;
		}
		else {
			if (this->day > other.day) {
				return true;
			}
			else if(this->day < other.day) {
				return false;
			}
			else {
				return true;
			}
		}
	}
}

bool Date::operator==(const Date& other) const {
	if (year == other.year && month == other.month && day == other.day) {
		return true;
	}
	return false;
}

Date& Date::operator+=(int days) {
	if (days + day > monthList[month]) {
		if (month = 12) {
			month = 1;
			year++;
		}
		else {
			month++;
		}
		this->day = days - (monthList[month] - this->day);
	}
	this->day += days;

	return *this;
}

void Date::parseDate(const MyString& date, int& year, int& month, int& day) {

	for (int i = 0; i < 10; i++) {
		if (i == 4 || i == 7) {
			continue;
		}
		if (!isNumber(date[i])) {
			throw std::exception("date must be valid");
		}
		if (i < 4) {
			year *= 10;
			year += getIndex(date[i]);
		}
		else if (i < 7) {
			month *= 10;
			month += getIndex(date[i]);
		}
		else {
			day *= 10;
			day += getIndex(date[i]);
		}
	}
}

std::ostream& operator<<(std::ostream& stream, const Date& date)
{
	stream << date.year << "-";
	if (date.month < 10) {
		stream << "0";
	}
	stream << date.month << "-";
	if (date.day < 10) {
		stream << "0";
	}
	stream << date.day;
	return stream;
}

std::istream& operator>>(std::istream& stream, Date& date)
{
	MyString str;
	std::cin >> str;
	date.setDate(str);
	return stream;
}
