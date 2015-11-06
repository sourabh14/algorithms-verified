/* BINARY TRIE : 0 and 1
 * 	MAXB = log2(MAXN)			MAXB is max bits reqd to represent array element
 *  Insertion : O(MAXB)			
 *  Query : O(MAXB)
 *  
 * 	Given an array of integers, find two elements whose XOR is maximum
 *  Complexity : O(MAXB * n)
 */
 
#include <bits/stdc++.h>
#define MAXN 100005
#define MAXB 17

int n, i, arr[MAXN];
int trie_size, trie_root, maxor, x;								//total nodes in trie

struct trie_node {
	int lef, rit;
} trie[MAXN];
	
void init() {
	trie_size = trie_root = 0;
	for (i=0; i<n; ++i) {
		trie[i].lef = trie[i].rit = -1;
	}
}		

void trie_insert(int a) {
	int b, node = trie_root;
	
	for (b = MAXB-1; b>=0; --b) {
		if ( ((1<<b) & a) == 0 ) {				//go left
			if (trie[node].lef == -1) {
				trie[node].lef = ++trie_size;
			}
			node = trie[node].lef;
		}
		else {									//go right
			if (trie[node].rit == -1) {
				trie[node].rit = ++trie_size;
			}
			node = trie[node].rit;		
		}
	}			
}

int trie_max_xor(int a) {	
	int ret = 0, b, node = trie_root;
	
	for (b = MAXB-1; b>=0; --b) {
		if ( ((1<<b) & a) == 0 ) {			
			if (trie[node].rit != -1) {
				ret |= (1<<b);
				node = trie[node].rit; 
			}
			else node = trie[node].lef; 
		}
		else {							
			if (trie[node].lef != -1) {
				ret |= (1<<b);
				node = trie[node].lef; 
			}
			else node = trie[node].rit; 	
		}
	}	
	
	return ret;
}

int main() {
	scanf("%d", &n);
	for (i=0; i<n; ++i) scanf("%d", &arr[i]);
	init();
	 
	trie_insert(arr[0]);
	maxor = 0;
	for (i=1; i<n; ++i) {
		x = trie_max_xor(arr[i]);
		if (maxor < x) { maxor = x; }
		trie_insert(arr[i]);
	}	
	
	/* printf("trie : ");
	for (i=0; i<trie_size; ++i) printf("[%d %d]  ", trie[i].lef, trie[i].rit);
	printf("\n\n");
	*/ 
	  
	printf("%d\n", maxor);
	  
	return 0;
}	  	  
		  
