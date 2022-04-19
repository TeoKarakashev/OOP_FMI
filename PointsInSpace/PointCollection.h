#pragma once
#include "Point3D.h"
class PointCollection {
	Point3D* points;
	size_t size;
	size_t capacity;

	void free();
	void copyFrom(const PointCollection& other);
	void resize();
	void shiftLeft(int index);
	void shiftRight(int index);

public:
	void add(const Point3D& point);
	PointCollection();
	PointCollection(const PointCollection& other);
	PointCollection& operator=(const PointCollection& other);
	~PointCollection();
	Point3D translate(int index, int x, int y, int z);
	Point3D operator[](int index) const;
	Point3D& operator[](int index);
	PointCollection& operator+=(const PointCollection& other);
	bool add(const Point3D& point, int index);
	bool remove(const Point3D& point, int index);
	size_t getSize() const;
};

PointCollection concat(const PointCollection& col1, const  PointCollection& col2);
