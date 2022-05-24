#include <iostream>
#include "Garage.h"

int main() {
	Garage garage;
	garage.addCar("Fiat", 200);
	garage.addTruck("MAN", 100);
	garage.addMinivan("Opel", 130);

	std::cout << garage.getCountOfVehiclesForTrip(300, "highway", 1);
}