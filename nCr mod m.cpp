/* nCr % p -
 * 		Using recurrance - when n is small ~ 10000
 * 			precompute : O(MAXN * MAXR)
 * 			query : O(1)
 * 		Using lucas theorem where - n is large, p is prime
 * 			query : O(n)
 */
 
#include <bits/stdc++.h>
#define MAXN 10000
#define MAXR 10000
#define MODU 1000000007		//10^9 + 7

int i, j;

//----------------------Recurrance----------------------
long long C[MAXN][MAXR];

void precompute() {
	for (i=0; i<MAXN; ++i) { C[i][0] = 1; C[i][i] = 1; }
	
	for (i=2; i<MAXN; ++i) {
		for (j=1; j<i; ++j) {
			C[i][j] = C[i-1][j-1] + C[i-1][j];
			if (C[i][j] > MODU) C[i][j] -= MODU;
		}
	}
}	

//------------------------------------------------------

//-------------------------Lucas------------------------

int modPow(int a, int x, int p) {	
	//calculates a^x % p
    int res = 1;
    while (x > 0) {
        if (x & 1) res = (res * a) % p;
        a = (a * a) % p;
        x >>= 1;
    }
    return res;
}

int modInverse(int a, int p) {
    //calculates the modular multiplicative of a mod m
    return modPow(a, p-2, p);
}
int modBinomial(int n, int r, int p) {
	// calculates C(n,r) mod p (assuming p is prime).

    int numerator = 1; // n * (n-1) * ... * (n-r+1)
    for (int i=0; i<r; i++) {
        numerator = (numerator * (n-i) ) % p;
    }

    int denominator = 1; // r!
    for (int i=1; i<=r; i++) {
        denominator = (denominator * i) % p;
    }

    // numerator / denominator mod p.
    return ( numerator* modInverse(denominator,p) ) % p;
}

//------------------------------------------------------	

int main() {
	//precompute();
	//printf("%lld\n", C[100][2]);
	int p = 73;
	printf("%d\n", modBinomial(10, 2, p));
	return 0;
}	 
