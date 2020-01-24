#include "Coffee.h"
#include <vector>
#include <string>

const double Coffee::PRICE = 25;
const vector<string> strengthLevels{"Light", "Normal", "Strong"};
const vector<string> coffeeTypes{ "Nescafe", "Turkish", "Colombian", "Espresso" };

Coffee::Coffee(bool withMilk, double numOfSugar, double temperature, eCupSize cupSize,
	eCoffeeType coffeeType, eStrengthLevel strengthLevel, bool foamy) :
	Item(PRICE), 
	Drink(PRICE, withMilk, numOfSugar, temperature, cupSize),
	coffeeType(coffeeType),
	strengthLevel(strengthLevel),
	foamy(foamy) {}

bool Coffee::getFoamy() const
{
	return foamy;
}

const Coffee::eCoffeeType Coffee::getCoffeeType() const
{
	return coffeeType;
}

const Coffee::eStrengthLevel Coffee::getStrengthLevel() const
{
	return strengthLevel;
}

Item* Coffee::clone() const
{
	return new Coffee(*this);
}

void Coffee::toOs(ostream& os) const
{
	Drink::toOs(os);
	os << "coffeeType: " << coffeeTypes[coffeeType] << endl << "strengthLevel: " 
		<< strengthLevels[strengthLevel] << endl << "creamed: " << boolalpha << foamy << endl;
}