#include "IObserver.h"

IObserver::IObserver(const string& name) : name(name) {}

const string& IObserver::getName() const
{
	return name;
}