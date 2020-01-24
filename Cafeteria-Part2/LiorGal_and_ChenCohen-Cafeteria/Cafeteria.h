#ifndef __CAFETERIA_H 
#define __CAFETERIA_H
#include "CoffeeMachine.h" 
#include "Seller.h" 
#include "Order.h"
#include "HotChocolateWithIceCream.h" 
#include "Menu.h" 

class Cafeteria 
{ 
public:
	static const int MAX_ORDERS;
	static const int MAX_SELLERS;

private:
	CoffeeMachine coffeeMachine;  
	Seller** sellers;  
	Order** orders; 
	Menu menu;
	char* name;  
	int currentNumOfSellers;
	int currentNumOfOrders;  

	void updateSellers(int index);

public:  
	// c'tor
	Cafeteria(const char* name, const CoffeeMachine& coffeMachine, const Menu& menu);
	Cafeteria(const Cafeteria& other) = delete;
	const Cafeteria& operator=(const Cafeteria& other) = delete;

	//d'tor
	~Cafeteria();
	
	// Getters
	Order** getAllOrders() const; 
	Seller** getAllSellers() const;
	int getNumOfOrders() const;
	int getNumOfSellers() const;
	const Date& getFilterLastCleaned() const;
	const Date& getCoffeeMachineLastMaintained() const;
	const char* getName() const;
	
	// Setters 
	void setName(const char* name);

	// Methods
	void showMenu() const;

	void addSeller(const Seller& seller) throw (const char*);
	void deleteSeller(const char* name, int seniority) throw (const char*);

	void addItemToMenu(Menu::eItems itemType) throw (const char*);
	void removeItemFromMenu(int index);
	
	int addOrder() throw (const char*);
	void deleteItemFromOrder(int orderIndex, int itemIndex) throw (const char*);
	void addItemToOrder(int orderIndex, const Item& item) throw (const char*);
	Item** completeOrder(int orderIndex);
	const void cancelOrder(int orderIndex) throw (const char*);
	const char* getItemType(int index) const;
	
	Order& operator[](int orderIndex) const;
};

#endif 

