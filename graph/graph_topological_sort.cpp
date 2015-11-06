/*Topological Sort of directed acyclic graph
 * Ordering of vertices along horizontal line so that all directed edges 
 * go from left to right
 * 
 * Whenever a vertex is finished in DFS it is inserted in front of list
 * 
 * Complexity : O(V+E) (same as dfs)
 */ 
#include <cstdio>
#include <vector>
#include <cstring>

#define MAXN 1000			//maximum number of vertices
using namespace std;

int n, i, e, a, b, toplist[MAXN], topn;
vector<int> g[MAXN];
bool visit[MAXN], discovered[MAXN];


void init1() {		//clear previous graph entries
	for (i=0; i<n; i++) g[i].clear();
}

void init2() {		//initialize for graph traversal		
	memset(visit,0,sizeof(visit));
	memset(discovered,0,sizeof(discovered));
	topn = n-1;
}

void join(int a, int b) {			 
	g[a-1].push_back(b-1);		
}

	
void dftrav(int u) {
	discovered[u] = 1;
	for (unsigned int v=0; v<g[u].size(); v++) {					//for every undiscovered vertex m connected to u
		int m = g[u][v];
		if (!discovered[m]) {							
			dftrav(m);									//dftrav m
		}	
	}
	visit[u] = 1;										//if they all are discovered then visit u
	toplist[topn--] = u;				
}	

	


int main() {
	scanf("%d %d",&n ,&e);			//scan no of vertices and edges
	init1();
	while (e--) {
		scanf("%d %d", &a, &b);		//a and b are vertex no (1 based indexing)
		join(a,b);
	}
	
	init2();					//initialization for dfs
	for (i=0; i<n; i++) {
		if (!visit[i]) {
			dftrav(i);
		}
	}		
	
	printf("Topological list : ");
	for (i=0; i<n; i++) {
		printf("%d ",toplist[i]+1);
	}
	printf("\n");	
	
	return 0;
}	
