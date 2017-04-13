#include <cstdio>
#include <iostream>
using namespace std;

int task, n, m, A;

int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d", &task);
	for (int tk=1; tk<=task; tk++){
		scanf("%d%d%d", &n, &m, &A);
		bool fnsh = false;
		for (int x1=0; x1<=n; x1++){
		for (int y2=0; y2<=m; y2++){
		for (int x2=0; x2<=n; x2++){
			if ( fnsh ) break;
			if ( x2==0 ){
				if ( x1*y2==A ){
					int y1 = 0;
					fnsh = true;
					printf("Case #%d: 0 0 %d %d %d %d\n", tk, x1, y1, x2, y2);
				}
				continue;
			}
			int y1 = x1*y2-A;
			if ( y1%x2!=0 ) continue;
			y1 = y1/x2;
			if ( 0<=y1 && y1<=m ){
				fnsh = true;
				printf("Case #%d: 0 0 %d %d %d %d\n", tk, x1, y1, x2, y2);
			}
		}
		if (fnsh) break;
		}
		if (fnsh) break;
		}
		if (!fnsh) printf("Case #%d: IMPOSSIBLE\n", tk);
	}
	return 0;
}
