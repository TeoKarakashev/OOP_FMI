#pragma once
#include "MyString.h"
//! Holds values of the given date
class Date {
	//! Year of the date
	unsigned year;
	//! Month of the date
	unsigned month;
	//! Day of the date
	unsigned day;

	//! List of Max days in every month
	int monthList[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	//! helper for switching bettwen characters and intergers
	char numbersList[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }; 

	//! returs whether the given char is a number or not
	bool isNumber(const char ch);
	//! returns the index of a given char in a sequence of chars
	int getIndex(const char ch);
	//! return whether the date is in the right format - YYYY-MM-DD
	bool isValidDate(int year, int month, int day);
public:
	
	//! Default constructor for the class
	Date();

	//! Constructor that takes string and parse it to date
	Date(const MyString& date);
	//! Parses a String to Date
	void parseDate(const MyString& date, int& year, int& month, int& day);
	//! Setter for date
	void setDate(const MyString& date);
	//! Parses Date to String
	MyString toString() const;
	//! returns whether the date is in a week of a given date or before the given date
	bool isComingUp(Date date) const;
	//! Implemetation for the > operator
	bool operator>(const Date& other) const;
	//! Implemetation for the >= operator
	bool operator>=(const Date& other) const;
	//! Implemetation for the == operator
	bool operator==(const Date& other) const;
	//! Implemetation for the += operator
	Date& operator+=(int days);

	//! Implemetation for the << operator
	friend std::ostream& operator<<(std::ostream& stream, const Date& date);
	//! Implemetation for the >> operator
	friend std::istream& operator>>(std::istream& stream, Date& date);
};
