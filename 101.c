#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i,k;
	int sum =0;
	int j;
	for (i = 3; i >= 0; i--)
	{
		k = n / pow(10, i);
		sum += k;
		j = pow(10, i);
		n = n % j;
	}
	printf("%d\n",sum);
	return 0;
}

