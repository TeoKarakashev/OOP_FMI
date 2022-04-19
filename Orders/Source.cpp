#include <iostream>
#include "Product.h"
#include "FoodPanda.h"
#include "Order.h"
#include "Restaurant.h"


int main() {
	Product p1("Apple");
	Product p2("Banana");
	Product p3("Steak");
	Product p4("Chicken");
	char name[10] = {"Glovo"};
	char name2[10] = {"Happy"};
	Restaurant r1(name);
	Restaurant r2(name2);
	r1.add(p1);
	r1.add(p2);
	r2.add(p3);
	r2.add(p4);
	Order o1(name);
	FoodPanda foodPanda;
	foodPanda.add(r1);
	foodPanda.add(r2);
	std::cout<<foodPanda.order(o1);
}