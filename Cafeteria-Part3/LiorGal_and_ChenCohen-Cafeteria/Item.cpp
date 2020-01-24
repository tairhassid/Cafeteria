#include "Item.h"

int Item::ID_GENERATOR = 0;

Item::Item(double price) : price(price), id(ID_GENERATOR++) {}

Item::~Item() {}

double Item::getPrice() const
{
	return price;
}

int Item::getId() const
{
	return id;
}

void Item::setPrice(double price)
{
	this->price = price;
}

void Item::toOs(ostream& os) const {}

ostream& operator<<(ostream& os, const Item& item)
{
	os << "Item index: #" << item.getId() << endl;
	os << typeid(item).name()+6 << " price is " << item.price << " NIS" << endl;
	item.toOs(os);
	return os;
}


