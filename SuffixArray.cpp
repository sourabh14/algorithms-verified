/*SUFFIX ARRAY - The suffixes of a string are sorted according to lexicographic (dictionary) order.
	COMPLEXITY - O(n-(log-n)^2) 
	The algorithm is mainly based on maintaining the order of the string’s suffixes sorted by their 
	2^k long prefixes.
	The suffix array will be found on the last row of matrix P.

LARGEST COMMON PREFIX(LCP) of suffixes of a string..

Application : No of different substring in a string. (for substring definition see wiki page)
*/

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define MAXN 100005		//max length of string
#define MAXLG 20		//log2(MAXN)	

char str[MAXN];

struct entry {
	int nr[2], p;
} L[MAXN];

long P[MAXLG][MAXN], n, i, stp, cnt, SufArr[MAXN], lcp[MAXN], t, q, k, ind, l;


int cmp(struct entry a, struct entry b) {
	return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}


void makelcp() {		//lcp[i] is lcp of sufarr[i-1] and [i]
	int k, x, y;
	
	for (i=1; i<n; i++) {
		x = SufArr[i-1];
		y = SufArr[i];
		lcp[i] = 0;
		
		for (k = stp - 1; k >= 0 && x < n && y < n; k --) {
			if (P[k][x] == P[k][y])
			x += 1 << k, y += 1 << k, lcp[i] += 1 << k;
		}
	}		
}

void suffixSort() {
	for (i = 0; i < n; i++) {			
		P[0][i] = str[i] - 'a';
	}	
	//P[i][j] stores rank of i-th prefix when sorted at jth step
	
	// At k-th step : 2^(k) + 1 length suffix, of prefixes of given string are sorted 
	
	for (stp = 1, cnt = 1; (cnt >> 1) < n; stp++, cnt <<= 1) {
		for (i = 0; i < n; i++) {
			L[i].nr[0] = P[stp - 1][i];
			L[i].nr[1] = i + cnt < n ? P[stp - 1][i + cnt] : -1;
			L[i].p = i;
		}
		sort(L, L + n, cmp);
		for (i = 0; i < n; i ++)
		P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ?
		P[stp][L[i - 1].p] : i;
	}

	for (i=0; i<n; i++) {
		SufArr[P[stp-1][i]] = i;
	}
}

int main() {
	scanf("%s",str);
	n=strlen(str);
	suffixSort();
 	makelcp();
	
	printf("Suffix array : ");
	for (i=0; i<n; i++) printf("%ld ",SufArr[i]);
	printf("\n");
	
	printf("Lcp array : ");
	for (i=0; i<n; i++) printf("%ld ",lcp[i]);
	printf("\n");	 
	return 0;
}
