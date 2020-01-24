#ifndef __OBSERVER_H
#define __OBSERVER_H

#include <string>
#include <iostream>
using namespace std;

class IObserver
{
protected:
	string name;
public:
	IObserver(const string& name);
	virtual void notify(const string& itemType) const = 0;
	virtual IObserver* clone() const = 0;
	virtual const string& getName() const;
};

#endif
