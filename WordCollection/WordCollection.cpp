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
	if (capacity = size) {
		resize();
	}
	if (size == 0) {
		words[size++] = word;
	}
	else {
		int index = getCorrectIndexToAddWord(word);
		if (index >= 0) {
			shiftRight(index);
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

void WordCollection::shiftRight(int index) {
	for (int i = size - 1; i >= index; i--){
		words[i+1] = words[i];
	}
}

void WordCollection::shiftLeft(int index) {
	for (int i = index; i < size - 1; i++) {
		words[i] = words[i+1];
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

bool WordCollection::contains(const char* word, int& index) const
{
	int fromIndex = 0;
	int toIndex = size - 1;
	int midIndex = 0;
	while (fromIndex <= toIndex) {
		midIndex = fromIndex + (toIndex - fromIndex) / 2;
		if (words[midIndex] == word) {
			index = midIndex;
			return true;
		}

		if (words[midIndex] < word) {
			fromIndex = midIndex + 1;
		}
		else {
			toIndex = midIndex - 1;
		}
	}
	index = -1;
	return false;
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

MyString& WordCollection::operator[](int index) {
	if (index >= size)
		throw "Invalid index";

	return words[index];
}

MyString WordCollection::operator[](int index) const {
	if (index >= size)
		throw "Invalid index";

	return words[index];
}

bool WordCollection::operator[](const char* str) const {
	int index = 0;
	return contains(str, index);
}

WordCollection& WordCollection::operator+=(const WordCollection& collection2) {
	for (int i = 0; i < collection2.size; i++){
		add(collection2[i]);
	}
	return *this;
}

WordCollection& WordCollection::operator-=(const WordCollection& collection2) {
	for (int i = 0; i < collection2.size; i++){
		*this /= collection2[i].getStr();
	}
	return *this;
}

WordCollection& WordCollection::operator*=(const MyString& word) {
	add(word);
	return *this;
}

WordCollection& WordCollection::operator/=(const char* word) {
	int index = 0;
	if (contains(word, index)) {
		shiftLeft(index);
		size--;
	}
	return *this;
}

WordCollection& WordCollection::operator<<(const char* word) {
	add(word);
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const WordCollection& collection)
{
	stream << "{ ";
	for (size_t i = 0; i < collection.size; i++) {
		stream << collection[i] << " ";
	}
	stream << "}";
	return stream;
}

std::istream& operator>>(std::istream& stream, WordCollection& collection) {
	MyString word;
	std::cin >> word;
	collection.add(word);
	return stream;
}

WordCollection operator+(const WordCollection& collection1, const WordCollection& collection2) {
	WordCollection result(collection1);
	result += collection2;
	return result;
}

WordCollection operator-(const WordCollection& collection1, const WordCollection& collection2) {
	WordCollection result(collection1);
	result -= collection2;
	return result;
}
