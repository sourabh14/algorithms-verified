/* 
	Counting no of nodes at given level of tree
*/

#include <bits/stdc++.h>
#define MAXN 100

using namespace std;

int n, e; 		// n - vertices, e - edges
vector<int> g[MAXN];
bool discovered[MAXN], visited[MAXN];

int vertices_at_level[MAXN];

void init() {
	memset(visited, 0, sizeof(visited));
	memset(discovered, 0, sizeof(discovered));
	memset(vertices_at_level, 0, sizeof(vertices_at_level));
}

void join(int u, int v) {
	g[u].push_back(v);
	g[v].push_back(u);
}

void bftrav(int s) {
	list<int> que;
	int u, v, m, level;

	level = 0;
	discovered[s] = true;
	que.push_back(s);
	que.push_back(-1);

	printf("\nLevel %d: ", level);

	while (!que.empty()) {
		u = que.front();
		que.pop_front();
		if (u == -1) {	// end of level
			if (que.empty())
				break;
			else {
				level++;
				printf("\nLevel %d: ", level);
				que.push_back(-1);
			}
		}
		else {
			visited[u] = true;
			printf("%d ", u);
			vertices_at_level[level]++;

			for (v=0; v<g[u].size(); v++) {
				m = g[u][v];
				if (!discovered[m]) {
					discovered[m] = true;
					que.push_back(m);
				}
			}
		}
	}

}

int main() {
	init();
	scanf("%d", &n);
	e = n-1;

	int a, b, level;
	while (e--) {
		scanf("%d %d", &a, &b);
		join(a, b);
	}
	scanf("%d", &level);

	bftrav(0);
	printf("\nVertices at level %d: %d\n", level, vertices_at_level[level]);

	return 0;
}