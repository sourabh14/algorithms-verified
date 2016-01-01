//gray code for n bit value, binary to gray code
#include <iostream>
#include <string>
using namespace std;
	
int main() {
	int nbit = 3; 			
	for (int i=0; i<(1<<nbit); i++) {
		cout << "gray code for " << i << " " << (i^(i>>1)) << endl;
	}	
	return 0;
}	
