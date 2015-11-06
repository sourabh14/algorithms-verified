/* DISJOINT SET DATA STRUCTURE : a structure that maintains a collection S1, S2, S3, …, Sn of 
 * dynamic disjoint sets. Two sets are disjoint if their intersection is null.
 * 
 * Operations : merge-set(x,y) - O(1) - merge into one set the set that contains 
 * 									element x and the set that contains element y 
 * 			  - connected(x,y) - O(1) - check connectivity of x and y
 * 
 * Complexity : O(m+n) : m-no of operations and n- no of nodes
 * 			  - O(n) : space complexity
 * 
 * Application : To determine if two nodes are connected in a graph 
 * 			   - Better than bfs in two aspects 
 * 					- Memory requirement is less
 * 					- When merge-set() and connected() operations are mixed 
 * 
 * Heuristics : 
 *    Union by rank - the root of the tree with fewer nodes point to the root of the tree with more nodes.
 * 					- this avoids tall trees- for this we keep track of tree size sz[i]
 *    Path compression - make each node on the find path point directly to the root
 * 					   - this keeps tree almost flat	
 */

#include <cstdio>
#include <cstring>

#define MAXN 100005

int n, m, i, x, y, ch;
int id[MAXN], sz[MAXN];

void init() {
	for (i=0; i<n; i++)  id[i] = i;
	memset(sz, 1, sizeof(sz));
}
	
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

int main() {
	scanf("%d %d", &n, &m);
	init();
	while (m--) {
		scanf("%d %d %d", &ch, &x, &y);
		if (ch == 1) {		 				//merge-set 
			if (!connected(x-1,y-1)) {	
				merge_set(x-1,y-1);
			} 
		}
		else {								//connnected
			if (connected(x-1, y-1)) printf("connected\n");	
			else printf("not connected\n");
		}
	}
	return 0;		
}
