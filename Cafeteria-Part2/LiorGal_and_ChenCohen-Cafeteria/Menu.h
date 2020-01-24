#ifndef __MENU_H 
#define __MENU_H 

#include <iostream>
using namespace std;

#include "Item.h"

class Menu
{
public:
	static const int MAX_NUM_OF_ITEMS;
	static const int NUM_OF_ENUM;
	enum eItems{ COFFEE, ICE_CREAM, HOT_CHOCOLATE, HOT_CHOCOLATE_WITH_ICE_CREAM };
	
private:
	char** allItemType;
	int currentNumOfItems;
	eItems itemType;


public:
	Menu();
	Menu(const Menu& other);
	const Menu& operator=(const Menu& other);
	~Menu();

	// Getters
	int getCurrentNumOfItems() const;
	const char* getItemType(int index) const;

	// Methods
	void operator+=(eItems itemType) throw (const char*);
	bool isItemTypeInMenu(eItems itemType);
	bool isItemInMenu(const Item& item);
	void operator-=(int index);
	const char* operator[](int index);

	friend ostream& operator<<(ostream& os, const Menu& menu);
};


#endif // !__MENU_H 
