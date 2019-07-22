#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a,b;
	a=n/10;
	b=n%10;
	printf("%d\n",b*10+a);
	return 0;
}
