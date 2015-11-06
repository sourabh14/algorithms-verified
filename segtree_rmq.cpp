/*SEGMENT TREE : 
	Time complexity for - Construction - O(n)
					- Range min Query - O(log-n)
					- Update Query - O(log-n)
*/					

#include<cstdio>
#include<algorithm>
#include<cmath>
#define INF 1000000
using namespace std;


long *segtree, *arr, n;
long st, end;				//for range min query
long indx, val;			//for update query


/* Initially on function call --
	l = 0  ; r = n-1 ; idx = 0 ;
*/	


//					--CONSTRUCTION--
			

long constructST_rmq(long l, long r, long idx) {
	if (l == r) {
		segtree[idx] = arr[l];
		return arr[l];
	}
	
	long mid = (l+r)/2;
	segtree[idx] = min(constructST_rmq(l,mid,((idx<<1) + 1)), constructST_rmq(mid+1,r,((idx<<1) + 2)));
		
	return segtree[idx];
}	

void construct() {
	long x = (long)(ceil(log2(n))); 
	long max_size = 2*(long)pow(2, x) - 1;
	segtree = new long[max_size];
	
	constructST_rmq(0,n-1,0);				//for range min query
	/*
	printf("segtree : ");
	for (long i = 0; i<max_size; i++) printf("%ld ",segtree[i]);	
	printf("\n");
	*/
}	

//					--RANGE MIN QUERY--

long rangeMin(long l, long r, long idx) {

	if (l >= st && r <= end) return segtree[idx];
	
	if (l>end || r<st) return INF;
	
	long mid = (l+r)/2;
	return min(rangeMin(l, mid, ((idx<<1) + 1)), rangeMin(mid+1, r, ((idx<<1) + 2)));
}	






//					--UPDATE--
void update_rmq(long l, long r, long idx) {
	if (indx < l || indx > r) return;
	
	
	segtree[idx] = min(segtree[idx],val);
	
	if (l != r) {
		long mid = (l+r)/2;
		update_rmq(l, mid, ((idx<<1) + 1));
		update_rmq(mid+1, r, ((idx<<1) + 2));
	}
}				
	
	
main() {
	printf("Enter arr size : ");
	scanf("%ld",&n);
	arr = new long[n];
	printf("Enter values :\n");
	for (long i = 0; i<n; i++) scanf("%ld",&arr[i]);
	
	construct(); 
	
	printf("RANGE MIN QUERY\nSum from _ to _ : ");
	scanf("%ld %ld", &st, &end); st--; end--;
	printf("Range min : %ld\n\n",rangeMin(0,n-1,0));


	printf("UPDATE QUERY\nUpdate arr id _ to _ : ");
	scanf("%ld %ld",&indx, &val);
	indx--;
	arr[indx] = val;
	update_rmq(0,n-1,0);
}	
	

