#include "buyList.h"

buyList::buyList()
{
	setCnt(0);
}

void buyList::setCnt(int cnt)
{
	Cnt = cnt;
}

void buyList::setThing(int pos, Thing thing)
{
	List[pos] = thing;
}

void buyList::delThing(CString name)
{
	int cnt = getCnt();
	int pos = getThingpos(name);
	ie(i, pos, cnt)setThing(i, getThing(i + 1));
	setCnt(cnt - 1);
}

int buyList::getCnt()
{
	return Cnt;
}

int buyList::getThingpos(CString name)
{
	LPTSTR pName = new TCHAR[20];
	_stprintf_s(pName, 20, _T("%s"), name);
	int cnt = getCnt();
	ie(i, 1, cnt)
	{
		if (cmpstr(pName, getThing(i).getName()))return i;
	}
	return 0;
}

Thing buyList::getThing(int pos)
{
	return List[pos];
}

bool buyList::cmpstr(LPTSTR x, LPTSTR y)
{
	ie(i, 0, 19)if (x[i] != y[i])return false;
	return true;
}