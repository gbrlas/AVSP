#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int a[1100], n, tt, ttt=0;

int main(){
	freopen("C-large.in","r",stdin);
	freopen("a.out","w",stdout);
	for (scanf("%d", &tt); tt--;){
		scanf("%d", &n);
		int s=0, all=0;
		for (int i=0; i<n; i++){
			scanf("%d", a+i);
			s ^= a[i];
			all += a[i];
		}
		sort( a, a+n );
		if ( s==0 )
			printf("Case #%d: %d\n", ++ttt, all-a[0]);else
			printf("Case #%d: NO\n", ++ttt);
	}
	return 0;
}
