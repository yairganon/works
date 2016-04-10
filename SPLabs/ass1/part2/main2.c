#include <stdio.h>
#include <stdlib.h>
extern void calc_func(long long *x, int numOfRounds);
int compare (long long * x, long long * y){return *x==*y;}
int main(int argc, char** argv)
{
	unsigned long long int *x = (unsigned long long int *) malloc(sizeof(unsigned long long int));
	int numOfRounds;
	char sX [17];
	fgets(sX , 16 , stdin);
	*x=strtoll(sX,NULL,16);
	fgets(sX , 8 , stdin);
	numOfRounds= atoi(sX);
	calc_func(x,numOfRounds);
	free(x);
	return 0;
}