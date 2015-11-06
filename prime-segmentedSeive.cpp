//Segment Sieve
#include <cstdio>
#define HIGH1 1000000000			
#define HIGH2 100000
#define PRIMESIZE 32000
using namespace std;

int prime[PRIMESIZE];				// set size to (10^9)^0.5
bool isprime[HIGH2];
int t, nop;
long m,mm,n,k,i,j,p;

void init() {						//find all primes upto 32000 and store in prime array
	int nop=0;
	for (i=3; i<PRIMESIZE; i+=2) { isprime[i] = 1; }		//make all odds as prime
	
	for (i=3; i*i<=PRIMESIZE; i+=2) {
		if (isprime[i]) { 				// if it is prime
			for (j=i*2; j<=PRIMESIZE; j+=i) {
				isprime[j] = 0;			//all its multiples are marked 0
			}	
		}
	}
	
	prime[nop++] = 2;					//add 2 to prime list
	
	for (i=3;i<PRIMESIZE;i++) {
		if (isprime[i]) prime[nop++] = i;			//add it to prime array
	}	
}
	
main() {
	init();
	scanf("%d",&t);
	while (t--) {
		scanf("%ld %ld",&m, &n);					//segment from m to n
		
		for (i=0; i<(n-m+1); i++) isprime[i] = 1; 
		if (m == 1) isprime[0] = 0;
		
		for (i=0,p=prime[i];  p*p<=n;  i++,p=prime[i]) {
			if (m%p == 0) j = m;
			else j = (m/p + 1)*p;					//find first multiple of p >= m
			if (j == p) j+=p;
			
			for (; j<=n; j+=p) {				//mark all multiples of p as - not prime
				isprime[j-m] = 0;
			}	
		}	
		
		for (i=0;i<(n-m+1);i++) {
			if (isprime[i]) printf("%ld\n",i+m);
		}	
	}	
}			
