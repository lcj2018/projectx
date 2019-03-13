#ifndef ROOM_H
#define ROOM_H

#include "Date.h"

class Room
{
public:
	Room();

	void setDate(int, Date);
	void setCnt(int);

	Date getDate(int);
	int getCnt();

private:
	int cnt;
	Date list[8];
};

#endif