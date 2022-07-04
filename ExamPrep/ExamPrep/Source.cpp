#include <iostream>
#include "SurfAndTurf.h"
#include "Dish.h"
#include "MeatDish.h"
#include "SeafoodDish.h"
#include "IngredientsNames.h"
int main() {

	 Dish* seaDish = new SeaFoodDish("Salmon", 150);
	 seaDish->addIngredient("water");
	 seaDish->addIngredient("salt");
	 Dish* meatDish = new MeatDish("beef", 120);
	 meatDish->addIngredient("potatoes");
	 meatDish->addIngredient("onion");
	 meatDish->addIngredient("water");
	SurfAndTurf surfAndTurf;
	surfAndTurf.addDish(seaDish);
	surfAndTurf.addDish(meatDish);
	surfAndTurf.printAll();
}