//Basic graph - using adjacency list
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define MAXN 1000			//maximum number of vertices

using namespace std;

int n, i, e, a, b;
vector<int> g[MAXN];


void join(int a, int b) {	//for undirected graph 
	g[a-1].push_back(b-1);
	g[b-1].push_back(a-1);			
}

void init() {
	for (i=0; i<n; i++) g[i].clear();
}	

void display() {
printf("\n----adjacency list------\n");
	for (int i=0;i<n;i++) {
		printf("%d -> ",i+1);
		for (int j=0; j<g[i].size(); j++) {
			printf("%d,  ",g[i][j]+1);
		}
		printf("\n");
	}
	printf("-------------------------\n");
}

int main() {
	scanf("%d %d",&n ,&e);		//scan no of vertices and edges
	init();
	while (e--) {
		scanf("%d %d", &a, &b);		//a and b are vertex no (1 based indexing)
		join(a,b);
	}
	display();					//display graph
	return 0;
}	
