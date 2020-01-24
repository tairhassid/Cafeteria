#include "CoffeeMachine.h"

CoffeeMachine::CoffeeMachine(const Date& lastMaintained, const Filter& filter) :
	lastMaintained(lastMaintained), filter(filter) {}

const Filter& CoffeeMachine::getFilter() const
{
	return filter;
}

const Date& CoffeeMachine::getLastMaintained() const
{
	return lastMaintained;
}

double CoffeeMachine::getCurrentWaterTemperature() const
{
	return currentWaterTemperature;
}

void CoffeeMachine::prepareCoffee(const Coffee& coffee)
{
	++filter;
}

void CoffeeMachine::replaceFilter(const Filter& newFilter, const Date& date)
{
	filter = newFilter;
	lastMaintained = date;
}
