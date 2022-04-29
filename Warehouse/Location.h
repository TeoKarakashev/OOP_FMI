#pragma once
#include <iostream>

class Location {
	char section;
	unsigned shelf;
	unsigned startPosition;
	unsigned endPosition;

public:
	Location();
	Location(char section, unsigned shelf, unsigned startPosition, unsigned endPosition);
	
	friend std::ostream& operator<<(std::ostream& stream, const Location& products);
};
