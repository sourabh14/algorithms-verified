/* DIJKSTRA ALGORITHM - Complexity : O(V*Tem + E*Tdk)
 * 		-Tem - time for extracting minimum ; Tdk - time for decreasing key
 * 
 * 		LINK LIST IMPLEMENTATION:
 * 			Tem : O(V) and Tdk = O(1)
 * 			Total complexity : O(V^2 + E) = O(V^2)
 * 
 * 		USING BINARY HEAP AS MINIMUM PRIORITY QUEUE
 * 			For sparse graph i.e   E << O(v^2)
 * 			Tem : O(log-V) and Tdk = O(log-V)
 * 			Total complexity : O((V + E) * log-V) = O(E*log-V)
 */ 
#include <bits/stdc++.h>
#define MAXN 10000											//maximum number of vertices
#define INF 100000000

using namespace std;

int n, i, e, a, b, t, wt, mindis;
int sor, dest, pred[MAXN], dist[MAXN];
bool finl[MAXN];
struct graph_node {
	int ver, wt;
};	
vector<struct graph_node> g[MAXN];

/* sor - source
 * dest - destination
 * pred[i] denotes predecessor of vertex i in shortest path\
 * finl[i] - true when shortest path from sor is determined
 * 			 dijkstra ends when final[dest] is true
 * dist[i] - minimum distance from sor to i
 */


//----------------------Graph--------------------------------

void join(int a, int b, int w) {			//for directed graph 
	struct graph_node n;
	n.ver = b-1; n.wt = w;
	g[a-1].push_back(n);			
}

void init() {
	for (i=0; i<n; i++) g[i].clear();
}	

//------------------------------------------------------------



//---------------------------Heap-----------------------------

class Heap {
	public :
	
	//static const int MAX = 10000;			//max elements in heap
	struct heapnode {
		int key, vno;
	} hp[MAXN];	
	int size, handle[MAXN];					//handle keeps track where is the vertex in heap	
	
	Heap(int n) {
		size = n;
		for (int i=0; i<n; ++i) {
			hp[i].key = INF;			//first is heap key	
			hp[i].vno = i;				//second is vertex no
			handle[i] = i;
		}
	}
	
	void min_heapify(int i) {			
		//Bubble down the argument vertex(i) ; complexity - O(lg-n)
		int l = 2*i + 1, v1, v2;
		int r = l+1, minim = i;
		if (l<size && hp[l].key < hp[i].key) {
			minim = l;
		}
		if (r<size && hp[r].key < hp[minim].key) {
			minim = r;
		}
		if (i != minim) {
			v1 = hp[i].vno; v2 = hp[minim].vno;
			swap(hp[i], hp[minim]);
			swap(handle[v1], handle[v2]);
			min_heapify(minim);
		}
	}	
	
	void deque() {							
		//Remove top element from heap : complexity - O(log-n)
		int top;
		hp[0] = hp[size-1];
		size--;
		top = hp[0].vno;
		handle[top] = 0;
		min_heapify(0);
	}	 
	
	void decrease_key(int v, int key) {		
		//bubbles up the changed vertex : complexity - O(log-n)
		int parent, h = handle[v], vp;
		hp[h].key = key;
		while (h>0) {
			parent = (h-1)/2;
			vp = hp[parent].vno;
			if (hp[parent].key > hp[h].key) {
				swap(hp[parent], hp[h]);
				swap(handle[vp], handle[v]);
				h = parent;
			}
			else break;	
		}
	}	
	
	bool empty() {
		if (size > 0) return false;
		return true;
	}	
	
	int get_min_ver() {
		return hp[0].vno;
	}
	
	int get_min_wt() {
		return hp[0].key;
	}	
	
	int get_wt(int ver) {
		int han = handle[ver];
		return hp[han].key;
	}	
	
	void display() {
		printf("heap : ");
		for (int i=0; i<size; ++i) printf("[%d %d]  ", hp[i].vno+1, hp[i].key);
		printf("\n");
		
		printf("handle : ");
		for (int i=0; i<5; ++i) printf("%d  ", handle[i]+1);
		printf("\n");
	}	
};	


//----------------------------------------------------------------



//---------------------------Dijkstra------------------------------
void init2() {
	memset(pred, -1, sizeof pred);
	memset(finl, 0, sizeof finl);
	memset(dist, INF, sizeof dist);
}	


int dijkstra(int s, int d) {
	int u, v, udis, vdis;
	Heap pri_q(n);											//create priority queue with n elements
	init2();
	
	pred[s] = s;
	pri_q.decrease_key(s, 0);
	
	while ( !pri_q.empty() ) {			
		u = pri_q.get_min_ver();							// extract minimum dist vertex from heap
		dist[u] = pri_q.get_min_wt();						// get its weight
		udis = dist[u];
		
		pri_q.deque();												//remove top element from heap
		
		if (dist[u] == INF) break;									//dest is unreachable
		
		finl[u] = true;
		if (finl[d]) break;											//dest is found
		
		for (unsigned int i=0; i<g[u].size(); ++i) {
			v = g[u][i].ver;
			if (!finl[v]) {											// if v is not in finl list
				vdis = pri_q.get_wt(v);
				if (vdis > udis + g[u][i].wt) {						// relax operation
					pri_q.decrease_key(v, udis + g[u][i].wt);
					pred[v] = u;
				}	
			}	
		}
	}		
	
	return dist[d];
}	

void print_path(int des) {
	int path[MAXN], id=0;
	for (i=des; pred[i]!=i; i=pred[i]) {
		path[id++] = i+1;
	}
	path[id++] = i+1;
	printf("Path : ");
	for (i=id-1; i>0; i--) printf("%d -> ", path[i]);
	printf("%d\n", path[0]);	
}	

//---------------------------------------------------------	

int main() {
	scanf("%d %d",&n ,&e);											//scan no of vertices and edges
	init();
	while (e--) {
		scanf("%d %d %d", &a, &b, &wt);								//a and b are vertex no (1 based indexing)
		join(a, b, wt);
	}
	
	scanf("%d", &t);
	while (t--) {													// test cases
		scanf("%d %d", &sor, &dest);
		mindis = dijkstra(sor-1, dest-1);
		if (finl[dest-1]) {											//dest is reachable
			printf("Shortest distance from %d to %d : %d\n", sor, dest, mindis);
			print_path(dest-1);
		}
		else {
			printf("Destination unreachable\n");
		}		
	}	
	
	return 0;
}	
