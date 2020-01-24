#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <iostream>
using namespace std;

const int Menu::MAX_NUM_OF_ITEMS = 30;
const int Menu::NUM_OF_ENUM = 4;
const char* itemTypes[] = { "Coffee", "Hot Chocolate", "Ice Cream", "Hot Chocolate With Ice Cream" };

Menu::Menu() : currentNumOfItems(0)
{
	allItemType = new char*[MAX_NUM_OF_ITEMS];
}

Menu::Menu(const Menu& other)
{
	*this = other;
}

const Menu& Menu::operator=(const Menu& other)
{
	if (this != &other)
	{
		for (int i = 0; i < currentNumOfItems; i++)
		{
			delete allItemType[i];
		}
		delete[] allItemType;

		currentNumOfItems = other.currentNumOfItems;
		itemType = other.itemType;
		allItemType = new char*[MAX_NUM_OF_ITEMS];

		for (int i = 0; i < currentNumOfItems; i++)
		{
			allItemType[i] = _strdup(other.allItemType[i]);
		}
	}
	return *this;
}

Menu::~Menu()
{
	for (int i = 0; i < currentNumOfItems; i++)
	{
		delete allItemType[i];
	}
	delete[] allItemType;
}

int Menu::getCurrentNumOfItems() const
{
	return currentNumOfItems;
}

const char* Menu::getItemType(int index) const
{
	return itemTypes[index];
}

/*add item to menu*/
void Menu::operator+=(eItems itemType) throw (const char*)
{
	if (!isItemTypeInMenu(itemType))
	{
		if (currentNumOfItems < MAX_NUM_OF_ITEMS)
			allItemType[currentNumOfItems++] = _strdup(itemTypes[itemType]);
		else
			throw "You've reached max number of items!";
	}
	else
		throw "The Item is already in the menu";
}

/*Checks if the item type is already in the menu- so we can't add it twice*/
bool Menu::isItemTypeInMenu(eItems itemType)
{
	for (int i = 0; i < currentNumOfItems; i++)
	{
		if (strcmp(allItemType[i], itemTypes[itemType]) == 0)
			return true;
	}
	return false;
}

/*Checks if the item we want to order is offered in our menu (means we added it to menu)*/
bool Menu::isItemInMenu(const Item& item)
{
	const char* itemName = typeid(item).name() + 6;
	int size = strlen(itemName);;
	bool flag = false;

	for (int i = 0; i < currentNumOfItems; i++)
	{
		int itemTypeLen = strlen(allItemType[i]);
		if (itemTypeLen >= size)
		{
			flag = true;

			for (int j = 0, k = 0; j < itemTypeLen || k < size ; j++)
			{
				if (allItemType[i][j] == ' ')
					continue;
				if (allItemType[i][j] != itemName[k])
				{
					flag = false;
					break;
				}
				k++;
			}
		}
		if (flag)
			return flag;
	}
	return flag;
}

void Menu::operator-=(int index)
{
	for (int i = index; i < currentNumOfItems - 1; i++)
	{
		allItemType[i] = allItemType[i + 1];
	}
	delete allItemType[--currentNumOfItems];
}

const char* Menu::operator[](int index)
{
	return allItemType[index];
}

ostream& operator<<(ostream& os, const Menu& menu)
{
	if (menu.currentNumOfItems == 0)
		os << "The menu is currently empty" << endl;
	else
	{
		os << "Menu:" << endl;

		for (int i = 0; i < menu.currentNumOfItems; i++)
		{
			os << menu.allItemType[i] << endl;
		}
	}
	return os;
}