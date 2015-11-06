//Convex hull - Graham scan algo
#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAXN 100005
#define MAXCOR 10004
using namespace std;

struct point {
	int x, y, id;
} cor[MAXN], cnvx_hull[MAXN], p, q, r;							//chn denotes number of hull points
	
int t, n, i, min_y, min_x, min_i, chn, o_cnt;

void input();
void print_cor();
void print_hull();
bool all_coolinear();
int cmp(struct point a, struct point b);
inline int ccw(struct point A, struct point B, struct point C);
void graham_scan();
void perimeter();

int main() {
	scanf("%d",&t);
	while (t--) {
		input();
		if (n == 1) {
			chn = 1;
			cnvx_hull[0] = cor[0];
		}
		else {
			//shift origin
			min_x = cor[min_i].x; 
			for (i=0; i<n; i++) {
				cor[i].x -= min_x;
				cor[i].y -= min_y;
			}	
			
			//shift all (0,0) in beginning
			for (i=0,o_cnt=0; i<n; i++) {
				if ((cor[i].x == 0) && (cor[i].y == 0)) {
					swap(cor[o_cnt], cor[i]);
					o_cnt++;
				}
			}		 
			sort(cor+o_cnt, cor+n, cmp);
			
			//check all points are coolinear
			if (all_coolinear()) {	
				chn = 2;
				cnvx_hull[0] = cor[0];
				cnvx_hull[1] = cor[n-1];
			}	 
			else {
				graham_scan();
			}		
		}
		
		perimeter();
		print_hull();
	
	}
	return 0;
}			


void input() {
	scanf("%d", &n);
	min_y = MAXCOR;
	for (i=0; i<n; i++) {
		scanf("%d %d",&cor[i].x, &cor[i].y);
		cor[i].id = i+1;
		if (min_y > cor[i].y) {							//find the bottomost point 
			min_y = cor[i].y; 
			min_i = i;
		}
		if ((min_y == cor[i].y) && (cor[min_i].x > cor[i].x)) {
			min_i = i;
		} 
	}
}		

void print_cor() {
	printf("\ncoordinates\n");
	for (i=0; i<n; i++) {
		printf("id %d-> %d %d\n",cor[i].id, cor[i].x, cor[i].y);
	}
}	

void print_hull() {
	for (i=0; i<chn; i++) {
		printf("%d ", cnvx_hull[i].id);
	}
	printf("\n");
}	

bool all_coolinear() {
	for (i=0; i<(n-2); i++) {
		if (ccw(cor[i], cor[i+1], cor[i+2]) != 0) break;
	}	
	if (i == (n-2)) return true;
	return false;
}	

//comparison for sort : make sure (0,0) doesn't comes
int cmp(struct point a, struct point b) {
	if ((a.x == 0) && (b.x == 0)) return (a.y < b.y ? 1 : 0);
	if ((a.x == 0) || (b.x == 0)) return (a.x > b.x ? 1:0);	
	
	float m1 = float(a.y)/a.x;
	float m2 = float(b.y)/b.x;
	if (m1 == m2) return (a.x < b.x ? 1 : 0);
	if ((m1 == 0) || (m2 == 0)) return (m1 == 0 ? 1 : 0);	
	return (m1*m2 < 0 ? (m1 > m2 ? 1:0) : (m1 < m2 ? 1 : 0));
}

//cross product of vector AB and BC
inline int ccw(struct point A, struct point B, struct point C) {	
	int x1, x2, y1, y2;
	x1 = B.x - A.x; x2 = C.x - B.x;
	y1 = B.y - A.y; y2 = C.y - B.y;
	return (x1*y2 - y1*x2);
}	

void graham_scan() {
	chn = 1;
	cnvx_hull[0] = cor[0];			
	i = o_cnt;
	cnvx_hull[1] = cor[i];			//push cor[1]
	
	for (i++; i<n; i++) {
		if ((cor[i].x == cor[i-1].x) && (cor[i].y == cor[i-1].y)) continue;
		q = cnvx_hull[chn];	
		p = cnvx_hull[chn-1];	
		
		//while new point causes concave corner or coolinear
		while (ccw(p, q, cor[i]) <= 0) {		 
			chn--;
			q = cnvx_hull[chn];	
			p = cnvx_hull[chn-1];
		}	
		cnvx_hull[++chn] = cor[i];
	}	
	chn++;
}	

void perimeter() {
	float peri=0;
	int x1, x2, y1, y2;
	for (i=0; i<chn-1; i++) {
		x1 = cnvx_hull[i].x; y1 = cnvx_hull[i].y;
		x2 = cnvx_hull[i+1].x; y2 = cnvx_hull[i+1].y;
		peri += sqrt( (y2-y1)*(y2-y1) + (x2-x1)*(x2-x1) );
	}
	x1 = cnvx_hull[i].x; y1 = cnvx_hull[i].y;
	x2 = cnvx_hull[0].x; y2 = cnvx_hull[0].y;
	peri += sqrt( (y2-y1)*(y2-y1) + (x2-x1)*(x2-x1) );
	
	printf("%.2f\n",peri);
}
