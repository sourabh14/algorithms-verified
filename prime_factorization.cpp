/* Prime factorization
 * 		Complexity : O(sqrt(n))
 */ 

#include <bits/stdc++.h>
#define HIGH 1003						//set it to sqrt(MAXN)
#define MAXN 1000006

int n, x, i, factor[HIGH], freq[HIGH], nfac;

void factorize() {
	nfac = 0;
	x = n;
	
	if (x%2 == 0) {
		factor[0] = 2;
		freq[0] = 1;
		x >>= 1;
		while ((x%2) == 0) {
			freq[0]++;
			x >>= 1;
		}
		nfac++;
	}
	
	for (i=3; (i*i)<=x; i+=2) {
		if (x%i == 0) {
			factor[nfac] = i;
			freq[nfac] = 1;
			x /= i;
			while ((x%i) == 0) {
				freq[nfac]++;
				x /= i;
			}
			nfac++;
		}
	}			
	
	if (x > 2) {
		factor[nfac] = x;
		freq[nfac] = 1;
		nfac++;
	}
}			


int main() {
	n = 315;
	factorize();
	for (i=0; i<nfac; ++i) printf("(%d %d)  ", factor[i], freq[i]);
	printf("\n");
	return 0;
}	
