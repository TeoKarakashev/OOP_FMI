#pragma once

class Date {
	unsigned year;
	unsigned month;
	unsigned day;
	int monthArray[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

public:
	Date();
	Date(int year, int month, int day);

};
