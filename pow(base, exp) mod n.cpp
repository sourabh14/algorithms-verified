/* Power function : (base ^ exp) % modulo
 * 		query : O(log-n)
 */ 
  
#include <cstdio> 

int modPow(int base, int exp, int modulo) {
	int result = 1;
	while (exp>0) {
		if (exp & 1) result = (result * base)%modulo;
		base = (base*base)%modulo;
		exp >>= 1;
	}
	return result;
}		
			
int main() {
	printf("%d\n", modPow(3, 6, 100000));
	return 0;
}
