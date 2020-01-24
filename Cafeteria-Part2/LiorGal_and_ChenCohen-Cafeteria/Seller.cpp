#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Seller.h"

Seller::Seller(const char* name, int seniority) throw(const char*)
{
	this->name = strdup(name);
	setSeniority(seniority);
}

Seller::Seller(const Seller& other) : name(NULL)
{
	*this = other;
}

const Seller& Seller::operator=(const Seller& other)
{
	setName(other.name);
	seniority = other.seniority;

	return *this;
}

Seller::~Seller()
{
	delete[] name;
}

const char* Seller::getName() const
{
	return name;
}

int Seller::getSeniority() const
{
	return seniority;
}

void Seller::setName(const char* newName)
{
	delete[] name;
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
}

void Seller::setSeniority(int seniority) throw (const char*)
{
	if (seniority < this->seniority)
		throw "Invalid seniority!";
	this->seniority = seniority;
}

