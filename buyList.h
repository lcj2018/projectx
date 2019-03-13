#ifndef BUYLIST_H
#define BUYLIST_H

#include "Thing.h"
//#include "preOutput.h"
#define ie(i,s,t) for(int i=s;i<=t;++i)

using namespace std;

class buyList
{
public:
	buyList();

	void setCnt(int);
	void setThing(int, Thing);
	void delThing(CString);

	int getCnt();
	int getThingpos(CString);
	Thing getThing(int);

	bool cmpstr(LPTSTR, LPTSTR);
private:
	int Cnt;
	Thing List[1000];
};

#endif