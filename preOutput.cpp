#include "preOutput.h"
#include "CivSup.h"
#include <fstream>
#include <tchar.h>

#define LL long long
#define ie(i,s,t) for(int i=s;i<=t;++i)

using namespace std;

int getCnt()
{
	LPTSTR pWhite = new TCHAR[20];
	_stprintf_s(pWhite, 20, _T("%s"), _T(""));
	CivSup tmpUser(pWhite, 0, pWhite, pWhite, 0, 0, pWhite, 0, pWhite, pWhite);
	ifstream UDat("User.dat", ios::in | ios::binary);
	UDat.seekg(0);
	UDat.read(reinterpret_cast<char *>(&tmpUser), sizeof(CivSup));
	UDat.close();
	return (int)(tmpUser.GetStuNum()%2147483646);
}

bool check(LL stunum)
{
	LPTSTR pWhite = new TCHAR[20];
	_stprintf_s(pWhite, 20, _T("%s"), _T(""));
	CivSup tmpUser(pWhite, 0, pWhite, pWhite, 0, 0, pWhite, 0, pWhite, pWhite);
	int cnt = getCnt();
	ifstream UDat("User.dat", ios::in | ios::binary);
	ie(i, 1, cnt)
	{
		UDat.seekg(i*sizeof(CivSup));
		UDat.read(reinterpret_cast<char *>(&tmpUser), sizeof(CivSup));
		if (tmpUser.GetStuNum() == stunum)
		{
			UDat.close(); return true;
		}
	}
	UDat.close();
	return false;
}

CivSup getInfo(LL stunum)
{
	LPTSTR pWhite = new TCHAR[20];
	_stprintf_s(pWhite, 20, _T("%s"), _T(""));
	CivSup tmpUser(pWhite, 0, pWhite, pWhite, 0, 0, pWhite, 0, pWhite, pWhite);
	CivSup noFound(pWhite, 0, pWhite, pWhite, 0, 0, pWhite, 0, pWhite, pWhite);
	int cnt = getCnt();
	ifstream UDat("User.dat", ios::in | ios::binary);
	ie(i, 1, cnt)
	{
		UDat.seekg(i*sizeof(CivSup));
		UDat.read(reinterpret_cast<char *>(&tmpUser), sizeof(CivSup));
		if (tmpUser.GetStuNum() == stunum)
		{
			UDat.close();
			return tmpUser;
		}
	}
	UDat.close();
	return noFound;
}

int getPos(LL stu)
{
	LPTSTR pWhite = new TCHAR[20];
	_stprintf_s(pWhite, 20, _T("%s"), _T(""));
	CivSup tmpUser(pWhite, 0, pWhite, pWhite, 0, 0, pWhite, 0, pWhite, pWhite);
	int cnt = getCnt();
	ifstream UDat("User.dat", ios::in | ios::binary);
	ie(i, 1, cnt)
	{
		UDat.seekg(i*sizeof(CivSup));
		UDat.read(reinterpret_cast<char *>(&tmpUser), sizeof(CivSup));
		if (tmpUser.GetStuNum() == stu)
		{
			UDat.close();
			return i;
		}
	}
	UDat.close();
	return 0;
}

void display()
{
	fstream UDat("User.dat", ios::in | ios::binary);
	LPTSTR pWhite = new TCHAR[20];
	_stprintf_s(pWhite, 20, _T("%s"), _T(""));
	CivSup tmpUser(pWhite, 0, pWhite, pWhite, 0, 0, pWhite, 0, pWhite, pWhite);
	ie(i, 0, 1)
	{
		UDat.seekg(i*sizeof(CivSup));
		UDat.read(reinterpret_cast<char *>(&tmpUser), sizeof(CivSup));
		tmpUser = tmpUser;
	}
}

void pushRoom(LL stu, int roomPos,Date tmp)
{
	CivSup tmpUser = getInfo(stu);
	Room tmpRoom;
	int tmpCnt = tmpUser.GetRoom(roomPos).getCnt()+1;
	tmpRoom = tmpUser.GetRoom(roomPos);
	tmpRoom.setCnt(tmpCnt);
	tmpRoom.setDate(tmpCnt, tmp);
	tmpUser.SetRoom(roomPos, tmpRoom);
	//tmpUser.GetRoom(roomPos)
	//tmpUser.GetRoom(roomPos).setDate(tmpCnt, tmp);
	int pos = getPos(stu);
	//getCnt();
	//display();
	fstream UDat("User.dat", ios::in | ios::out | ios::binary);
	UDat.seekp(pos*sizeof(CivSup));
	UDat.write(reinterpret_cast<const char *>(&tmpUser), sizeof(CivSup));
	UDat.close();
	//getCnt();
	//display();
}

bool cmpstr(LPTSTR x, LPTSTR y) 
{
	ie(i, 0, 19)if (x[i] != y[i])return false;
	return true;
}
