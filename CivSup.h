#ifndef CIVSUP_H
#define CIVSUP_H

#include "Person.h"
#include "Room.h"
#include <tchar.h>
#define LL long long
using namespace std;

class CivSup :public Person//Civilization Supervisor
{
public:
	CivSup(TCHAR[] = L"", LL = 0, TCHAR[] = L"", TCHAR[] = L"", int = 0, LL = 0, TCHAR[] = L"", int = 0, TCHAR[] = L"", TCHAR[] = L"");
	
	void SetFloor(int);
	void SetRoom(int,Room);

	int GetFloor();
	Room GetRoom(int);
private:
	int Floor;
	Room room[60];
};

#endif