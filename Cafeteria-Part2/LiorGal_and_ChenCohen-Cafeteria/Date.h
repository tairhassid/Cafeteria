#ifndef __DATE_H 
#define __DATE_H 
#include <iostream>
using namespace std;

class Date
{
private:
	int day, month, year;

public:
	Date(int day, int month, int year);

	//getters
	int getDay() const;
	int getMonth() const;
	int getYear() const;

	//Methods
	friend ostream& operator<<(ostream& os, const Date& date);
	bool operator>=(const Date& other);
};



#endif 

