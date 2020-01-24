#include "Cafeteria.h"  
#include <string>
#include <iostream>
using namespace std; 

const int NAME_LEN =  15;

void addItemToMenu(Cafeteria& cafeteria);
void startNewOrder(Cafeteria& cafeteria);
void showOrderHistory(const Cafeteria& cafeteria);
Seller* initSeller() throw (const string&);
void cancelOrder(Cafeteria& cafeteria) throw (const string&);

void main()
{
	{
		int choice = 0;
		bool fContinue = true;

		Menu menu;

		Seller* seller = nullptr;
		Date date(1, 1, 2019);
		Filter filter(10, date);
		CoffeeMachine coffeeMachine(date, filter);
		Cafeteria& cafeteria = Cafeteria::getInstance("CppCoffee", coffeeMachine, menu);
		

		do {
			cout << "what would you like?\n1 - show menu\n2 - add item to menu\n3 - new order\n4 - show order history\n5 - cancel order\n6 - add seller\n7 - fire seller\n8 - last time filter cleaned\n9 - last time coffee machine was maintained\n10 - Exit\n\n";
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				cafeteria.showMenu();
				break;
			}

			case 2:
			{
				addItemToMenu(cafeteria);
				break;
			}

			case 3:
			{
				startNewOrder(cafeteria);
				break;
			}

			case 4:
			{
				try
				{
					showOrderHistory(cafeteria);
				}
				catch (const string& msg)
				{
					cout << msg << endl;
				}
				break;
			}

			case 5:
			{
				try
				{
					cancelOrder(cafeteria);
				}
				catch (const string& msg)
				{
					cout << msg << endl;
				}
				break;
			}

			case 6: // Init a seller & add them to the cafeteria
			{
				try
				{
					seller = initSeller();
					cafeteria.addSeller(*seller);
				}
				catch (const string& msg)
				{
					cout << msg << endl;
				}
				break;
			}

			case 7:  // Delete seller
			{
				string name;
				int seniority;
				cout << "enter name and seniority of the seller:  ";
				cin >> name >> seniority;
				try
				{
					cafeteria.deleteSeller(name, seniority);
				}
				catch (const string& msg)
				{
					cout << msg << endl;
				}
				break;
			}

			case 8: // Get last time filter got cleaned
			{
				cout << cafeteria.getFilterLastCleaned() << endl;
				break;
			}

			case 9: // Get last time coffee machine was maintained
			{
				cout << cafeteria.getCoffeeMachineLastMaintained() << endl;
				break;
			}

			case 10:
			{
				cout << "Bye!" << endl;
				fContinue = false;
				break;
			}

			default:
				cout << "Illegal choice! try again";
				break;
			}
			cout << "\n";
		} while (fContinue);


		delete seller;
	}
	system("pause");
}

void addItemToMenu(Cafeteria& cafeteria)
{
	bool fcontinue = true;
	int choice;
	do
	{
		cout << "Please choose item to add:" << endl;
		for (int i = 0; i < Menu::NUM_OF_ENUM; i++)
		{
			cout << i + 1 << "- " << cafeteria.getItemType(i) << endl;
		}
		cin >> choice;
		if (choice > Menu::NUM_OF_ENUM || choice < 0)
		{
			cout << "Illegal choice! try again" << endl;
		}
		else
		{
			fcontinue = false;
		}
		
	} while (fcontinue);

	try
	{
		cafeteria.addItemToMenu(Menu::eItems(choice - 1));
	}
	catch (const string& msg)
	{
		cout << msg << endl;
		return;
	}
	cout << "Item added to menu: " << cafeteria.getItemType(choice-1) << endl;
}

void startNewOrder(Cafeteria& cafeteria)
{
	bool fContinue = true;
	int choice;
	char decision = 'y';
	int orderIndex;
	int itemIndex;
	
	try
	{
		orderIndex = cafeteria.addOrder();

	}
	catch (const string& msg)
	{
		cout << msg << endl;
		return;
	}

	do
	{
		cout << "what would you like?\n1-coffee\n2-hot choclate\n3-ice cream\n4-hot choclate with ice cream\n5-cancel item\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			try
			{
				Item* coffee = new Coffee(true, 2, 65, Drink::LARGE, Coffee::COLOMBIAN, Coffee::STRONG, true);
				cafeteria.addItemToOrder(orderIndex, *coffee);
			}
			catch(const string& msg)
			{
				cout << msg << endl;
			}
			break;
		}

		case 2:
		{
			try
			{
				Item* hotChocolate = new HotChocolate(true, 2, 60, 0, Drink::LARGE);
				cafeteria.addItemToOrder(orderIndex, *hotChocolate);
			}
			catch (const string& msg)
			{
				cout << msg << endl;
			}
			break;
		}
		case 3:
		{
			try
			{
				Item* iceCream = new IceCream(IceCream::CHOCLATE, 3);
				cafeteria.addItemToOrder(orderIndex, *iceCream);
			}
			catch (const string& msg)
			{
				cout << msg << endl;
			}
			break;
		}
		case 4:
		{
			try
			{
				IceCream iceCream(IceCream::CHOCLATE, 3);
				Item::ID_GENERATOR--;
				HotChocolate hotChocolate(true, 2, 60, 0, Drink::LARGE);
				Item::ID_GENERATOR--;
				Item* hotChocolateWithIceCream = new HotChocolateWithIceCream(hotChocolate, iceCream);
				cafeteria.addItemToOrder(orderIndex, *hotChocolateWithIceCream);
			}
			catch (const string& msg)
			{
				cout << msg << endl;
			}
			break;
		}
		case 5:
		{
			try
			{
				if (cafeteria[orderIndex].getItems().getSize() == 0)
					throw string("Order is empty!");
				cout << cafeteria[orderIndex] << endl;
				cout << "Choose item to cancel:" << endl;
				cin >> itemIndex;
				cafeteria.deleteItemFromOrder(orderIndex, itemIndex);
				cout << "Item was canceled" << endl;
			}
			catch (const string& msg)
			{
				cout << msg << endl;
			}
			break;
		}
		default:
		{
			cout << "Illegal choice";
			break;
		}
		}

		cout << "Anything else? 'y' || 'n' ";
		cin >> decision;
		if (decision == 'n')
			fContinue = false;
	} while (fContinue);
	cafeteria.completeOrder(orderIndex);
}

void showOrderHistory(const Cafeteria& cafeteria)
{
	if (cafeteria.getNumOfOrders() == 0)
		throw string("No orders exists!");
	cout << "Order history:" << endl;

	vector<Order*>::const_iterator itrStart = cafeteria.getAllOrders().begin();
	vector<Order*>::const_iterator itrEnd = cafeteria.getAllOrders().end();

	for (; itrStart != itrEnd; ++itrStart)
	{
		cout << *(*itrStart) << endl;
	}
}

void cancelOrder(Cafeteria& cafeteria) throw (const string&)
{
	int choice;
	showOrderHistory(cafeteria);
	cout << "Which order would you like to cancel?" << endl;
	cin >> choice;
	cafeteria.cancelOrder(choice);
}

Seller* initSeller() throw (const string&)
{
	string name;
	int seniority;

	cout << "Enter a name and seniority:";
	cin >> name >> seniority; 
	
	return new Seller(name, seniority); 
}












