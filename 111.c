#include <stdio.h> 
int main()
{
	int N;
	scanf("%d", &N);
	if (N <= 3) printf("14\n");
	else  printf("%g\n", 14 + 2.3 * (N - 3)); 
	return 0;
}

