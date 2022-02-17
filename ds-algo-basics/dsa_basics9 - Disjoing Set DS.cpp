/* 
	Disjoint Set DS
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	/* Disjoint Set Data Structure: 
		 - a structure that maintains a collection S1, S2, S3, …, Sn of dynamic disjoint sets. 
		 - Two sets are disjoint if their intersection is null.
		 - sets are structured as trees and represented by their root
		 - each node has a parent - maintained in array id[]
		 - the root node's parent is root itself
		 
		 Operations : - merge-set(x,y) - O(1) - merge into one set the set that contains 
		 									element x and the set that contains element y 
	 									- we maintain parent of each node - id[x]
	 									- we find root of both x and y and make id of rootx as as rooty (or vice-versa)
		 			  
		 			  - connected(x,y) - O(1) - check connectivity of x and y
		 			  		- If roots of x and y are same then they are in the same set i.e. they are connected
		 
		 Complexity : O(m+n) : m-no of operations and n- no of nodes
		 			  - O(n) : space complexity
		 
		 Application   - To determine if two nodes are connected in a graph - kruskal algo
		 			   - Better than bfs in two aspects 
		 					- Memory requirement is less
		 					- When merge-set() and connected() operations are mixed i.e. graph is dynamic - the edges are added dynamically and we need to maintain connected components as each edge is added.
		 
		 Heuristics : 
		    Union by rank - the root of the tree with fewer nodes point to the root of the tree with more nodes.
		 					- this avoids tall trees- for this we keep track of tree size sz[i]
		   
		    Path compression - make each node on the find path point directly to the root
		 					   - this keeps tree almost flat

	*/

	
	return 0;
}