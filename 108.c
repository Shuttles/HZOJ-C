#include <stdio.h>
int main()
{
	char x;
	scanf("%c", &x);
	double m,n;
	scanf("%lf%lf",&m, &n);
	switch (x)
	{
		case 'r' :
			printf("%.2f\n", m*n);break;

		case 't':
			printf("%.2f\n", m*n/2);break;
	}

	return 0;
}
