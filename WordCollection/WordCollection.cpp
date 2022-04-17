#include "WordCollection.h"
#include <iostream>

void WordCollection::free() {
	delete[] words;
}

void WordCollection::copyFrom(const WordCollection& other) {
	words = new MyString[other.size];
	for (int i = 0; i < other.size; i++) {
		words[i] = other.words[i];
	}
	size = other.size;
	capacity = other.capacity;
}

void WordCollection::resize() {
	capacity *= 2;
	MyString* temp = new MyString[capacity];
	for (int i = 0; i < size; i++)
	{
		temp[i] = words[i];
	}
	free();
	words = temp;
}

void WordCollection::add(const MyString& word) {
	if (size == 0) {
		words[size++] = word;
	}
	else {
		int index = getCorrectIndexToAddWord(word);
		if (index >= 0) {
			shift(index);
			words[index] = word;
			size++;
		}
	}
}

int WordCollection::getCorrectIndexToAddWord(const MyString& word) {
	int fromIndex = 0;
	int toIndex = size - 1;
	int midIndex = 0;
	bool isHiger = false;
	while (fromIndex <= toIndex) {
		midIndex = fromIndex + (toIndex - fromIndex) / 2;
		if (words[midIndex] == word) {
			return -1;
		}

		if (words[midIndex] < word) {
			fromIndex = midIndex + 1;
			isHiger = true;
		}
		else {
			toIndex = midIndex - 1;
			isHiger = false;
		}
	}
	if (isHiger) {
		return midIndex + 1;
	}
	return midIndex;
}

void WordCollection::shift(int index) {
	for (int i = size - 1; i >= index; i--){
		words[i+1] = words[i];
	}
}

WordCollection::WordCollection() {
	words = new MyString[2];
	capacity = 2;
	size = 0;
}

WordCollection::WordCollection(const WordCollection& other) {
	copyFrom(other);
}

WordCollection& WordCollection::operator=(const WordCollection& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

WordCollection::~WordCollection() {
	free();
}

MyString& WordCollection::operator[](size_t index)
{
	if (index >= size)
		throw "Invalid index";

	return words[index];
}

MyString WordCollection::operator[](size_t index) const
{
	if (index >= size)
		throw "Invalid index";

	return words[index];
}

bool WordCollection::operator[](const char* str) const
{
	int fromIndex = 0;
	int toIndex = size - 1;
	int midIndex = 0;
	while (fromIndex <= toIndex) {
		midIndex = fromIndex + (toIndex - fromIndex) / 2;
		if (words[midIndex] == str) {
			return true;
		}

		if (words[midIndex] < str) {
			fromIndex = midIndex + 1;
		}
		else {
			toIndex = midIndex - 1;
		}
	}
	return false;
}

WordCollection& WordCollection::operator+=(const WordCollection& colection2) {
	for (int i = 0; i < colection2.size; i++){
		this->add(colection2[i]);
	}
	return *this;
}

WordCollection& WordCollection::operator*=(const MyString& word) {
	if (capacity <= size) {
		resize();
	}
	add(word);
	return *this;
}

size_t WordCollection::getSize() const
{
	return size;
}


std::ostream& operator<<(std::ostream& stream, const WordCollection& colection)
{
	size_t size = colection.getSize();
	stream << "{ ";
	for (size_t i = 0; i < size; i++) {
		stream << colection[i] << " ";
	}
	stream << "}";
	return stream;
}

WordCollection operator+(const WordCollection& collection1, const WordCollection& collection2)
{
	WordCollection result(collection1);
	result += collection2;
	return result;
}
