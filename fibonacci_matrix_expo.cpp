/* Fibonacci number through matrix exponentiation
 * 		-When value of n is large (~10^15) and dp cannot be applied 
 * 		-Complexity : O(log-n)		
 * 
 * 		General formula
 * 			|  f(n)    |       | f(n-1) |
 * 			| f(n-1)   | = M x | f(n-2) |
 *			| ......   |       | ...... |
 *			| f(n-k+1) |       | f(n-k) |
 * 
 * 		For fibonacci k=2
 * 		|  f(n)    |    | a b | * | f(n-1) |
 * 		| f(n-1)   | = 	| c d |   | f(n-2) |
 * 
 * 		|  f(n)    |    | 1 1 | * | f(n-1) |
 * 		| f(n-1)   | = 	| 1 0 |   | f(n-2) |
 * 
 * 		for n >= 2
 * 		|  f(n)    |    | 1 1 |^(n-1)  * | 1 | 
 * 		| f(n-1)   | = 	| 1 0 |  	 	 | 0 | 	
 */

#include <bits/stdc++.h>  
#define MODU 1000000007

struct matrix {
	long long a00, a01, a10, a11;
};
typedef struct matrix MAT;	

MAT matrix_mult(MAT m1, MAT m2) {
	MAT ret;
	ret.a00 = (((m1.a00 * m2.a00) % MODU) + ((m1.a01 * m2.a10) % MODU)) % MODU;
	ret.a01 = (((m1.a00 * m2.a01) % MODU) + ((m1.a01 * m2.a11) % MODU)) % MODU;
	ret.a10 = (((m1.a10 * m2.a00) % MODU) + ((m1.a11 * m2.a10) % MODU)) % MODU;
	ret.a11 = (((m1.a10 * m2.a01) % MODU) + ((m1.a11 * m2.a11) % MODU)) % MODU;
	return ret;
}	

long long fib(long long exp) {
	MAT Base, F;
	
	Base.a00 = 1; Base.a01 = 1;
	Base.a10 = 1; Base.a11 = 0;
	
	F.a00 = 1; F.a01 = 0;				//Identity matrix
	F.a10 = 0; F.a11 = 1;
	
	while (exp > 0) {
		if (exp & 1) F = matrix_mult(F, Base);
		Base = matrix_mult(Base, Base);
		exp >>= 1;
	}
	
	return F.a00;
}	 

int main() {
	//fib(0) = 0, fib(1) = 1
	long long n = 4;		//10^10
	printf("%nth fibonacci number : lld\n", fib(n-1));
	return 0;
}	
