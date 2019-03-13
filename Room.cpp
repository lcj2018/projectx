#include "Room.h"

Room::Room()
{
	setCnt(0);
}

void Room::setCnt(int tmp)
{
	cnt = tmp;
}

void Room::setDate(int p, Date date)
{
	list[p] = date;
}

Date Room::getDate(int p)
{
	return list[p];
}

int Room::getCnt()
{
	return cnt;
}