#include "PointCollection.h"
#include <iostream>

int main() {
	PointCollection col;
	Point3D p1(1, 1, 1);
	Point3D p2(2, 1, 1);
	Point3D p3(1, 4, 2);
	col.add(p1);
	col.add(p2);
	col.add(p3);
	Point3D p4 = col.translate(1, 1, 1, 1);
	for (size_t i = 0; i < 1; i++){
		std::cout<<p4.getX()<<" "<<p4.getY() << " "<<p4.getZ() << " ";
	}
}