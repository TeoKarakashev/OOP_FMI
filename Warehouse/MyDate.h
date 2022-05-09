#pragma once
#include "MyString.h"

class Date {
	unsigned year;
	unsigned month;
	unsigned day;

	int monthList[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	char numbersList[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }; 

	bool isNumber(const char ch);
	int getIndex(const char ch);
	bool isValidDate(int year, int month, int day);
public:
	Date();
	Date(const MyString& date);
	void parseDate(const MyString& date, int& year, int& month, int& day);
	void setDate(const MyString& date);
	MyString toString();
	bool isComingUp(Date date) const;
	bool operator>(const Date& other) const;
	bool operator>=(const Date& other) const;
	bool operator==(const Date& other) const;
	Date& operator+=(int days);

	friend std::ostream& operator<<(std::ostream& stream, const Date& date);
	friend std::istream& operator>>(std::istream& stream, Date& date);
};
