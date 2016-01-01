/* Given unsorted array - find the kth smallest element 
 * -Based on quick sort algo
 * Complexity :
 *  	Time : O(n)
 * 		Space : O(1)
 * 
 * To find median k = n/2
 */
 
#include <bits/stdc++.h>
#define MAXN 10
using namespace std;

int arr[MAXN], n, i;

int partition(int l, int r) {
	if (l == r) return l;
	
	int x = arr[r], i = l-1, j;
	for (j=l; j<r; j++) {
		if (arr[j] <= x) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[r]);
	return i+1;
}			

int findkth(int k) {
	/* modifies arr such that kth smallest element will be in arr[k-1]*/
	
	int pivot, l=0, r=n-1;
	while (1) {
		pivot = partition(l, r);
	
		if (pivot == (k-1)) break;
		else if (pivot < (k-1)) l = pivot+1;
		else r = pivot-1;	
	}	
	
	return arr[k-1];
}	

int main() {
	n = 6;
	arr[0] = 1; arr[1] = 7; arr[2] = 3;
	arr[3] = 2; arr[4] = 8; arr[5] = 4;
	
	int k = 6;
	cout << k << "th smallest element : " << findkth(k) << endl;
	return 0;
}	
