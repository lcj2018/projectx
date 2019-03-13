#include "Thing.h"

Thing::Thing(TCHAR name[20], int times, double time, double cost)
{
	setName(name);
	setTimes(times);
	setTime(time);
	setCost(cost);
	setValue(times*time);
}

void Thing::setName(TCHAR name[20])
{
	wcscpy_s(Name, 20, name);
}

void Thing::setTimes(int times)
{
	Times = times;
}

void Thing::setTime(double time)
{
	Time = time;
}

void Thing::setCost(double cost)
{
	Cost = cost;
}

void Thing::setValue(double value)
{
	Value = value;
}

TCHAR *Thing::getName()
{
	return Name;
}

int Thing::getTimes()
{
	return Times;
}

double Thing::getTime()
{
	return Time;
}

double Thing::getCost()
{
	return Cost;
}

double Thing::getValue()
{
	return Value;
}