#include <bits/stdc++.h>

using namespace std;

int main() {
	int A[] = { 3, 34, 4, 12, 5, 2 };
	int Asize = 6;
	int sum = 50;
	int i,j,x;

	bool dp[Asize][sum+2];

	for (i=0; i<Asize; i++) {
		dp[i][0] = true;
		for (j=1; j<=sum+1; j++) {
			dp[i][j] = false;
		}
 	}
 	dp[0][3] = true;

/*
 	for (i=0; i<Asize; i++) {
		for (j=0; j<=sum+1; j++) {
			printf("%d ", dp[i][j]?1:0);
		}
		printf("\n");
 	}
 	printf("\n\n");
 	*/

	for (i=1; i<Asize; i++) {
		for (j=1; j<=sum; j++) {
			// printf("\ni: %d  j: %d\n", i, j);
			if (A[i] <= j) {		// A[i] may be included
				x = j - A[i];
				if (dp[i-1][x] == true) {
					dp[i][j] = true;
					//printf("control 1\n");
				}
				else {
					dp[i][j] = dp[i-1][j];
					//printf("control 2\n");
				}
			}
			else {					// A[i] cannot be included
				dp[i][j] = dp[i-1][j];
				//printf("control 3\n");
			}
			//printf("dp[%d][%d]: %d\n", i, j, dp[i][j]?1:0);
		}
	}
/*
	for (i=0; i<Asize; i++) {
		for (j=0; j<=sum+1; j++) {
			printf("%d ", dp[i][j]?1:0);
		}
		printf("\n");
 	}
 	printf("\n\n");
*/
	x = 6;

	if (dp[Asize-1][x]) printf("sum %d is possible\n", x);
	else printf("sum %d is not possible\n", x);

	x = 12;

	if (dp[Asize-1][x]) printf("sum %d is possible\n", x);
	else printf("sum %d is not possible\n", x);


	x = 7;

	if (dp[Asize-1][x]) printf("sum %d is possible\n", x);
	else printf("sum %d is not possible\n", x);

	x = 9;

	if (dp[Asize-1][x]) printf("sum %d is possible\n", x);
	else printf("sum %d is not possible\n", x);

	x = 35;

	if (dp[Asize-1][x]) printf("sum %d is possible\n", x);
	else printf("sum %d is not possible\n", x);

	x = 13;

	if (dp[Asize-1][x]) printf("sum %d is possible\n", x);
	else printf("sum %d is not possible\n", x);

	return 0;
}