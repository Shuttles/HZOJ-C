#include <stdio.h>
#include <math.h>
int main()
{
	double n;
	scanf("%lf",&n);
	if (n >= 0) printf("%g\n", n);
	else printf("%g\n", fabs(n));
	return 0;
}

