#ifndef __SELLER_H
#define __SELLER_H

#include "IObserver.h"

class Seller : public IObserver
{
private:
	int seniority;

public:
	// c'tor & d'tor
	Seller(const string& name, int seniority) throw (const string&);

	// Getters
	int getSeniority() const;

	// Setters
	void setName(const string& newName);
	void setSeniority(int seniority) throw (const string&);

	virtual void notify(const string& itemType) const override;
	virtual IObserver* clone() const override;
};

#endif
