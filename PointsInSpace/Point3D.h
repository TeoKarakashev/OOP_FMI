#pragma once

class Point3D {
	int x;
	int y;
	int z;

public:
	Point3D();
	Point3D(int x, int y, int z);
	int getX() const;
	int getY() const;
	int getZ() const;
};
