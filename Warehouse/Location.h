#pragma once
#include <iostream>

static unsigned MAX_SHELF_SIZE = 100;
static unsigned MAX_SHLEFS_IN_SECTION = 1;

class Location {
	char section;
	unsigned shelf;
	unsigned startPosition;
	unsigned endPosition;

public:
	Location();
	Location(char section, unsigned shelf, unsigned startPosition, unsigned endPosition);

	char getSection() const;
	unsigned getShelf() const;
	unsigned getStartPosition() const;
	unsigned getEndPosition() const;

	void setEndPosition(unsigned endPosition);
	
	friend std::ostream& operator<<(std::ostream& stream, const Location& products);
};
