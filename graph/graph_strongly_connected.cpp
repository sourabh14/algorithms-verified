/* STRONGLY CONNECTED COMPONENT
 * 
 * Complexity - O(V+E)
 */ 
#include <cstdio>
#include <vector>
#include <cstring>

#define MAXN 1000			//maximum number of vertices
using namespace std;

//toplist gives nodes with decreasing order of finishing time for each connected component
int n, i, j, e, a, b, toplist[MAXN], topn, compn;	
vector<int> g[MAXN], g_tran[MAXN];		//g_tran is transpose graph
bool visit[MAXN], discovered[MAXN];


void init1() {		//clear previous graph entries
	for (i=0; i<n; i++) g[i].clear();
	for (i=0; i<n; i++) g_tran[i].clear();
}

void init2() {		//initialize for graph traversal		
	memset(visit,0,sizeof visit);
	memset(discovered,0,sizeof discovered);
	topn = n-1;
}

	
void dftrav(int u) {
	discovered[u] = 1;
	for (unsigned int v=0; v<g[u].size(); v++) {		//for every undiscovered vertex m connected to u
		int m = g[u][v];
		if (!discovered[m]) {							
			dftrav(m);									//dftrav m
		}	
	}
	visit[u] = 1;										//if they all are discovered then visit u
	toplist[topn--] = u;				
}

void dftrav_t(int u) {
	discovered[u] = 1;
	for (unsigned int v=0; v<g_tran[u].size(); v++) {		//for every undiscovered vertex m connected to u
		int m = g_tran[u][v];
		if (!discovered[m]) {							
			dftrav_t(m);									//dftrav m
		}	
	}
	visit[u] = 1;										//if they all are discovered then visit u			
	printf("%d ",u+1);
}		


int main() {
	scanf("%d %d",&n ,&e);			//scan no of vertices and edges
	init1();
	while (e--) {
		scanf("%d %d", &a, &b);		//a and b are vertex no (1 based indexing)
		g[a-1].push_back(b-1);
		g_tran[b-1].push_back(a-1);	//transpose graph
	}
	
	init2();					//initialization for dfs
	for (i=0; i<n; i++) {
		if (!visit[i]) {
			dftrav(i);
		}
	}	
	
	//Transpose graph
	init2();
	printf("Strongly connected components : \n");
	compn = 1;
	for (i=0; i<n; i++) {
		if (!visit[toplist[i]]) {
			printf("Component %d : ", compn++);
			dftrav_t(toplist[i]);		//dfs on transpose graph
			printf("\n");
		}	
	}
	printf("\n");	
	
	return 0;
}	

