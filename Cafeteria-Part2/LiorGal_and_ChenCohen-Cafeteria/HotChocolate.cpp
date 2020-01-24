#include "Drink.h"
#include "HotChocolate.h"

const double HotChocolate::PRICE = 20;
const double HotChocolate::PRICE_PER_MARSHMALLOW = 1;

HotChocolate::HotChocolate(bool withMilk, double numOfSugar, double temperature
	, int numOfMarshmallows, eCupSize cupSize) : Item(PRICE + (PRICE_PER_MARSHMALLOW*numOfMarshmallows)), Drink(PRICE, withMilk, numOfSugar, temperature, cupSize), numOfMarshmallows(numOfMarshmallows)
{
	setPrice(numOfMarshmallows);
}

int HotChocolate::getNumOfMarshmalows() const
{
	return numOfMarshmallows;
}

double HotChocolate::getPrice() const
{
	return price;
}

void HotChocolate::setNumOfMarshmallows(int num)
{
	this->numOfMarshmallows = num;
	price = PRICE + (PRICE_PER_MARSHMALLOW*numOfMarshmallows);
}

/*The base price is PRICE but the final price depends on how many marshmallows were added*/
void HotChocolate::setPrice(int numOfMarshmallows)
{
	price = PRICE + (PRICE_PER_MARSHMALLOW*numOfMarshmallows);
}

Item* HotChocolate::clone() const
{
	return new HotChocolate(*this);
}

void HotChocolate::toOs(ostream& os) const
{
	Drink::toOs(os);
	os << "Num of marshmallows is " << numOfMarshmallows << "\n";
}

HotChocolate::~HotChocolate() {}
