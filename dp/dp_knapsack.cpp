#include <cstdio>
#include <algorithm>
using namespace std;

int t, n, w, x, y, val[105], wt[105];
long knapsack[105][105];

main() {
	scanf("%d",&t);
	while (t--) {
		scanf("%d %d",&n, &w);
		for (int i=0;i<n;i++) {
			scanf("%d %d %d",&x, &y, &wt[i]);
			val[i] = x*y;
		}
		
		for (int i=0; i<=n; i++) {
			for (int j=0; j<=w; j++) {
				if (i == 0 || j == 0) knapsack[i][j] = 0;
				
				else if (wt[i-1] > j) {
					knapsack[i][j] = knapsack[i-1][j];
				}
				
				else {
					knapsack[i][j] = max(val[i-1]+knapsack[i-1][j-wt[i-1]], knapsack[i-1][j]);
				}
			}
		}				
		printf("%ld\n",knapsack[n][w]);
	}
}			
