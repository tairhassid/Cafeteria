#ifndef __MENU_H 
#define __MENU_H 

#include <vector>
#include <string>
#include <iostream>
using namespace std;

#include "IObserver.h"
#include "Item.h"

class Menu
{
public:
	static const int MAX_NUM_OF_ITEMS;
	static const int NUM_OF_ENUM;
	enum eItems{ COFFEE, ICE_CREAM, HOT_CHOCOLATE, HOT_CHOCOLATE_WITH_ICE_CREAM };
	
private:
	vector<string> allItemType;
	eItems itemType;
	vector<IObserver*> viewers;

	//observer design pattern
	void notifyAllRegistered(eItems itemType) const;

public:
	Menu();

	// Getters
	const string& getItemType(int index) const;
	int getNumOfItems() const;

	// Methods
	void operator+=(eItems itemType) throw (const string&);
	bool isItemTypeInMenu(eItems itemType);
	bool isItemInMenu(const Item& item);
	void operator-=(int index);
	const string& operator[](int index);

	friend ostream& operator<<(ostream& os, const Menu& menu);

	//observer design pattern
	void registerObserver(IObserver* obs);

};


#endif // !__MENU_H 
