/* GCD - Largest number that divides both number
 * 		- Euclidean algorithm -Complexity : O(log-n)
 * 		- a and b are co primes if gcd(a,b) = 1;
 * 
 * Extended GCD : Check if d is gcd of a and b
 * 		- Bezout's Identity : gcd(a, b) = ax + by  where x and y are integers
 */ 		

#include <bits/stdc++.h>
using namespace std;

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

int ext_gcd(int a, int b, int &x, int &y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1; 
	int d = ext_gcd(b%a, a, x1, y1);
	x = y1 - (b/a) * x1;
	y = x1;
	return d;	
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
	return 0;
}	
