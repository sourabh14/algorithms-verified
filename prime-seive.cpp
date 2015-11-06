//Program to find if a no. is prime or not - Sieve of Eratosthenes
// complexity - for precalculation - O(n*log(log-n))
//			for each query - O(1)
// the range of values for testing prime is - 1 to 10000000
#include<cstdio>
#include<cstring>
#define HIGH 10000000			// set this as max value upto prime calculation

bool isprime[HIGH];

void sieve() {
	long i, j;
	memset(isprime,1,sizeof(isprime));
	isprime[0] = 0;
	isprime[1] = 0;
	for (i=2; i*i<=HIGH; i++) {
		if (isprime[i] == 1) { 				// if it is prime
			for (j=i*2; j<=HIGH; j+=i) {
				isprime[j] = 0;				//all its multiples are marked 0
			}	
		}
	}
}	

int main() {
	sieve();
	return 0;
}			
