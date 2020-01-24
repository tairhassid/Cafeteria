#ifndef __FILTER_H 
#define __FILTER_H  

#include "Date.h" 

class Filter
{
private:
	int numOfUsages;
	Date lastCleaned;

public:
	// c'tor
	Filter(int numOfUsages, const Date& lastCleaned);

	// Getters
	int getNumOfUsages() const;
	const Date& getLastCleaned() const;

	// Methods
	void clean(const Date& date) throw (const char*);
	const Filter& operator++();
};

#endif
