#ifndef THING_H
#define THING_H
#include <afxwin.h>

class Thing
{
public:
	Thing(TCHAR[] = L"", int = 0, double = 0, double = 0);

	void setTimes(int);
	void setTime(double);
	void setCost(double);
	void setValue(double);
	void setName(TCHAR []);

	int getTimes();
	double getTime();
	double getCost();
	double getValue();
	TCHAR *getName();
private:
	TCHAR Name[20];
	int Times;
	double Time;
	double Cost;
	double Value;
};

#endif