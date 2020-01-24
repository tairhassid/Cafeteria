#ifndef __HotChocolateWithIceCream_H
#define __HotChocolateWithIceCream_H 
#include "IceCream.h" 
#include "HotChocolate.h"

class HotChocolateWithIceCream : public IceCream, public HotChocolate
{

private:
	bool whippedCream;
	bool cherry;

public:
	// c'tor
	HotChocolateWithIceCream(const HotChocolate& hotChocholate, const IceCream& iceCream);

	// Getters
	bool getWithWhippedCream() const;
	bool getWithCherry() const;

	// Methods
	void addWhippedCream();
	void addCherry();
	virtual void toOs(ostream& os) const override;
	virtual Item* clone() const override;
};

#endif // ! __HotChoclateWithIceCream_H

