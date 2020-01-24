#ifndef __ITEM_H
#define __ITEM_H

#include <iostream>
using namespace std;

class Item
{
public:
	static int ID_GENERATOR;
protected:
	int id;
	double price;

	// c'tors
	Item(double price);

public:
	virtual ~Item();

	// Getters
	double getPrice() const;
	int getId() const;

	// Setters
	void setPrice(double price);

	// Operators
	friend ostream& operator<<(ostream& os, const Item& item);

	// Methods
	virtual void toOs(ostream& os) const;
	virtual Item* clone() const = 0;
};

#endif 


