#include <cstdio>
#include <algorithm>
using namespace std;
double all[2][1005];
int main() {
	int t, n;
	scanf("%d", &t);
	for(int cn=1; cn<=t; ++cn) {
		scanf("%d", &n);
		for(int i=0; i<n; ++i) scanf("%lf", &all[0][i]);
		for(int i=0; i<n; ++i) scanf("%lf", &all[1][i]);
		sort(all[0], all[0]+n);
		sort(all[1], all[1]+n);
		int ans0=0, ans1=0;
		for(int i0=n-1, i1=n-1; i0>=0&&i1>=0; --i0) {
			while( i1>=0&&all[1][i1]>all[0][i0] ) --i1;
			if( i1>=0 && all[1][i1]<all[0][i0] ) --i1, ++ans0;
		}
		for(int i0=n-1, i1=n-1; i0>=0&&i1>=0; --i1) {
			while( i0>=0&&all[0][i0]>all[1][i1] ) --i0;
			if( i0>=0 && all[0][i0]<all[1][i1] ) --i0, ++ans1;
		}
		printf("Case #%d: %d %d\n", cn, ans0, n-ans1);
	}
}