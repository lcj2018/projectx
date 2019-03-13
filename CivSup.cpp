#include "stdafx.h"
#include "CivSup.h"
#define ie(i,s,t) for(int i=s;i<=t;++i)
#define LL long long

CivSup::CivSup(TCHAR name[20], LL stunum, TCHAR institute[20], TCHAR profess[20], int classnum, LL phone, TCHAR building[20], int floor, TCHAR question[20], TCHAR answer[20])
	:Person(name, stunum, institute, profess, classnum, phone, building, question, answer)//*
{
	SetFloor(floor);
	Room tmp;
	ie(i, 1, 59)SetRoom(i, tmp);
}

void CivSup::SetFloor(int floor)
{
	Floor = floor;
}

void CivSup::SetRoom(int p, Room tmp)
{
	room[p] = tmp;
}

int CivSup::GetFloor()
{
	return Floor;
}

Room CivSup::GetRoom(int p)
{
	return room[p];
}


