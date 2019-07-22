#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	i=1;
	double sum = 0;
	while(i <= 6)
	{
		sum = (sum+n) * 1.00417;
		i++;
	}
	printf("$%.2f\n", sum);
	return 0;
}
