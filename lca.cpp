/* Lowest common ancestor (LCA) on tree - using DFS and RMQ 
 * 
 * Euler tour using DFS : O(n) where n - number of nodes
 * 
 * RMQ - Using sparse table matrix 
 * 			algorithmic complexity : Preprocessing - O(n*log-n)
 * 								   : Query - O(1)
 *			space complexity : O(n*log-n)
 * 
 * Overall complexity : Preprocessing- O(n*log-n)
 * 					  : Query : O(1)
*/

#include <bits/stdc++.h>

#define MAXN 1003		//vertices on tree
#define MAXE 2003		//max size of euler tour (dfs) = 2*n - 1
#define MAXLG 12		//ceil(log2(MAXE))

using namespace std;

int n, q, v1, v2, i, j;

//tree, dfs
vector<int> g[MAXN];
bool discovered[MAXN];

//lca
int E[MAXE], L[MAXE], H[MAXN], en;	

/* E[i] : euler tour
 * L[i] : level of node during euler tour
 * H[i] : first occurance of ith node in E 
 * en : length of euler tour
 */ 

//RMQ
struct {
	int mn, indx;
} st[MAXE][MAXLG];
 

//-------------------------Euler tour-------------------------

void init_dfs() {				
	memset(discovered, 0, sizeof discovered);
	memset(H, -1, sizeof H);
	en = 0;								
}

void dftrav(int u, int lev) {
	discovered[u] = 1;
	
	if (H[u] == -1) H[u] = en;
	L[en] = lev;
	E[en++] = u;
	
	for (unsigned int v=0; v<g[u].size(); v++) {					//for every undiscovered vertex m connected to u
		int m = g[u][v];
		if (!discovered[m]) {	
			dftrav(m, lev+1);							//dftrav m
			L[en] = lev;
			E[en++]=u;
			
		}	
	}		
}

//------------------------------------------------------------


//------------------------- RMQ ----------------------------

void rmq_precompute() {
	// range minimum in L[]
	int sz;
	for (i=0; i<en; ++i) {
		st[i][0].mn = L[i];
		st[i][0].indx = i;
	}	
	
	for (j=1, sz=(1<<j); sz<=en; j++, sz=(1<<j)) {
		for (i=0; (i+sz-1)<en; i++) {
			if (st[i][j-1].mn < st[i+(sz>>1)][j-1].mn) {
				st[i][j] = st[i][j-1];
			}
			else {
				st[i][j] = st[i+(sz>>1)][j-1];
			}	
		}
	}
}			

int rmq_indx(int l, int r) {			//returns index of min value from [l,r]
	int k=0;
	int sz = r-l+1;
	while (sz>>=1) k++;
	
	if (st[l][k].mn < st[r-(1<<k)+1][k].mn) 
		return st[l][k].indx;
	else 	
		return st[r-(1<<k)+1][k].indx;
}	

//------------------------------------------------------------


//--------LCA---------

int lca(int u, int v) {
	int eu, ev, eid;
	eu = H[u-1]; 
	ev = H[v-1];
	if (eu > ev) swap(eu, ev);
	eid = rmq_indx(eu, ev);
	return E[eid] + 1;
}	

//--------------------
	
int main() {
	//input
	scanf("%d", &n);						//vertex id is from 1 to n
	for (i=0; i<n-1; ++i) {
		scanf("%d %d", &v1, &v2);
		g[v1-1].push_back(v2-1);
		g[v2-1].push_back(v1-1);
	}
	
	//precompute
	init_dfs();
	dftrav(0, 0);
	rmq_precompute();
	
	//query
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d", &v1, &v2);
		printf("lca of %d and %d : %d\n", v1, v2, lca(v1, v2));
	}		
	
	return 0;
}	
