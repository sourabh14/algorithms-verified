/* Minimum spanning tree- Kruskal algo
 * Using disjoint set ds
 * Complexity : O(E-log(V)) 
 */ 
 
#include <bits/stdc++.h>
#define MAXN 1000					//maximum number of vertices
#define MAXE 10000					//maximum number of edges

using namespace std;

//Graph var
struct edge_node {
	int wt, u, v;
} edge[MAXE];	
int n, e, i, cnt, mst_wt;
vector<int> mst[MAXN];

//Disjoint set ds var
int id[MAXN], sz[MAXN], x, y;;


void init() {
	for (i=0; i<n; ++i) {
		mst[i].clear();
		id[i] = i;
	}
	memset(sz, 1, sizeof(sz));	
}

//------------------Disjoint set ds------------------

int root(int p) {
	while (p!=id[p]) {
		id[p] = id[id[p]]; 				//path compression
		p = id[p];					
	}
	return p;
}

bool connected(int p, int q) {
	return (root(p) == root(q));
}	
		
void merge_set(int p,int q) {
	int rootp = root(p);				
	int rootq = root(q);
	if (sz[rootp] < sz[rootq]) {		//union by rank	
		id[rootp] = rootq;				
		sz[rootq] += sz[rootp];
	}
	else {
		id[rootq] = rootp;
		sz[rootp] += sz[rootq];
	}
}

//---------------------------------------------------


//-----------------------MST-------------------------

void join(int a, int b) {			 
	mst[a].push_back(b);
	mst[b].push_back(a);			
}

int cmp(struct edge_node a, struct edge_node b) {
	return (a.wt < b.wt) ? 1 : 0;
}

void build_mst() {
	mst_wt = 0, cnt = 0;						//number of edges added in mst
	
	sort(edge, edge + e, cmp);					//sort according to edge weight
	for (i=0; i<e; ++i) {
		x = edge[i].u;
		y = edge[i].v;
		if ( !connected(x, y) ) {
			join(x, y);							//add edge to mst
			merge_set(x, y);
			cnt++;
			mst_wt += edge[i].wt;
		}
		
		if (cnt == (n-1)) break;
	}	
}	
	 
void display_mst() {
	printf("\n----MST adjacency list----\n");
	for (i=0; i<n; ++i) {
		printf("%d -> ", i+1);
		for (unsigned int j=0; j<mst[i].size(); ++j) {
			printf("%d,  ", mst[i][j]+1);
		}
		printf("\n");
	}
	printf("--------------------------\n\n");
	
	printf("Total MST weight : %d\n", mst_wt);
}
	 
//---------------------------------------------------------	 

int main() {
	scanf("%d %d",&n ,&e);											//scan no of vertices and edges
	init();
	for (i=0; i<e; ++i) {
		scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].wt);		
		edge[i].u--, edge[i].v--;
	}
	
	build_mst();
	display_mst();
	
	return 0;
}	
