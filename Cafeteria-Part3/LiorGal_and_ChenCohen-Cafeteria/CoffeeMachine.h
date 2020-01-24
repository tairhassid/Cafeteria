#ifndef __COFFEMACHINE_H 
#define __COFFEMACHINE_H 

#include "Filter.h" 
#include "Coffee.h"

class CoffeeMachine
{
private:
	double currentWaterTemperature;
	Date lastMaintained;
	Filter filter;

public:
	// c'tor
	CoffeeMachine(const Date& lastMaintained, const Filter& filter);

	// Getters
	const Filter& getFilter() const;
	const Date& getLastMaintained() const;
	double getCurrentWaterTemperature() const;

	// Methods
	void prepareCoffee(const Coffee& coffee);
	void replaceFilter(const Filter& newFilter, const Date& date);
};

#endif
