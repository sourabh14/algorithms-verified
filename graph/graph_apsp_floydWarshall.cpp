/* All pair shortest path : Floyd Warshall Algorithm
 * Dynamic programming
 * Complexity : O(V^3)
 * Space complexity : O(V^2) - For adjacency matrix
 */
  
#include <bits/stdc++.h>
#define MAXN 100											//Maximum no of vertices
#define INF 10000000

int n, e, i, j, k, wt;
int t, g[MAXN][MAXN], pred[MAXN][MAXN];

void init() {
	for (i=0; i<n; ++i) {
		for (j=0; j<n; ++j) { g[i][j] = INF; pred[i][j] = -1; }
		g[i][i] = 0;
	}	
}	

void floyd_warshall() {
	for (k=0; k<n; ++k) {
		for (i=0; i<n; ++i) {
			for (j=0; j<n; ++j) {
				if (g[i][j] > g[i][k] + g[k][j]) {
					g[i][j] = g[i][k] + g[k][j];
					pred[i][j] = pred[k][j];
				}		
			}
		}			
	}	
}

void print_path(int s, int d) {
	int path[MAXN], id=0, x;
	for (x = d; pred[s][x] != s; x = pred[s][x]) {
		path[id++] = x;
	}
	path[id++] = x; path[id++] = s; 
	
	printf("Path : ");
	for (x = id-1; x>0; --x) printf("%d -> ", path[x]+1);
	printf("%d\n", path[0]+1);
}		

int main() {
	scanf("%d %d",&n ,&e);									//scan no of vertices and edges
	init();
	while (e--) {
		scanf("%d %d %d", &i, &j, &wt);						//a and b are vertex no (1 based indexing)
		g[i-1][j-1] = wt;
		pred[i-1][j-1] = i-1;
	}
	
	floyd_warshall();					
	
	scanf("%d", &t);										//Test cases
	while (t--) {
		scanf("%d %d", &i, &j);
		if (g[i-1][j-1] != INF) {
			printf("Shortest distance from %d to %d : %d\n", i, j, g[i-1][j-1]);
			print_path(i-1, j-1);
		}
		else {
			printf("Destination unreachable\n");
		}	
	}	
	
	return 0;
}	
