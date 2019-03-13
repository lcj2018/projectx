#ifndef DATE_H
#define DATE_H

class Date
{
public:
	Date();

	void setYear(int);
	void setMonth(int);
	void setDay(int);

	int getYear();
	int getMonth();
	int getDay();
private:
	int year;
	int month;
	int day;
};

#endif