#include "Filter.h"

Filter::Filter(int numOfUsages, const Date& lastCleaned) : lastCleaned(lastCleaned), numOfUsages(numOfUsages) {}

int Filter::getNumOfUsages() const
{
	return numOfUsages;
}

const Date& Filter::getLastCleaned() const
{
	return lastCleaned;
}

void Filter::clean(const Date& date) throw (const char*)
{
	if (lastCleaned >= date)
		throw "invalid date!";
	lastCleaned = date;
	
}

const Filter& Filter::operator++()
{
	numOfUsages++;
	return *this;
}