#ifndef __CAFETERIA_H 
#define __CAFETERIA_H
#include "CoffeeMachine.h" 
#include "Seller.h" 
#include "Order.h"
#include "HotChocolateWithIceCream.h" 
#include "Menu.h" 
#include "MyLinkedList.h"
#include <vector>
#include <iostream>
using namespace std;

class Cafeteria 
{ 
public:
	static const int MAX_ORDERS;
	static const int MAX_SELLERS;

private:
	CoffeeMachine coffeeMachine;
	vector<Seller*> sellers;
	vector<Order*> orders;
	Menu menu;
	string name;

	static Cafeteria theCafeteria;
	Cafeteria(const string& name, const CoffeeMachine& coffeMachine, const Menu& menu);
	Cafeteria(const Cafeteria& other);


public:
	//Singleton
	static Cafeteria& getInstance(const string& name, const CoffeeMachine& coffeMachine, const Menu& menu);

	// Getters
	const vector<Order*>& getAllOrders() const; 
	const vector<Seller*>& getAllSellers() const;
	int getNumOfOrders() const;
	const Date& getFilterLastCleaned() const;
	const Date& getCoffeeMachineLastMaintained() const;
	const string& getName() const;

	// Methods
	void showMenu() const;

	void addSeller(Seller& seller); //Can't add const seller to vector<Seller*>
	void deleteSeller(const string& name, int seniority) throw (const string&);

	void addItemToMenu(Menu::eItems itemType) throw (const string&);
	void removeItemFromMenu(int index);
	
	int addOrder();
	void deleteItemFromOrder(int orderIndex, int itemIndex) throw (const string&);
	void addItemToOrder(int orderIndex, const Item& item);
	void completeOrder(int orderIndex);
	const void cancelOrder(int orderIndex) throw (const string&);
	const string& getItemType(int index) const;
	
	Order& operator[](int orderIndex) const;
	void showOrderHistory() const;
	
};

#endif 

