//ROD CUTTING PROBLEM - DYNAMIC PROGRAMMING - BOTTOM UP APPROACH
#include<iostream>
#include<algorithm>
#include<vector>
#define INF -100000
using namespace std;

int bottom_up_cut_rod(vector<int> &p, vector<int> &r, vector<int> &s, int n, vector<int> &c) {
	r[0] = 0;	c[0] = 0;
	for (int j=1;j<=n;j++) {
		c[j] = 0;
		int q = INF;
		int i;
		for (i=1;i<=j;i++) {
			if (q < (p[i] + r[j-i])) {
				q = p[i] + r[j-i];
				s[j] = i;	
			}		
		}
		if (s[j] < j) {
			c[j] = c[j-s[j]] + 1;
		}	
		r[j] = q;
	}
	return r[n];
}		

main() {
	vector<int> p = {0,1,5,8,9,10,17,17,20,24,30}; // price list of 10 parts p[n] denotes price of rod of size n
	vector<int> r(11), s(11);  //array of maximum rate and size (index - length of rod) 
	vector<int> cut(11);
	int len = 5;
	cout << "maximum sum of rod of len  5 :  " << bottom_up_cut_rod(p,r,s,len,cut) << endl;
	cout << "cuts : " << cut[len] << endl;
	cout << "length of rods : " ;
	while (len > 0) {
		cout << s[len] << " ";
		len = len - s[len];
	}
	cout << endl ;
		
}	
