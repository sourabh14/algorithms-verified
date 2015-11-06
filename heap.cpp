/* Minimum priority queue - using heap
 * Operations :
 * 	Build - O(n)
 * 	Enque - O(log-n)
 * 	Deque - O(log-n)
 * 	decrease_key - O(log-n)
 */ 
#include <bits/stdc++.h>
#define INF 1000000

using namespace std;

class Heap {
	public :
	
	static const int MAXN = 10000;
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
		int l = 2*i+1;
		int r = l+1, minim = i;
		if (l<size && hp[l].key < hp[i].key) {
			minim = l;
		}
		if (r<size && hp[r].key < hp[minim].key) {
			minim = r;
		}
		if (i != minim) {
			swap(hp[i], hp[minim]);
			swap(handle[i], handle[minim]);
			min_heapify(minim);
		}
	}	
	
	void heap_deque() {							
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
		int parent, h = handle[v];
		hp[h].key = key;
		while (h>0) {
			parent = (h-1)/2;
			if (hp[parent].key > hp[h].key) {
				swap(hp[parent], hp[h]);
				swap(handle[parent], handle[h]);
				h = parent;
			}
			else break;	
		}
	}	
	
	bool heap_empty() {
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
};			

int main() {
	Heap h(6);
	printf("%d %d\n", h.get_min_ver(), h.get_min_wt());

	h.decrease_key(4, 10);
	printf("%d %d\n", h.get_min_ver(), h.get_min_wt());
	
	h.heap_deque();
	
	h.decrease_key(5, 44);
	printf("%d %d\n", h.get_min_ver(), h.get_min_wt());
	return 0;
}	



