#include <stdio.h>
#include <math.h>

// This is only for the point of messing around with macros and figuring things out. 
// ABS(5-10) (5 - 10 < 0 ? -5-10 : x)
// ABS(a--) ((a--) < 0 -(a--) : (a--))
// ABS(++a) ((++a) < 0 -(++a) : (++a))
#define MIN(a, b) (a < b) ? a : b
#define MAX(a, b) (a > b) ? a : b
int _ABS_x;
#define ABS(x) (_ABS_x = x, _ABS_x < 0 ? -_ABS_x : _ABS_x)
int _rfactor;
int _rsub;
double _rval;
#define RVALUE(x) (_rfactor = x, _rval = (1/(_rfactor -1)), _rsub = _rval, (_rval - _rsub) > 0 ? (int)(_rval + 1) : _rsub)

int main()
{
	int a = 50;
	int b = 75;
	int x = -5;
	int y = 0;
	double ceil_v = 0.0;

	printf("A: %d B: %d\n",a,b);
	printf("MIN: %d\n",MIN(a, b));
	printf("MAX: %d\n",MAX(a, b));
	printf("ABS(x): %d\n",ABS(x));
	printf("ABS('C'): %d\n",ABS('C'));

	printf("ABS(5 - 10): %d\n",ABS(5-10));
	printf("ABS(y--): %d\n",ABS(y--));
	y = 0;
	printf("ABS(++y): %d\n",ABS(++y));

	ceil_v = ceil(1/10);

	printf("Ceil: %1f\n",ceil_v);
	printf("Rvalue: %d\n",RVALUE(11));


	return 0;
}
