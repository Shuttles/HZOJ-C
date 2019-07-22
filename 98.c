#include<stdio.h>
#define PI 3.14
int main()
{
	double r,h;
	scanf("%lf%lf",&r,&h);
	printf("%.2f\n%.2f\n",r*r*PI,r*r*PI*h);
	return 0;
}

