/* BINARY SEARCH : Searching in sorted array
 * 		Complexity : O(log-n)
 */
 
#include <bits/stdc++.h>
#define MAXN 10

int i, n, k, arr[MAXN], rarr[MAXN];

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

int search_rotated(int l, int r, int key) {
	//return index where key is found - array rotated by any number of times
	//else return -1
	
	if (l > r) return -1;
	
	int mid = (l+r)/2;
	
	if (rarr[mid] == key) return mid;
	
	/* if LHS rarr[l] to rarr[mid] is sorted */
	if (rarr[l] <= rarr[mid]) {
		/* if key lies on LHS */
		if (key >= rarr[l] && key < rarr[mid])
			return search_rotated(l, mid-1, key);
			
		else 
			return search_rotated(mid+1, r, key);
	}
	
	/* else RHS rarr[mid] to rarr[r] is sorted */
	
	//if key lies on rhs
	if (key > rarr[mid] && key <= rarr[r]) 
		return search_rotated(mid+1, r, key);
		
	return search_rotated(l, mid-1, key);
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
	
	
	/* rotated array search - (distinct elements) */
	n = 5;
	rarr[0] = 6; rarr[1] = 7; rarr[2] = 9;
	rarr[3] = 1; rarr[4] = 3; 
	k = 9;
	
	i = search_rotated(0, n-1, k);
	printf("\nrotated search\n");
	if (i == -1) printf("not found %d\n", k);
	else printf("found %d at index %d\n", k, i);

	return 0;
}	 
