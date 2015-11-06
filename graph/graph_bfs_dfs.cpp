/*Graph traversal - BFS and DFS
- complexity O(V+E) 
- For BFS, dist[i] is the minimum no of edges from source to any 'i'
  for unweighted graph this gives min distance from source vertex 
  if any vertex is unreachable its dist is INF
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

#define MAXN 1000			//maximum number of vertices
#define INF 1000000

using namespace std;

int n, i, e, a, b, dist[MAXN];
vector<int> g[MAXN];
bool visit[MAXN], discovered[MAXN];


void init1() {		//clear previous graph entries
	for (i=0; i<n; i++) g[i].clear();
}

void init2() {		//initialize for graph traversal		
	memset(visit,0,sizeof(visit));
	memset(discovered,0,sizeof(discovered));
	memset(dist,INF,sizeof(dist));
}

void join(int a, int b) {			//for undirected graph 
	g[a-1].push_back(b-1);
	g[b-1].push_back(a-1);			
}

void bftrav(int s) {					//s is the source	
	init2();		
	queue<int> que;		
	discovered[s] = true;
	dist[s] = 0;
	que.push(s);
	
	while (!que.empty()) {
		int m;
		int u = que.front(); 
		que.pop();	
		visit[u] = 1;
		
		printf("%d ",u+1);
		
		for (unsigned int v=0; v<g[u].size(); v++) {					//for every undiscovered vertex m connected to u
			m = g[u][v];
			if (!discovered[m]) {							//push it to que
				discovered[m] = true;
				dist[m] = dist[u] + 1;
				que.push(m);
			}	
		}	
	}
}				
	
	
void dftrav(int u) {
	discovered[u] = 1;
	for (unsigned int v=0; v<g[u].size(); v++) {				//for every undiscovered vertex m connected to u
		int m = g[u][v];
		if (!discovered[m]) {							
			dftrav(m);									//dftrav m
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
		join(a,b);
	}
							//for traversal- give source according to 0-based indexing
	printf("bfs : ");
	bftrav(0);
	printf("\n");
	
	init2();					//initialization for dfs
	printf("dfs : ");
	dftrav(0);
	printf("\n");
	
	return 0;
}	
