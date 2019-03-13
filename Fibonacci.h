#ifndef FIBONACCI_H
#define FIBONACCI_H

#define LL long long

struct matrix
{
	LL a[5][5];
};

matrix mul(matrix, matrix);

matrix cal(matrix x, LL v);

LL getFib(int pos, bool flag);

#endif