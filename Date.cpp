#include "Date.h"

Date::Date()
{
	setYear(0);
	setMonth(0);
	setDay(0);
}

void Date::setYear(int y)
{
	year = y;
}

void Date::setMonth(int m)
{
	month = m;
}

void Date::setDay(int d)
{
	day = d;
}

int Date::getYear()
{
	return year;
}

int Date::getMonth()
{
	return month;
}

int Date::getDay()
{
	return day;
}
