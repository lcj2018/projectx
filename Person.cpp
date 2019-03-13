#include "Person.h"
#include <windows.h>
#define ie(i,s,t) for(int i=s;i<=t;++i)
#define LL long long

using namespace std;

Person::Person(TCHAR name[20], LL stunum, TCHAR institute[20], TCHAR profess[20], int classnum, LL phone, TCHAR building[20],TCHAR question[20],TCHAR answer[20])//*
{
	SetName(name);
	SetStuNum(stunum);
	SetInstitute(institute);
	SetProfess(profess);
	SetClass(classnum);
	SetPhone(phone);
	SetBuilding(building);
	SetPassword(1, 0);
	SetQuestion(question);
	SetAnswer(answer);
}

void Person::SetName(TCHAR name[20])
{
	wcscpy_s(Name, 20, name);
}

void  Person::SetStuNum(LL stunum)
{
	StuNum = stunum;
}

void Person::SetInstitute(TCHAR institute[20])
{
	wcscpy_s(Institute, 20, institute);
}

void Person::SetProfess(TCHAR profess[20])
{
	wcscpy_s(Profess, 20, profess);
}

void Person::SetClass(int classnum)
{
	Class = classnum;
}

void Person::SetPhone(LL phone)
{
	Phone = phone;
}

void Person::SetQuestion(TCHAR question[20])
{
	wcscpy_s(Question, 20, question);
}

void Person::SetBuilding(TCHAR building[20])
{
	wcscpy_s(Building, 20, building);
}

void Person::SetPassword(int pos,LL password)
{
	//wcscpy_s(Password, 20, password);
	Password[pos] = password;
}

void Person::SetAnswer(TCHAR answer[20])
{
	wcscpy_s(Answer, 20, answer);
}

void Person::SetBuyList(buyList buy)
{
	Buy = buy;
}

TCHAR *Person::GetName()
{
	return Name;
}

LL Person::GetStuNum()
{
	return StuNum;
}

TCHAR *Person::GetInstitute()
{
	return Institute;
}

TCHAR *Person::GetProfess()
{
	return Profess;
}

int Person::GetClass()
{
	return Class;
}

LL Person::GetPhone()
{
	return Phone;
}

TCHAR *Person::GetBuilding()
{
	return Building;
}

LL Person::GetPassword(int pos)
{
	return Password[pos];
}

TCHAR * Person::GetQuestion()
{
	return Question;
}

TCHAR * Person::GetAnswer()
{
	return Answer;
}//*

buyList Person::GetBuyList()
{
	return Buy;
}
