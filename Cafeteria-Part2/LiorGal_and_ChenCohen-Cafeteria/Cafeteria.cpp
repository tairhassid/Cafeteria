#define _CRT_SECURE_NO_WARNINGS

#include "Cafeteria.h"

const int Cafeteria::MAX_ORDERS = 10;
const int Cafeteria::MAX_SELLERS = 5;

Cafeteria::Cafeteria(const char* name, const CoffeeMachine& coffeeMachine, const Menu& menu) :
	name(NULL), coffeeMachine(coffeeMachine), menu(menu), currentNumOfOrders(0), currentNumOfSellers(0)
{
	setName(name);
	sellers = new Seller*[MAX_SELLERS];
	orders = new Order*[MAX_ORDERS];
}

Cafeteria::~Cafeteria()
{
	for (int i = 0; i < currentNumOfSellers; i++)
	{
		delete sellers[i];
	}

	for (int i = 0; i < currentNumOfOrders; i++)
	{
		delete orders[i];
	}

	delete[] sellers;
	delete[] orders;
	delete name;
}

Order** Cafeteria::getAllOrders() const
{
	return orders;
}

Seller** Cafeteria::getAllSellers() const
{
	return sellers;
}

int Cafeteria::getNumOfOrders() const
{
	return currentNumOfOrders;
}

int Cafeteria::getNumOfSellers() const
{
	return currentNumOfSellers;
}

const Date& Cafeteria::getFilterLastCleaned() const
{
	return coffeeMachine.getFilter().getLastCleaned();
}

const Date& Cafeteria::getCoffeeMachineLastMaintained() const
{
	return coffeeMachine.getLastMaintained();
}

const char* Cafeteria::getName() const
{
	return name;
}

void Cafeteria::setName(const char* newName)
{
	delete[] name;
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
}

void Cafeteria::showMenu() const
{
	cout << menu << endl;
}

void Cafeteria::addSeller(const Seller& seller) throw (const char*)
{
	if (currentNumOfSellers < MAX_SELLERS)
	{
		(sellers[currentNumOfSellers++]) = new Seller(seller);
	}
	else
		throw "You've reached max number of sellers!";
}

void Cafeteria::deleteSeller(const char* name, int seniority) throw (const char*)
{
	for (int i = 0; i < currentNumOfSellers; i++)
	{
		if (strcmp(sellers[i]->getName(), name) == 0 && sellers[i]->getSeniority() == seniority)
		{
			updateSellers(i);
			return;
		}
	}
	throw "No such seller found";
}

void Cafeteria::updateSellers(int index)
{
	for (int i = index; i < currentNumOfSellers-1; i++)
	{
		*sellers[i] = *sellers[i + 1];
	}
	delete sellers[--currentNumOfSellers];
}

void Cafeteria::addItemToMenu(Menu::eItems itemType) throw (const char*)
{
	menu += itemType;
}

void Cafeteria::removeItemFromMenu(int index)
{
	menu -= index;
}

int Cafeteria::addOrder() throw (const char*)
{
	if (menu.getCurrentNumOfItems() == 0)
		throw "The menu is empty, there is nothing you can order!";
	if (currentNumOfSellers == 0)
		throw "There are no sellers, you can't order";
	if (currentNumOfOrders < MAX_ORDERS)
	{
		orders[currentNumOfOrders++] = new Order(currentNumOfOrders);
		return currentNumOfOrders - 1;
	}
	throw "You've reached max number of orders!";
}

void Cafeteria::deleteItemFromOrder(int orderIndex, int itemIndex) throw (const char*)
{
	orders[orderIndex]->deleteItem(itemIndex);
}

void Cafeteria::addItemToOrder(int orderIndex, const Item& item) throw (const char*)
{
	if (!menu.isItemInMenu(item))
		throw "We don't server this item, choose one from the menu";
	orders[orderIndex]->addItem(item);

	const Coffee* temp = dynamic_cast<const Coffee*>(&item);
	if (temp != NULL)
	{
		coffeeMachine.prepareCoffee(*temp);
	}
}

Item** Cafeteria::completeOrder(int orderIndex)
{
	orders[orderIndex]->completeOrder();
	return orders[orderIndex]->getItems();
}

const void Cafeteria::cancelOrder(int orderIndex) throw (const char*)
{
	if (orderIndex < 0 || orderIndex >= currentNumOfOrders)
		throw "Order doesn't exist";

	for (int i = orderIndex; i < currentNumOfOrders - 1; i++)
	{
		*orders[i] = *orders[i + 1];
	}
	delete orders[--currentNumOfOrders];
}


Order& Cafeteria::operator[](int orderIndex) const
{
	return *(orders[orderIndex]);
}

const char* Cafeteria::getItemType(int index) const
{
	return menu.getItemType(index);
}