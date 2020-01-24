#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Seller.h"

Seller::Seller(const string& name, int seniority) throw (const string&) : IObserver(name), seniority(0)
{
	setSeniority(seniority);
}

int Seller::getSeniority() const
{
	return seniority;
}

void Seller::setName(const string& newName)
{
	name = newName;
}

void Seller::setSeniority(int seniority) throw (const string&)
{	
	if (seniority < this->seniority)
		throw string("Invalid seniority!");
	this->seniority = seniority;
}

void Seller::notify(const string& itemType) const
{
	cout << "Seller " << getName() << " is updated about the item " << itemType << endl;
}

IObserver* Seller::clone() const
{
	return new Seller(*this);
}

