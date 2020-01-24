#include "HotChocolateWithIceCream.h"

HotChocolateWithIceCream::HotChocolateWithIceCream(const HotChocolate& hotChocholate, const IceCream& iceCream) :
	Item(HotChocolate::PRICE),
	Drink(hotChocholate.PRICE, hotChocholate.getWithMilk(), hotChocholate.getNumOfSugar(),
		hotChocholate.getNumOfSugar(), hotChocholate.getCupSize()),
	HotChocolate(hotChocholate),
	IceCream(iceCream) {}

bool HotChocolateWithIceCream::getWithWhippedCream() const
{
	return whippedCream;
}

bool HotChocolateWithIceCream::getWithCherry() const
{
	return cherry;
}

void HotChocolateWithIceCream::addWhippedCream()
{
	if (!whippedCream)
		whippedCream = true;
}
void HotChocolateWithIceCream::addCherry()
{
	if (!cherry)
		cherry = true;
}

void HotChocolateWithIceCream::toOs(ostream& os) const
{
	Drink::toOs(os);
	if (whippedCream)
		os << "Whipped cream on top" << endl;
	if (cherry)
		os << "Cherry on top" << endl;
}

Item* HotChocolateWithIceCream::clone() const
{
	return new HotChocolateWithIceCream(*this);
}
