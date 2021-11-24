/* 
	MST - Prim, Kruskal algo
	Dijkstra
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	/* Spanning Tree
		-Given a connected and undirected graph, a spanning tree of that graph is a subgraph that is a tree and connects all the vertices together. 

	Minimum Spanning Tree 
		- A single graph can have many different spanning trees. MST is a spanning tree with minimum weight.
		- A minimum spanning tree has (V – 1) edges where V is the number of vertices in the given graph. 

	Applications of MST
		- Network design.
			- telephone, electrical, hydraulic, TV cable, computer, road
			- The standard application is to a problem like phone network design. You have a business with several offices; you want to lease phone lines to connect them up with each other; and the phone company charges different amounts of money to connect different pairs of cities. You want a set of lines that connects all your offices with a minimum total cost. 	
		- Cluster analysis
			k clustering problem can be viewed as finding an MST and deleting the k-1 most expensive edges.

	*/

	/* Kruskal algo
		- Greedy strategy. It grows MST one edge at a time
		- Algo
			- Sort all the edges in non-decreasing order of their weight. 
			- Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If cycle is not formed, include this edge. Else, discard it. 
			- Repeat step#2 until there are (V-1) edges in the spanning tree.
		- We use disjoint set ds for detecting cycle
 
	*/	

	/* Prim's Algo
		- Greedy strategy.  
		- The idea is to maintain two sets of vertices. The first set contains the vertices already included in the MST, the other set contains the vertices not yet included. 
		- At every step, it considers all the edges that connect the two sets, and picks the minimum weight edge from these edges. 
		- After picking the edge, it moves the other endpoint of the edge to the set containing MST. 

		- A group of edges that connects two set of vertices in a graph is called cut in graph theory. 
		- So, at every step of Prim’s algorithm, we find a cut (of two sets, one contains the vertices already included in MST and other contains rest of the vertices), pick the minimum weight edge from the cut and include this vertex to MST Set 

	*/

	/* Dijkstra’s shortest path algorithm 
		- Find the shortest paths from the source to all vertices in the given graph.
		- Like Prim’s MST, we generate a SPT (shortest path tree) with a given source as a root. 
		- We maintain two sets, one set contains vertices included in the shortest-path tree, other set includes vertices not yet included in the shortest-path tree. At every step of the algorithm, we find a vertex that is in the other set (set of not yet included) and has a minimum distance from the source.
		-  If we are interested only in the shortest distance from the source to a single target, we can break the for loop when the picked minimum distance vertex is equal to the target
		- Dijkstra’s algorithm doesn’t work for graphs with negative weight cycles. For graphs with negative weight edges and cycles, Bellman–Ford algorithm can be used,

		ADJACENCY LIST IMPLEMENTATION:
  			Total complexity : O(V^2)
  
  		USING BINARY HEAP AS MINIMUM PRIORITY QUEUE
  			For sparse graph i.e   E << O(v^2)
  			Total complexity : O(E*log-V)

		Eg: https://youtu.be/smHnz2RHJBY?list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU
		

	*/
	return 0;
}