#ifndef __HOTCHOCOLATE_H 
#define __HOTCHOCOLATE_H 
#include "Drink.h"

class HotChocolate :virtual public Drink
{
public:
	static const double PRICE;
	static const double PRICE_PER_MARSHMALLOW;

private:
	int numOfMarshmallows;

public:
	// c'tor
	HotChocolate(bool withMilk, double numOfSugar, double temperature, 
		int numOfMarshmalows, eCupSize cupSize);

	virtual ~HotChocolate();

	// Getters
	int getNumOfMarshmalows() const;
	double getPrice() const; 

	// Setters
	void setNumOfMarshmallows(int num);
	void setPrice(int numOfMarshmallows);

	// Methods
	virtual Item* clone() const override;
	virtual void toOs(ostream& os) const override;
};

#endif
