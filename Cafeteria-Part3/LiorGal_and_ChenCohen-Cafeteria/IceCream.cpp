#include "IceCream.h"


const double IceCream::PRICE_PER_SCOOP = 5;
const vector<string> flavors{ "Chocolate", "Vanilla", "Cherry", "Banana" };

IceCream::IceCream(eFlavor flavor, int numOfScoops) : Item(PRICE_PER_SCOOP*numOfScoops), 
	flavor(flavor), numOfScoops(numOfScoops) {}

IceCream::eFlavor IceCream::getFlavor() const
{
	return flavor;
}

int IceCream::getNumOfScoops() const
{
	return numOfScoops;
}

Item* IceCream::clone() const
{
	return new IceCream(*this);
}

void IceCream::toOs(ostream& os) const
{
	os << numOfScoops << " scoops " << flavors[flavor] << " flavored" << endl; 
}

IceCream::~IceCream() {}

