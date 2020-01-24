#include "Order.h"
#include "Coffee.h"

const int Order::MAX_NUM_OF_ITEMS = 10;
int Order::ID_GENERATOR = 0;

Order::Order() : totalPrice(0), items(), id(ID_GENERATOR++) {}


bool Order::getComplete() const
{
	return complete;
}

double Order::getTotalPrice() const
{
	return totalPrice;
}

const MyLinkedList<Item*>& Order::getItems() const
{
	return items;
}

int Order::getId() const
{
	return id;
}

void Order::completeOrder()
{
	complete = true;
}

void Order::setId(int id)
{
	this->id = id;
}

void Order::deleteItem(int itemIndex) throw (const string&)
{
	Item* data = items.removeItem(itemIndex);
	totalPrice -= data->getPrice();
}

void Order::addItem(const Item& item)  //item has to be const. if not- we will have access to it from main
{
	if (complete)
		throw "Can't add item to a completed order!";
	items.insertLast(item.clone());
	totalPrice += item.getPrice();
}

ostream& operator<<(ostream& os, const Order& order)
{
	os << "Order #" << order.id << ":\n";
	order.getItems().print();
	os << "\nTotal price is " << order.totalPrice << " NIS\n";
	return os;
}


