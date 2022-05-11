#pragma once
#include <iostream>

static unsigned MAX_SHELF_SIZE = 1000;
static unsigned MAX_SHLEFS_IN_SECTION = 12;

//! class that stores the location
class Location {
	//! Coresponds to which section the product is
	char section;
	//! Coresponds to which shelf the product is
	unsigned shelf;
	//! Coresponds to the starting position on the given shelf
	unsigned startPosition;
	//! Coresponds to the end position on the given shelf
	unsigned endPosition;

public:
	//! Default constructor for the class
	Location();
	//! Constructor with parameters
	Location(char section, unsigned shelf, unsigned startPosition, unsigned endPosition);

	//! Getter for the section
	const char getSection() const;
	//! Getter for the shelf
	const unsigned getShelf() const;
	//! Getter for the start positon
	const unsigned getStartPosition() const;
	//! Getter for the end position
	const unsigned getEndPosition() const;

	//! Validates end position
	void setEndPosition(unsigned endPosition);
	
	//! Implementation for the << operator
	friend std::ostream& operator<<(std::ostream& stream, const Location& products);
};
