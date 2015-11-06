/* LONGEST INCREASING SUBSEQUENCE : DYNAMIC PROGRAMMING
	complexity : O(n^2)
length of LIS for { 10, 22, 9, 33, 21, 50, 41, 60, 80 } is 6 and LIS is {10, 22, 33, 50, 60, 80}.
*/

#include<cstdio>
#define MAXN 1000
using namespace std;

long n, arr[MAXN], dp[MAXN], mx;

long lis() {
	for (long i=0;i<n;i++) { dp[i] = 1; }	//dp[i] represents length of LIS with arr[i] as last element

	for (long i=0;i<n;i++) {
		for (long j=0;j<i;j++) {
			if ((arr[i] > arr[j]) && (dp[i] < dp[j] + 1 )) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	mx = dp[n-1];
	//return max dp
	for (long i=n-2;i>=0;i--) { if (dp[i] > mx) mx = dp[i]; }
	
	return mx;
}				

main() {
	printf("Enter no of numbers : ");
	scanf("%ld",&n);
	printf("Enter array elements : \n");
	for (long i=0;i<n;i++) { scanf("%ld",&arr[i]); }
	printf("Longest increasing subsequence : %ld\n",lis());
	
	printf("\n---------\ndp : ");
	for (long i=0;i<n;i++) { printf("%ld  ",dp[i]); }
	printf("\n");
}	
	
