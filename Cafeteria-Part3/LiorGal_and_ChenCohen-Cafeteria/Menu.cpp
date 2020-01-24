#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <algorithm>

const int Menu::MAX_NUM_OF_ITEMS = 30;
const int Menu::NUM_OF_ENUM = 4;
const string itemTypes[] = { "Coffee", "Hot Chocolate","Ice Cream", "Hot Chocolate With Ice Cream" };

Menu::Menu()  {}


const string& Menu::getItemType(int index) const
{
	return itemTypes[index];
}

int Menu::getNumOfItems() const
{
	return allItemType.size();
}

/*add item to menu*/
void Menu::operator+=(eItems itemType) throw (const string&)
{
	if (!isItemTypeInMenu(itemType))
	{
		if (allItemType.size() < MAX_NUM_OF_ITEMS)
		{
			allItemType.push_back(itemTypes[itemType]);
			notifyAllRegistered(itemType);
		}
		else
			throw string("You've reached max number of items!");
	}
	else
		throw string("The Item is already in the menu");
}

/*Checks if the item type is already in the menu- so we can't add it twice*/
bool Menu::isItemTypeInMenu(eItems itemType)
{
	for (int i = 0; i < allItemType.size(); i++)
	{
		if (allItemType[i] == itemTypes[itemType])
			return true;
	}
	return false;
}

///*Checks if the item we want to order is offered in our menu (means we added it to menu)*/
bool Menu::isItemInMenu(const Item& item)
{
	string temp;

	for (int i = 0; i < allItemType.size(); i++)
	{
		temp = allItemType[i];
		temp.erase(remove_if(temp.begin(), temp.end(), isspace), temp.end());

		if ((typeid(item).name() + 6) == temp)
			return true;
	}
	return false;
}

void Menu::operator-=(int index)
{
	allItemType.erase(allItemType.begin() + index);
}

const string& Menu::operator[](int index)
{
	return allItemType[index];
}

ostream& operator<<(ostream& os, const Menu& menu)
{
	os << "Menu:" << endl;

	vector<string>::const_iterator itrStart = menu.allItemType.begin();
	vector<string>::const_iterator itrEnd = menu.allItemType.end();

	for (; itrStart != itrEnd ; ++itrStart)
	{
		os << *itrStart << endl;
	}
	return os;
}

void Menu::registerObserver(IObserver* obs)
{
	cout << "Registerd " << obs->getName() << endl;
	viewers.push_back(obs);
}

void Menu::notifyAllRegistered(eItems itemType) const
{
	int size = viewers.size();
	string type = itemTypes[itemType];
	for (int i = 0; i < size; i++)
	{
		viewers[i]->notify(type);
	}
}