#include<iostream>
#include<vector>
#define INF 10000000

using namespace std;

main() {
	vector<int> c = {1,3,5};			//coins of value 3,5,11
	int sum =11;
	vector<int> min(sum+1,INF);
	min[0] = 0;
	for (int i=1 ; i<=sum ; i++) {
		for (int j=0 ; j<3 && c[j]<=i ; j++) {
			int m = i-c[j];
			if (min[i] > min[m]+1) {
				min[i] = min[m]+1;
			}
		}
	}
	
	cout << "min coins : " ;
	for (int i=0;i<12;i++) {
		cout << min[i] << "  ";
	}
}		
					
