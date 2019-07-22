#include <stdio.h>
int main()
{
	int y, m, d;
	scanf("%d%d%d", &y, &m, & d);
	if ((y % 4 == 0) && (y % 100 != 0) || y % 400 == 0) {
	    if (m == 2){
		 if (d ==29) printf("%d 2 %d\n%d 3 1\n", y, d - 1, y);
		 else if (d == 1) printf("%d 1 31\n%d 2 2\n", y, y);
		 else printf("%d %d %d\n%d %d %d", y, m, d - 1, y, m, d + 1);
	    }
	    else if (m == 3) {
	    	if (d == 1) printf("%d 2 29\n%d 3 2\n", y, y);
		else if (d == 31) printf("%d 3 30\n%d 4 1\n", y, y);
		else printf("%d %d %d\n%d %d %d", y, m, d - 1, y, m, d + 1);
	    }
	    else if (m == 4 || m == 6 || m == 9 || m == 11) {
		if (d == 1) printf("%d %d 31\n%d %d %d", y, m - 1, y, m, d + 1);
		else if (d == 30) printf("%d %d %d\n%d %d 1", y, m, d - 1, y, m + 1);
		 else printf("%d %d %d\n%d %d %d", y, m, d - 1, y, m, d + 1);	
	    }
	    else if (m == 1){
	      if (d == 1) printf("%d 12 31\n%d 1 2\n", y - 1, y);
	      else if (d == 31) printf("%d 1 30\n%d 2 1\n", y, y);
	      else printf("%d %d %d\n%d %d %d", y, m, d - 1, y, m, d + 1); 
	    }
	    else if (m == 12) {
	      if (d == 31) printf("%d 12 30\n%d 1 1\n", y, y + 1);
	      else  if (d == 1) printf("%d 11 30\n%d 12 2\n", y, y);
	      else printf("%d %d %d\n%d %d %d", y, m, d - 1, y, m, d + 1);
	    }
	    else {
	    	if (d == 1) printf("%d %d 30\n%d %d 2\n", y, m - 1, y, m);
		else if (d == 31) printf("%d %d 30\n%d %d 1\n", y, m, y, m + 1);	
	    }
	}
	else {
		if (m == 2){
                 if (d ==28) printf("%d 2 %d\n%d 3 1\n", y, d - 1, y);
                 else if (d == 1) printf("%d 1 31\n%d 2 2\n", y, y);
                 else printf("%d %d %d\n%d %d %d", y, m, d - 1, y, m, d + 1);
            }
	    else if (m == 3) {
                if (d == 1) printf("%d 2 28\n%d 3 2\n", y, y);
                else if (d == 31) printf("%d 3 30\n%d 4 1\n", y, y);
                else printf("%d %d %d\n%d %d %d", y, m, d - 1, y, m, d + 1);
            }

            else if (m == 4 || m == 6 || m == 9 || m == 11) {
                if (d == 1) printf("%d %d 31\n%d %d %d", y, m - 1, y, m, d + 1);
                else if (d == 30) printf("%d %d %d\n%d %d 1", y, m, d - 1, y, m + 1);
                 else printf("%d %d %d\n%d %d %d", y, m, d - 1, y, m, d + 1);
            }
            else if (m == 1){
              if (d == 1) printf("%d 12 31\n%d 1 2\n", y - 1, y);
              else if (d == 31) printf("%d 1 30\n%d 2 1\n", y, y);
              else printf("%d %d %d\n%d %d %d", y, m, d - 1, y, m, d + 1);
            }
         else if (m == 12) {
              if (d == 31) printf("%d 12 30\n%d 1 1\n", y, y + 1);
              else  if (d == 1) printf("%d 11 30\n%d 12 2\n", y, y);
              else printf("%d %d %d\n%d %d %d", y, m, d - 1, y, m, d + 1);
            }
            else {
                if (d == 1) printf("%d %d 30\n%d %d 2\n", y, m - 1, y, m);
                else if (d == 31) printf("%d %d 30\n%d %d 1\n", y, m, y, m + 1);
            }

	}

	return 0;
}

