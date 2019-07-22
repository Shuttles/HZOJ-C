#include <stdio.h>
int main()
{
	double x;
	scanf("%lf", &x);
	if (x <= 15.0) printf("%.2f\n", 6 * x);
	else printf("%.2f\n", 90 + 9 * (x - 15));
	return 0;
}
