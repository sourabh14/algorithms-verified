/*Range minimum query - sparse table matrix

Algo complexity - 
	construction - O(n-log(n))
	query - O(1)
	
space complexity - O(n-log(n))	
*/
#include <cstdio>
#include <algorithm>

#define MAXN 100005
#define MAXLG 17		//ceil(log2(MAXN))

using namespace std;

long n, q, t, i, j, qi, qj, s, arr[MAXN], st[MAXN][MAXLG];

void precompute() {
	long sz;
	for (i=0; i<n; i++) st[i][0] = arr[i];
	
	for (j=1, sz=(1<<j); sz<=n; j++, sz=(1<<j)) {
		for (i=0; i+sz-1<n; i++) {
			st[i][j] = min(st[i][j-1], st[i+(sz>>1)][j-1]);
		}
	}
}			

long query(long l, long r) {	
	int k=0;
	long sz = r-l+1;
	while (sz>>=1) k++;
	
	return min(st[l][k], st[r-(1<<k)+1][k]);
}	

int main() {
	scanf("%ld",&t);
	for (s=1; s<=t; s++) {
		scanf("%ld %ld",&n, &q);
		for (i=0; i<n; i++) scanf("%ld", &arr[i]);
		precompute();
		printf("Scenario #%ld:\n",s);
		while (q--) {
			scanf("%ld %ld",&qi, &qj);
			printf("%ld\n",query(qi-1,qj-1));
		}
	}
	return 0;
}			
