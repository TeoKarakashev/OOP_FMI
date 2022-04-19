#include "Point3D.h"

Point3D::Point3D(){
	x = 0;
	y = 0;
	z = 0;
}

Point3D::Point3D(int x, int y, int z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

int Point3D::getX() const
{
	return  x;
}

int Point3D::getY() const
{
	return  y;
}

int Point3D::getZ() const
{
	return  z;
}