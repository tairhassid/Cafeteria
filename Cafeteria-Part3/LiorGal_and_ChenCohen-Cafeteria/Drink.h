#ifndef __DRINK_H 
#define __DRINK_H   

#include "Item.h" 

class Drink : virtual public Item
{
public:
	enum eCupSize { SMALL, MEDIUM, LARGE };

protected:
	eCupSize cupSize;
	bool withMilk;
	double numOfSugar;
	double temperature;

	// c'tor
	Drink(double price, bool withMilk, double numOfSugar, double temperature, eCupSize cupSize);

public:
	virtual ~Drink();

	// Getters 
	eCupSize getCupSize() const;
	bool getWithMilk() const;
	double getNumOfSugar() const;
	double getTemperature() const;

	// Methods
	virtual Item* clone() const override;
	virtual void toOs(ostream& os) const override;
};

#endif
