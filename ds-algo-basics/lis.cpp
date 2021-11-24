#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> A = {50, 3, 10, 7, 40, 80};
	int n = A.size();
	vector<int> lis(n, 1);
	int prev[n], lisprint[n];

	int i, j, maxlis, maxindx;

	for (i=0; i<n; i++)
		prev[i] = -1;

	for (i=1; i<n; i++) {
		for (j=i-1; j>=0; j--) {
			if (A[i] > A[j]) {
				if (lis[i] < (lis[j] + 1)) {
					lis[i] = (lis[j] + 1);
					prev[i] = j;
				}
			}
		}
	}

	maxlis = lis[0];
	maxindx = 0;
	for (i=1; i<n; i++) {
		if (maxlis < lis[i]) {
			maxlis = lis[i];
			maxindx = i;
		}
	}

	printf("Size of lis: %d\nLIS: ", maxlis);

	for (i=maxindx, j=maxlis-1; prev[i]!=-1; i=prev[i], j--) {
		lisprint[j] = A[i];
	}
	lisprint[j] = A[i];

	for (i=0; i<maxlis; i++) {
		printf("%d ", lisprint[i]);
	}
	printf("\n");


	return 0;
}