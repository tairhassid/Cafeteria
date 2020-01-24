#ifndef __ICECREAM_H 
#define __ICECREAM_H 
#include "Item.h"
#include <vector>
#include <string>

class IceCream :virtual public Item
{
public:
	static const double PRICE_PER_SCOOP;
	enum eFlavor { CHOCLATE, VANILLA, CHERRY, BANANA };
private:
	eFlavor flavor;
	int numOfScoops;

public:
	// c'tor
	IceCream(eFlavor flavor, int numOfScoops);

	virtual ~IceCream();

	// Getters
	eFlavor getFlavor() const;
	int getNumOfScoops() const;

	// Methods
	virtual Item* clone() const override;
	virtual void toOs(ostream& os) const override;
};

#endif
