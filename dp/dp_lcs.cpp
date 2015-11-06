/*LONGEST COMMON SUBSEQUENCE : DYNAMIC PROGRAMMING
complexity : O(n^2)
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXL 1003
using namespace std;

int k, l1, l2, i1, i2, dp[MAXL][MAXL];
char str1[MAXL], str2[MAXL];

int lcs_rec(int i1, int i2) {			//recursive solution - O(2^n)
	if (i1 == 0 || i2 == 0) 
		return 0;
	
	if (str1[i1] == str2[i2]) 
		return 1+lcs_rec(i1-1,i2-1);
		
	else 
		return max(lcs_rec(i1,i2-1),lcs_rec(i1-1,i2));
}

int lcs() {			
	l1 = strlen(str1);
	l2 = strlen(str2);
	
	for (i1=0; i1<=max(l1,l2); i1++) dp[i1][0] = dp[0][i1] = 0;
	
	for (i1=1; i1<=l1 ; i1++) {
		for (i2=1; i2<=l2; i2++) {
			if (str1[i1-1] == str2[i2-1]) dp[i1][i2] = 1 + dp[i1-1][i2-1];
			else dp[i1][i2] = max(dp[i1][i2-1] , dp[i1-1][i2]);
		}
	}
	
	return dp[l1][l2];
}			

int main() {
	scanf("%s %s", str1, str2);
	printf("%d\n", lcs());
	return 0;
}	
