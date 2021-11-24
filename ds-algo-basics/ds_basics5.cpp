/* 
	Graph - DFS, BFS
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	/* Graph - a non-linear data structure consisting of nodes and edges. Nodes are a.k.a vertices. The edges may contain weight/value/cost.

	Application: Graphs are used to represent networks. The networks may include paths in a city or telephone network or circuit network.

	Graph traversal - BFS, DFS - complexity O(V+E)

	BFS - explores all the edges to discover every vertex reachable from source.
	Application:
		- BFS gives shortest path i.e. smallest number of edges to reach vertex from source. It works for both directed and undirected graph.
		- We can maintain predecessor vertex to trace the shortest path.
		-Peer to Peer Networks. In Peer to Peer Networks like BitTorrent, Breadth First Search is used to find all neighbor nodes.
		-Social Networking Websites: In social networks, we can find people within a given distance ‘k’ from a person using Breadth First Search till ‘k’ levels.
		-GPS Navigation systems: Breadth First Search is used to find all neighboring locations.

	DFS - explores as far as possible along each branch before backtracking. 
	Application
		-Detecting cycle in a graph 
		-to find a path between two given vertices
		-Topological sort
		-Finding Strongly Connected Components of a graph

	*/

	/* Topological Sort of DAG
		- linear ordering of all vertices along horizontal line such that all directed edges go from left to right
		- Algo
			- DFS traversal
			- after completion of each node insert it in front of a linked list
		-application : to indicate precedence among events

	*/

	/* Strongly connected components (SCC) for directed graph
		- classic application of DFS
		- maximal set of vertices 'C' such that for every pair of vertices (u,v) in 'C' we have path from u to v and v to u. That is u and v are reachable from each other
		- Algo
			- DFS traversal
			- after completion of each node insert it in front of a linked list
			- On transpose graph, perform dfs starting from vertices given in linked list.
			- each traversal will give SCC
 
	*/	
	return 0;
}