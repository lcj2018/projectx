#ifndef PREOUTPUT_H
#define PREOUTPUT_H

#include "CivSup.h"
#include <cstring>
#include <afx.h>
#include "Date.h"
#define LL long long

int getCnt();

bool check(LL);

CivSup getInfo(LL);

int getPos(LL);

bool cmpstr(LPTSTR, LPTSTR);

void pushRoom(LL, int, Date);

void display();

#endif