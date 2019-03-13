#ifndef PERSON_H
#define PERSON_H

#include <tchar.h>
#include "buyList.h"
#define LL long long

class Person
{
public:
	Person(TCHAR[], LL, TCHAR[], TCHAR[], int, LL, TCHAR[], TCHAR[], TCHAR[]);//*

	void SetName(TCHAR []);
	void SetStuNum(LL);
	void SetInstitute(TCHAR []);
	void SetProfess(TCHAR []);
	void SetClass(int);
	void SetPhone(LL);
	void SetBuilding(TCHAR []);
	void SetPassword(int, LL);
	void SetQuestion(TCHAR []);
	void SetAnswer(TCHAR []);
	void SetBuyList(buyList);

	TCHAR *GetName();
	LL GetStuNum();
	TCHAR *GetInstitute();
	TCHAR *GetProfess();
	int GetClass();
	LL GetPhone();
	TCHAR *GetBuilding();
	LL GetPassword(int);
	TCHAR *GetQuestion();
	TCHAR *GetAnswer();
	buyList GetBuyList();
private:
	TCHAR Name[20];
	LL StuNum;
	TCHAR Institute[20];
	TCHAR Profess[20];
	int Class;
	LL Phone;
	TCHAR Building[20];
	LL Password[20];
	TCHAR Question[20];
	TCHAR Answer[20];
	buyList Buy;
};//*

#endif