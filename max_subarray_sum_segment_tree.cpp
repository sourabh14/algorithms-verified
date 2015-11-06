//Maximum subarray sum using segment tree
//with modification
#include <cstdio>
#include <algorithm>

using namespace std;

struct node {
	long sum, pref, suff, msa;
};
typedef struct node NODE;

int ch;
long i,n,m,x,y, arr[50004];
long indx, val; 						//for update
NODE segtree[200003], ans;
	

//										Construction
inline NODE join(NODE a, NODE b) {
	NODE ret;
	ret.sum = a.sum + b.sum;
	ret.pref = max(a.pref, a.sum + b.pref);
	ret.suff = max(b.suff, a.suff + b.sum); 
	ret.msa = max(max(a.msa, b.msa),(a.suff+b.pref));
	return ret;
}	 

NODE constructST(long l, long r, long idx) {
	if (l == r) {
		segtree[idx].sum = arr[l];
		segtree[idx].pref = arr[l];
		segtree[idx].suff = arr[l];
		segtree[idx].msa = arr[l];
		return segtree[idx];
	}
	
	long mid = (l+r)/2;
	NODE le = constructST(l,mid,((idx<<1) + 1));
	NODE ri = constructST(mid+1,r,((idx<<1) + 2));
	segtree[idx] = join(le, ri);
		
	return segtree[idx];
}		



//										Query

NODE rangeMsa(long l, long r, long idx, long a, long b) {
	if (l == a && r == b) {
		return segtree[idx];	
	}	
	
	long mid = (l+r)/2;
	if (b <= mid) {		//go to left sub tree
		return rangeMsa(l, mid, ((idx<<1) + 1), a, b);
	}
	
	if (a > mid) {		//go to right sub tree
		return rangeMsa(mid+1, r, ((idx<<1) + 2), a, b);
	}		
	
	NODE le = rangeMsa(l, mid, ((idx<<1) + 1), a, mid);
	NODE ri = rangeMsa(mid+1, r, ((idx<<1) + 2), mid+1, b);
	return join(le,ri);
}		

void update(long l, long r, long idx) {		//go upto leaf of tree and modify and in return path join le and ri
	if (l == r && l == indx) {
		segtree[idx].sum = val;
		segtree[idx].pref = val;
		segtree[idx].suff = val;
		segtree[idx].msa = val;
		return;
	}	
	
	long mid = (l+r)/2;
	if (indx <= mid) {		//go to left sub tree
		update(l, mid, ((idx<<1) + 1));
	}
	else {					//go to right sub tree
		update(mid+1, r, ((idx<<1) + 2));
	}		
	
	segtree[idx] = join(segtree[(idx<<1) + 1], segtree[(idx<<1) + 2]);
}	
	

int main() {
	scanf("%ld", &n);
	for (i=0; i<n; i++) scanf("%ld",&arr[i]);
	
	constructST(0,n-1,0);
	
	scanf("%ld",&m);
	while (m--) {
		scanf("%d",&ch);
		if (ch == 1) {
			scanf("%ld %ld",&x,&y); 
			x--; y--;
			ans = rangeMsa(0,n-1,0,x,y);
			printf("%ld\n",ans.msa);
		}
		else {
			scanf("%ld %ld",&indx, &val);
			indx--;
			update(0,n-1,0);
		}
	}	
	return 0;
}		
