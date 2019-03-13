#include<iostream>
#include "Fibonacci.h"
//#include<cstdio>
//#include<string>
//#include<algorithm>
//#include<iomanip>
#define ie(i,s,t) for(int i=s;i<=t;++i)
#define LL long long

using namespace std;

const LL mod = 100000000007;
matrix fi, ch, ans;

matrix mul(matrix x1, matrix x2)
{
	matrix tt;
	ie(i, 1, 2)ie(j, 1, 2)tt.a[i][j] = 0;
	ie(i, 1, 2)ie(j, 1, 2)ie(k, 1, 2)tt.a[i][j] = (tt.a[i][j] + (x1.a[i][k] * x2.a[k][j]) % mod) % mod;
	return tt;
}

matrix cal(matrix x, LL v)
{
	/*
	if(v==1)return ch;
	tmp=cal(x,v/2);
	if(v%2==0)return mul(tmp,tmp);
	if(v%2==1)return mul(mul(tmp,tmp),ch);
	*/
	matrix tmp;
	tmp = ch;
	ie(i, 1, v)
	{
		tmp = mul(tmp, tmp);
	}
	return tmp;
}

LL getFib(int pos,bool flag)
{
	ch.a[1][1] = 1; ch.a[1][2] = 1; ch.a[2][1] = 1; ch.a[2][2] = 0;
	fi.a[1][1] = 0; fi.a[1][2] = 1; fi.a[2][1] = 1; fi.a[2][2] = 1;
	if (pos == 0 || pos == 1)return 1;
	if (pos>1)
	{
		ans = cal(ch, pos);
		if(flag)ans=mul(ans,fi);
		return ans.a[1][2] % mod;
	}
	return 0;
}