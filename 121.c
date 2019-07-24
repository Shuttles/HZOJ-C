#include <stdio.h>
int main()
{
	char a, b;
	scanf("%c %c", &a, &b);
	if (a == 'O' && b == 'Y')
		printf("MING\n");
    if (a == 'H' && b == 'O')
        printf("MING\n");
    if (a == 'Y' && b == 'H')
        printf("MING\n");
    if (a == 'O' && b == 'H')
        printf("LI\n");
    if (a == 'H' && b == 'Y')
        printf("LI\n");
    if (a == 'Y' && b == 'O')
        printf("LI\n");
    if (a == 'Y' && b == 'Y' || a == 'H' && b == 'H' || a == 'O' && b == 'O')
        printf("TIE\n");
    return 0;
}
