//BFS on n X m matrix - and find size and no of each connected component
#include <cstdio>
#include <queue>
#include <cstring>

#define MAXN 251	//max no of rows(n) or col(m)

using namespace std;

int n, m, i, j, v;
int slick[MAXN * MAXN], sln;				//slick[i] denotes no of slicks of size i
bool g[MAXN][MAXN], discovered[MAXN][MAXN];


void init() {
	sln = 0;
	memset(g, 0, sizeof(g));
	memset(discovered, 0, sizeof(discovered));
	memset(slick, 0, sizeof(slick));
}	

void bftrav(int x, int y) {
	queue<int> que;
	int a, b, slsz=0;
	que.push(x); que.push(y);
	discovered[x][y] = true;
	
	while (!que.empty()) {
		a = que.front(); que.pop();
		b = que.front(); que.pop();
		slsz++;
		
		//left
		if (b-1>=0 && g[a][b-1] && !discovered[a][b-1]) {
			que.push(a); que.push(b-1);
			discovered[a][b-1] = true;
		}	
		//right
		if (b+1<m && g[a][b+1] && !discovered[a][b+1]) {
			que.push(a); que.push(b+1);
			discovered[a][b+1] = true;
		}	
		//up
		if (a-1>=0 && g[a-1][b] && !discovered[a-1][b]) {
			que.push(a-1); que.push(b);
			discovered[a-1][b] = true;
		}	
		//down
		if (a+1<n && g[a+1][b] && !discovered[a+1][b]) {
			que.push(a+1); que.push(b);
			discovered[a+1][b] = true;
		}	
	}	
	
	slick[slsz]++;
}			

int main() {
	scanf("%d %d", &n, &m);
	while (n != 0) {
		init();
		//input
		for (i=0; i<n; i++) {
			for (j=0; j<m; j++) {
				scanf("%d", &v);
				if (v) g[i][j] = true;
			}
		}
		
		//for each unvisited cell
		for (i=0; i<n; i++) {
			for (j=0; j<m; j++) {
				if (g[i][j] && !discovered[i][j]) {
					sln++;
					bftrav(i, j);
				}
			}
		}
		
		printf("%d\n",sln);
		for (i=1; i<=(n*m); i++) {
			if (slick[i] > 0) {
				printf("%d %d\n",i, slick[i]);
			}
		}					
				
		scanf("%d %d", &n, &m);
	}
	return 0;
}		
