#include <stdio.h>
int main()
{
	int a;
	scanf("%d", &a);
	if (a / 1000 == 0 && a /100 != 0)
	{
		if (a /100 == a % 10)
			printf("YES\n");
		else printf("NO\n");
	}
	else if (a / 1000 != 0)
	{
		if (a / 1000 == a % 10)
			printf("YES\n");
		else printf("NO\n");
	}
	else if (a / 10 == 0) printf("YES\n");
	else 
	{
		if (a / 10 == a % 10) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
