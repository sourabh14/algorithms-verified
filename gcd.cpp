/* GCD - Largest number that divides both number
 * 		- Euclidean algorithm -Complexity : O(log-n)
 * 		- a and b are co primes if gcd(a,b) = 1;
 * 
 * Extended GCD : Check if d is gcd of a and b
 * 		- Bezout's Identity : gcd(a, b) = ax + by  where x and y are integers
 * 
 * Modular mulplicative inverse using Bezout's identity:
 * 		- two numbers a and m
 * 		- let x be mult inverse of a : (a*x) % m == 1
 * 		- gcd(a, m) = ax + my = 1 (a and m should be co prime else inv doesn't exist)
 * 		- find x using bezout's identity
 */ 		

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int gcd1(int a, int b) {			//recursive
	if (a == 0) return b;
	return gcd1(b%a, a);
}	

int gcd2(int a, int b) {			//bottom up
	int r;
	if (a > b) swap(a, b);
	while (a > 0) {
		r = b%a; 
		b = a;
		a = r;
	}
	return b;
}	

LL ext_gcd(LL a, LL b, LL &x, LL &y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	LL x1, y1; 
	LL d = ext_gcd(b%a, a, x1, y1);
	x = y1 - (b/a) * x1;
	y = x1;
	return d;	
}	

LL mod_mult_inverse(LL a, LL m) {
	//(a*x) % m == 1
	LL x, y;
	ext_gcd(a, m, x, y);	
	if (x<0) x+=m;
	return x;
}		

int main() {
	int i, g, arr[] = {9, 27, 15, 45};
	
	g = arr[0];
	for (i=1; i<4; ++i) g = gcd2(g, arr[i]); 
	printf("g : %d\n", g);
	
	int a, b, x, y;
	a = 8; b = 12;
	g = ext_gcd(a, b, x, y);
	
	printf("Extended gcd \n");
	printf("g : %d, a : %d, x : %d,  b : %d, y : %d\n", g, a, x, b, y);
	
	//cout << "mod mult inverse  of 17 (m=3120): " << mod_mult_inverse(17, 3120) << endl;
	 
	
	return 0;
}	
