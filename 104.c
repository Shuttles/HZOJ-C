#include<stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	int a, b, c;
	a = x / 100;
	b = x % 100  /10;
	c = x % 10;
	if (a == 9 || b == 9 || c == 9) printf("YES\n");
	else printf("NO\n");
	return 0;
}
