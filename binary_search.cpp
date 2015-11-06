/* BINARY SEARCH : Searching in sorted array
 * 		Complexity : O(log-n)
 */
 
#include <bits/stdc++.h>
#define MAXN 10

int i, n, k, arr[MAXN];

int bin_srch(int l, int r, int key) {
	//return index of key if found
	//		-1 if key not found
	int mid;
	while (l <= r) {
		mid = (l+r)/2;
		if (arr[mid] == key) return mid;
		else if (arr[mid] < key) l = mid+1;
		else r = mid-1;
	}
	return -1;
}	

int lower_bound(int l, int r, int key) {
	//return index of first element greater than or equal to key
	//			-1 if all emements are less than key
	int mid;
	while (l < r) {
		mid = (l+r)/2;
		if (arr[mid] >= key) r = mid;
		else l = mid+1;
	}
	if (arr[l] >= key) return l;
	else return -1;
}		

int upper_bound(int l, int r, int key) {
	//return index of first element strictly greater than key
	//			-1 if all emements are less than or equal to key
	int mid;
	while (l < r) {
		mid = (l+r)/2;
		if (arr[mid] > key) r = mid;
		else l = mid+1;
	}
	if (arr[l] > key) return l;
	else return -1;
}


 
int main() {
	n = 7;
	arr[0] = 1; arr[1] = 3; arr[2] = 4;
	arr[3] = 6; arr[4] = 8; arr[5] = 9;
	arr[6] = 11;

	k = 4;
	i = bin_srch(0, n-1, k);

	if (i == -1) printf("%d not found\n", k);
	else printf("%d found at index %d\n", k, i);
	
	k = 20;
	i = lower_bound(0, n-1, k);

	if (i == -1) printf("all values are less than %d\n", k);
	else printf("lower bount for %d is at index %d\n", k, i);

	return 0;
}	 
