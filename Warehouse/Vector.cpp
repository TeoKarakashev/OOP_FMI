#include "Vector.h"

void Vector::resize() {
	capacity *= 2;
	int* newArr = new int[capacity];
	for (int i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}
	free();
	arr = newArr;
}

void Vector::free() {
	delete[] arr;
}

void Vector::copyFrom(const Vector& other) {
	size = other.size;
	capacity = other.capacity;
	arr = new int[capacity];
	for (int i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}
}

Vector::Vector() {
	arr = new int[2];
	capacity = 2;
	size = 0;
}

Vector::Vector(const Vector& other)
{
	copyFrom(other);
}

Vector& Vector::operator=(const Vector& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Vector::~Vector() {
	free();
}

void Vector::swap(int& i1, int& i2) {
	int temp = i2;
	i2 = i1;
	i1 = temp;
}

void Vector::add(const int element)
{
	if (capacity == size) {
		resize();
	}
	arr[size] = element;
	size++;
}

void Vector::deleteAll() {
	free();
	arr = new int[2];
	size = 0;
	capacity = 2;
}

const int Vector::getSize() const
{
	return size;
}

int& Vector::operator[](const int index)
{
	if (index >= 0 && index < size) {
		return arr[index];
	}
	throw std::exception("Out of range exception");

}

const int& Vector::operator[](const int index) const
{
	if (index >= 0 && index < size) {
		return arr[index];
	}
	throw std::exception("Out of range exception");
}

bool Vector::deleteAt(int index) {
	if (index < 0 || index >= size)
		return false;
	for (int i = index; i < size - 1; i++) {
		arr[i] = arr[i + 1];
	}
	size--;
	return true;
}

void Vector::sort() {
	for (int i = 0; i < size; i++) {
		int minIndex = i;
		for (int j = i; j < size; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);
	}
}

bool Vector::isEmpty() {
	return size == 0;
}



