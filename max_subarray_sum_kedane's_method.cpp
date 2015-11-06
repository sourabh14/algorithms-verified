//Maximum subarray sum using kedane's method
//complexity - O(n)
#include<cstdio>
#define SIZE 15007

long i,n,m,x,y, arr[SIZE];

int main() {
	scanf("%ld",&n);
	for (i=0;i<n;i++) scanf("%ld",&arr[i]);
	scanf("%ld",&m);
	while (m--) {
		scanf("%ld %ld",&x,&y); 
		x--; y--;
		
		local_max = arr[x]; global_max = arr[x];
		for (i=x+1; i<=y; i++) {
			if (local_max+arr[i] > arr[i]) local_max = local_max + arr[i];
			else local_max = arr[i];	
			
			if (global_max < local_max) global_max = local_max;
		}
		printf("%lld\n",global_max);
		
	}
	return 0;
}		
