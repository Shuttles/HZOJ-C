#include <stdio.h>
int main()
{
	int x, y;
	scanf("%d%d", &x, &y);
	if (x == y)
		printf("100\n");
	else if (x == 10 * (y % 10) + y / 10) printf("20\n");
	else if (x /10 == y /10 || x / 10 == y % 10 || x % 10 == y / 10 || x % 10 == y % 10) printf("2\n");
	else printf("0\n");
	return 0;
}
