#ifndef __COFFEE_H 
#define __COFFEE_H

#include "Drink.h"

class Coffee : public Drink
{

public:
	static const double PRICE;
	enum eCoffeeType { NESCAFE, TURKISH, COLOMBIAN, ESPRESSO };
	enum eStrengthLevel { LIGHT, NORMAL, STRONG };

private:
	eCoffeeType coffeeType;
	eStrengthLevel strengthLevel;
	bool foamy;

public:
	// c'tor
	Coffee(bool withMilk, double numOfSugar, double temperature, eCupSize cupSize,
		eCoffeeType coffeeType, eStrengthLevel strengthLevel, bool foamy);


	// Getters
	bool getFoamy() const;
	const eCoffeeType getCoffeeType() const;
	const eStrengthLevel getStrengthLevel() const;

	// Methods
	virtual Item* clone() const override;
	virtual void toOs(ostream& os) const override;
};

#endif