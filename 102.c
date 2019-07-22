#include<stdio.h>
int main()
{
	double a,b,c,t;
	scanf("%lf%lf%lf%lf",&a,&b,&c,&t);
	double x;
	x = (1 - t * (1/a + 1/b)) / (1/a +1/b -1/c);
	printf("%.2f\n", x + t);
	return 0;
}
