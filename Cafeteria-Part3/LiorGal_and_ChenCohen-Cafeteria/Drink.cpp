#include "Drink.h"
#include <vector>
#include <string>

const vector<string> cupSizes{ "Small", "Medium", "Large" };

Drink::Drink(double price, bool withMilk, double numOfSugar, double temperature, eCupSize cupSize) :
	Item(price), 
	withMilk(withMilk), 
	temperature(temperature), 
	cupSize(cupSize),
	numOfSugar(numOfSugar) {}

Drink::~Drink() {}

Drink::eCupSize Drink::getCupSize() const
{
	return cupSize;
}

bool Drink::getWithMilk() const
{
	return withMilk;
}

double Drink::getNumOfSugar() const
{
	return numOfSugar;
}

double Drink::getTemperature() const
{
	return temperature;
}

Item* Drink::clone() const
{
	return new Drink(*this);
}

void Drink::toOs(ostream& os) const
{
	os << "withMilk: " << boolalpha << withMilk << endl << "numOfSugar: " << numOfSugar << endl
		<< "temprature: " << temperature << endl << "cupSize: " << cupSizes[cupSize] << endl;
}