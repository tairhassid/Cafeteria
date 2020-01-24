#define _CRT_SECURE_NO_WARNINGS

#include "Cafeteria.h"

const int Cafeteria::MAX_ORDERS = 10;
const int Cafeteria::MAX_SELLERS = 5;

Cafeteria::Cafeteria(const string& name, const CoffeeMachine& coffeeMachine, const Menu& menu) :
	 coffeeMachine(coffeeMachine), menu(menu), name(name)
{}


Cafeteria& Cafeteria::getInstance(const string& name, const CoffeeMachine& coffeeMachine, const Menu& menu)
{
	static Cafeteria theCafeteria(name, coffeeMachine, menu);
	return theCafeteria;
}


const vector<Order*>& Cafeteria::getAllOrders() const
{
	return orders;
}

const vector<Seller*>& Cafeteria::getAllSellers() const
{
	return sellers;
}

int Cafeteria::getNumOfOrders() const
{
	return orders.size();
}

const Date& Cafeteria::getFilterLastCleaned() const
{
	return coffeeMachine.getFilter().getLastCleaned();
}

const Date& Cafeteria::getCoffeeMachineLastMaintained() const
{
	return coffeeMachine.getLastMaintained();
}

const string& Cafeteria::getName() const
{
	return name;
}

void Cafeteria::showMenu() const
{
	cout << menu << endl;
}

void Cafeteria::addSeller(Seller& seller) 
{
	sellers.push_back(&seller);
	menu.registerObserver(&seller);
}

void Cafeteria::deleteSeller(const string& name, int seniority) throw (const string&)
{
	vector<Seller*>::const_iterator itrStart = sellers.begin();
	vector<Seller*>::const_iterator itrEnd = sellers.end();


	for (; itrStart != itrEnd; ++itrStart)
	{
		if (((*itrStart)->getName() == name) && ((*itrStart)->getSeniority() == seniority))
		{
			sellers.erase(itrStart);
			return;
		}
	}

	throw string("No such seller found");
}

void Cafeteria::addItemToMenu(Menu::eItems itemType) throw (const string&)
{
	menu += itemType;
}

void Cafeteria::removeItemFromMenu(int index)
{
	menu -= index;
}

int Cafeteria::addOrder() throw (const string&)
{
	if(menu.getNumOfItems() == 0)
		throw string("The menu is empty, there is nothing you can order!");
	if(sellers.size() == 0)
		throw string("There are no sellers, you can't order");

	orders.push_back(new Order());
	Order* lastOrder = orders.back();
	return lastOrder->getId();
}

void Cafeteria::deleteItemFromOrder(int orderIndex, int itemIndex) throw (const string&)
{
	orders[orderIndex]->deleteItem(itemIndex);
}

void Cafeteria::addItemToOrder(int orderIndex, const Item& item)
{
	if (!menu.isItemInMenu(item))
		throw string("We don't server this item, choose one from the menu");
	orders[orderIndex]->addItem(item);

	const Coffee* temp = dynamic_cast<const Coffee*>(&item);
	if (temp != NULL)
	{
		coffeeMachine.prepareCoffee(*temp);
	}
}

void Cafeteria::completeOrder(int orderIndex)
{
		orders[orderIndex]->completeOrder();
}

const void Cafeteria::cancelOrder(int orderIndex) throw (const string&)
{
	if (orderIndex < 0 || orderIndex >= orders.size())
		throw string("Order doesn't exist");

	orders.erase(orders.begin() + orderIndex);

	vector<Order*>::const_iterator itrStart = orders.begin();
	vector<Order*>::const_iterator itrEnd = orders.end();

	for (int i = 0; itrStart != itrEnd; ++itrStart, i++)
	{
		(*itrStart)->setId(i);
	}
	Order::ID_GENERATOR--;
}


Order& Cafeteria::operator[](int orderIndex) const
{
	return *(orders[orderIndex]);
}

const string& Cafeteria::getItemType(int index) const
{
	return menu.getItemType(index);
}

void Cafeteria::showOrderHistory() const
{
	vector<Order*>::const_iterator itrStart = orders.begin();
	vector<Order*>::const_iterator itrEnd = orders.end();

	for (; itrStart != itrEnd; ++itrStart)
	{
		cout << *(*itrStart) << endl;
	}
}