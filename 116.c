#include <stdio.h>
int main()
{
	int a[4];
	int i,j,t;
	for (i=1; i <= 3; i++)
	{
		scanf("%d", &a[i]);	 
		
	}
	for (i = 1; i <= 2; i++)
	{
		for (j = i + 1; j <= 3; j++)
		{
			if (a[i] > a[j]) 
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;

			}	
		}
	}
	if (a[1] + a[2] < a[3]) printf("illegal triangle\n");
	else if (a[1] * a[1] + a[2] * a[2] > a[3] * a[3])
		printf("acute triangle\n");
	else if (a[1] * a[1] + a[2] * a[2] == a[3] * a[3]) printf("right triangle\n");
	else if (a[1] * a[1] + a[2] * a[2] < a[3] * a[3])	printf("obtuse triangle\n");
	return 0;
}
