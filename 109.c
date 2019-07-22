#include <stdio.h>
#include <math.h>
int panduan (int x)
{
	if (x % 2 == 0)
		return 1;
	else return 0;
}
int main()
{
	int x;
	int i,j,k;
	scanf("%d", &x);
	for (i = 3; i >= 0; i--)
	{
		k = x / pow(10, i);
		if ((panduan(k) == 1))
				{
					printf("YES\n");
					break;
				}
		j = pow(10, i);
		x = x % j;
	
	}
	if (i == -1) printf("NO\n");

	return 0;
}
