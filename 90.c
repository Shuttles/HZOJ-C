#include<stdio.h>
int main()
{
	int a;
	scanf("%d",&a);
	printf("%d\n%d\n%d\n",a/100,(a%100)/10,(a%100)%10);
	return 0;
}

