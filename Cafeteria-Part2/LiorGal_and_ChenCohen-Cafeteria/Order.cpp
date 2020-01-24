#include "Order.h"
#include "Coffee.h"

const int Order::MAX_NUM_OF_ITEMS = 10;

Order::Order(int id) : totalPrice(0), id(id)
{
	currentNumOfItems = 0;
	items = new Item*[MAX_NUM_OF_ITEMS];
}

const Order& Order::operator=(const Order& other)
{
	if (this != &other)
	{
		for (int i = 0; i < currentNumOfItems; i++)
		{
			delete items[i];
		}
		delete[]items;

		id = other.id;
		totalPrice = other.totalPrice;
		complete = other.complete;
		currentNumOfItems = other.currentNumOfItems;
		items = new Item*[MAX_NUM_OF_ITEMS];

		for (int i = 0; i < currentNumOfItems; i++)
		{
			items[i] = other.items[i]->clone();
		}
	}
	return *this;
}

Order::~Order()
{
	for (int i = 0; i < currentNumOfItems; i++)
	{
		delete items[i];
	}
	delete[]items;
}

bool Order::getComplete() const
{
	return complete;
}

int Order::getNumOfItems() const
{
	return currentNumOfItems;
}

double Order::getTotalPrice() const
{
	return totalPrice;
}

Item** Order::getItems() const
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


void Order::deleteItem(int itemIndex) throw (const char*)
{
	//array has 1 element
	if (currentNumOfItems == 1)
	{
		totalPrice -= items[currentNumOfItems - 1]->getPrice();
		delete items[--currentNumOfItems];
		return;
	}

	Item** newItems = new Item*[currentNumOfItems - 1];

	for (int i = 0; i < currentNumOfItems; i++)
	{
		if (items[i]->getId() == itemIndex)
		{
			totalPrice -= items[i]->getPrice();

			for (int j = i; j < currentNumOfItems - 1; j++)
			{
				newItems[j] = items[j + 1]->clone();
			}
			delete[] items;
			currentNumOfItems--;
			items = newItems;
			return;
		}
		else
		{
			newItems[i] = items[i]->clone();
		}
	}
	throw "No such item exists!";
}

void Order::addItem(const Item& item)  throw (const char*) //item has to be const. if not- we will have access to it from main
{
	if (complete)
		throw "Can't add item to a completed order!";
	if (currentNumOfItems < MAX_NUM_OF_ITEMS)
	{
		items[currentNumOfItems++] = item.clone();
		totalPrice += item.getPrice();

	}
	else
		throw "You've reached max number of items!";
}

ostream& operator<<(ostream& os, const Order& order)
{
	os << "Order #" << order.id << ":\n";
	for (int i = 0; i < order.currentNumOfItems; i++)
	{
		os << "Item index: #" << order.items[i]->getId() << endl << *(order.items[i]) << endl;
	}
	os << "\nTotal price is " << order.totalPrice << " NIS\n";
	return os;
}


