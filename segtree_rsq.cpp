/*SEGMENT TREE : 
	Space complexity - O(n-log-n)
	Time complexity for - Construction - O(n)
					- Sum Query - O(log-n)
					- Single Update Query - O(log-n)
*/					

#include <cstdio>
#include <cmath>
using namespace std;


long *segtree, *arr, n;
long st, end;				//for range sum query
long indx, dif;			//for update query


/* Initially on function call --
	l = 0  ; r = n-1 ; idx = 0 ;
*/	


//					--CONSTRUCTION--

long constructST_rsq(long l, long r, long idx) {
	if (l == r) {
		segtree[idx] = arr[l];
		return arr[l];
	}
	
	long mid = (l+r)/2;
	segtree[idx] = constructST_rsq(l,mid,((idx<<1) + 1)) + 
			constructST_rsq(mid+1,r,((idx<<1) + 2));
		
	return segtree[idx];
}				


void construct() {								//ignore this if maximum size is known
	long x = (long)(ceil(log2(n))); 
	long max_size = 2*(long)pow(2, x) - 1;
	segtree = new long[max_size];
	
	constructST_rsq(0,n-1,0);					//for range sum query
	
	/*printf("segtree : ");
	for (long i = 0; i<max_size; i++) printf("%ld ",segtree[i]);	
	printf("\n");*/
}	

//					--RANGE SUM QUERY--

long rangeSum(long l, long r, long idx) {
	if (l >= st && r <= end) return segtree[idx];		//fully inside	
	
	if (l>end || r<st) return 0;						//fully outside
	
	long mid = (l+r)/2;									//partial 
	return rangeSum(l, mid, ((idx<<1) + 1)) + 
			rangeSum(mid+1, r, ((idx<<1) + 2));
}	






//					--SINGLE UPDATE : add dif to element at index 'indx'--
void update_rsq(long l, long r, long idx) {
	if (indx < l || indx > r) return;
	
	segtree[idx] += dif;
	
	if (l != r) {
		long mid = (l+r)/2;
		update_rsq(l, mid, ((idx<<1) + 1));
		update_rsq(mid+1, r, ((idx<<1) + 2));
	}
}				
	
	
main() {
	printf("Enter arr size : ");
	scanf("%ld",&n);
	arr = new long[n];
	printf("Enter values :\n");
	for (long i = 0; i<n; i++) scanf("%ld",&arr[i]);
	
	construct(); 
	
	printf("RANGE SUM QUERY\nSum from _ to _ : ");
	scanf("%ld %ld", &st, &end); st--; end--;
	printf("Range sum : %ld\n\n",rangeSum(0,n-1,0));


	printf("UPDATE QUERY\nUpdate arr id _ to _ : ");
	long val;
	scanf("%ld %ld",&indx, &val);
	indx--;
	dif = val - arr[indx];
	arr[indx] = val;
	update_rsq(0,n-1,0);
}	
	

