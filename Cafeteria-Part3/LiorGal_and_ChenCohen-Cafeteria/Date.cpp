#include "Date.h"

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}

ostream& operator<<(ostream& os, const Date& date)
{
	os << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << endl;
	return os;
}

bool Date::operator>=(const Date& other)
{
	if (year > other.year)
		return true;
	if (year == other.year)
	{
		if (month > other.month)
			return true;
		if (month == other.month)
		{
			if (day >= other.day)
				return true;
		}
	}
	return false;
}