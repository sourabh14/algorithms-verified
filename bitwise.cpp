//operators : & | ^ ~ << >> 
#include<cstdio>
main() {
	//we use an integer to represent a set on a domain of up to 32 values 
	//with a 1 bit representing a member that is present and a 0 bit one that is absent
	/*
	A | B //set union
	A & B //set intersection
	A & ~B //set substraction
	
	A |= 1 << bit	//set bit
	A &= ~(1 << bit)	//clear bit
	(A & 1 << bit) != 0	//test bit
	*/
	int n = __builtin_ctz(10);		//count trailing zeroes

	
	n = __builtin_clz(23);			//count leading zeroes
	
	n = __builtin_popcount(10);		//count no of set (1) bits
	printf("%d\n",n); 	
	 

	// to check if no is power of two check popcount is 1 or not
	
	n & ~(n-1)			//to get lowest set bit
}	


