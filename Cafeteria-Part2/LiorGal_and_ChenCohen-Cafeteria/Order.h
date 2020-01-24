#ifndef __ORDER_H
#define __ORDER_H
#include "Item.h"

class Order
{
public:
	static const int MAX_NUM_OF_ITEMS;
private:
	int id;
	Item** items;
	double totalPrice;
	bool complete = false;
	int currentNumOfItems;

public:
	//c'tor & d'tor
	Order(int id); 
	Order(const Order &order) = delete;
	const Order& operator=(const Order& other);
	~Order();

	// Getters 
	bool getComplete() const;
	int getNumOfItems() const;
	double getTotalPrice() const;
	Item** getItems() const;
	int getId() const;

	// Setters 
	void completeOrder();

	// Methods
	void deleteItem(int itemIndex) throw (const char*);
	void addItem(const Item& item) throw (const char*);
	friend ostream& operator<<(ostream& os, const Order& order);
};

#endif
