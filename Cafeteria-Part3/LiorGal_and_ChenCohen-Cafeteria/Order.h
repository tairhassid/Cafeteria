#ifndef __ORDER_H
#define __ORDER_H
#include "Item.h"
#include "MyLinkedList.h"
#include <vector>

class Order
{
public:
	static const int MAX_NUM_OF_ITEMS;
	static int ID_GENERATOR;
private:
	int id;
	MyLinkedList<Item*> items;
	double totalPrice;
	bool complete = false;

public:
	//c'tor & d'tor
	Order(); 
	Order(const Order& other) = delete;
	const Order& operator=(const Order& other) = delete; //can't use operator= on items (MyLinkedList)

	// Getters 
	bool getComplete() const;
	double getTotalPrice() const;
	const MyLinkedList<Item*>& getItems() const;
	int getId() const;

	// Setters 
	void completeOrder();
	void setId(int id);

	// Methods
	void deleteItem(int itemIndex) throw (const string&);
	void addItem(const Item& item);
	friend ostream& operator<<(ostream& os, const Order& order);
};

#endif
