#include "PointCollection.h"

void PointCollection::free() {
	delete[] points;
}

void PointCollection::copyFrom(const PointCollection& other) {
	points = new Point3D[other.size];
	for (int i = 0; i < other.size; i++) {
		points[i] = other.points[i];
	}
	size = other.size;
	capacity = other.capacity;
}

void PointCollection::resize(){
	capacity *= 2;
	Point3D* temp = new Point3D[capacity];
	for (int i = 0; i < size; i++) {
		temp[i] = points[i];
	}
	free();
	points = temp;
}

void PointCollection::add(const Point3D& point) {
	if (capacity == size) {
		resize();
	}
	points[size++] = point;
}

void PointCollection::shiftLeft(int index){
	for (size_t i = index; i < size-1; i++){
		points[i] = points[i + 1];
	}
}

void PointCollection::shiftRight(int index) {
	for (size_t i = size-1; i > index; i--) {
		points[i+1] = points[i];
	}
}

PointCollection::PointCollection() {
	points = new Point3D[2];
	size = 0;
	capacity = 2;
}

PointCollection::PointCollection(const PointCollection& other) {
	copyFrom(other);	
}

PointCollection& PointCollection::operator=(const PointCollection& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

PointCollection::~PointCollection() {
	free();
}

Point3D PointCollection::translate(int index, int x, int y, int z) { 
	return Point3D(points[index].getX() + x, points[index].getY() + y, points[index].getZ() +z);
}

Point3D PointCollection::operator[](int index) const {
	if (index < 0 || index >= size) {
		throw "Invalid index";
	}
	return points[index];
}

Point3D& PointCollection::operator[](int index) {
	if (index < 0 || index >= size) {
		throw "Invalid index";
	}
	return points[index];
}

PointCollection& PointCollection::operator+=(const PointCollection& other) {
	for (int i = 0; i < other.size; i++) {
		add(other[i]);
	}
	return *this;
}

bool PointCollection::add(const Point3D& point, int index) {
	if (index < 0 || index >= size) {
		return false;
	}
	if (capacity <= size) {
		resize();
	}
	shiftRight(index);
	points[index] = point;
	return true;
}

bool PointCollection::remove(const Point3D& point, int index) {
	if (index < 0 || index >= size) {
		return false;
	}

	shiftLeft(index);
	return true;
}

size_t PointCollection::getSize() const
{
	return size;
}

PointCollection concat(const PointCollection& col1, const PointCollection& col2) {
	PointCollection result(col1);
	result += col2;
	return result;
}
