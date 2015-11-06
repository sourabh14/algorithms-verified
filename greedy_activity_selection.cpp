//Greedy - Activity selection
#include <cstdio>
#include <algorithm>
#define MAXN 100005
using namespace std;

struct Activity {
	int st, end;
} ac[MAXN];

int t, n, i, cnt, cur_end;

int cmp(struct Activity a, struct Activity b) {
	return  a.end == b.end ? (a.st < b.st ? 1 : 0) : (a.end < b.end ? 1 : 0);
}	  
	
int main() {
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		for (i=0; i<n; i++) scanf("%d %d",&ac[i].st, &ac[i].end);
		sort(ac, ac+n, cmp);		//sort according to finish time
		
		cnt = 0;
		cur_end=0;
		for (i=0; i<n; i++) {
			while ((ac[i].st < cur_end) && (i<n)) i++;
			if (i != n) {
				cnt++;
				cur_end = ac[i].end;
			}	
		}
		
		printf("%d\n",cnt);
	}
	return 0;
}			
		
