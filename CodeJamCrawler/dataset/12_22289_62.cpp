#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 10010;

int d[maxn], l[maxn], a[maxn], D;
int n, task;

int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d", &task);
	for (int cs=1; cs<=task; cs++){
		scanf("%d", &n);
		for (int i=0; i<n; i++)
			scanf("%d%d", d+i, l+i);
		scanf("%d", &D);

		memset(a, -1, sizeof(a));
		a[0] = d[0]<<1;
		if ( a[0] >= D ){
			printf("Case #%d: YES\n", cs);
			continue;
		}

		bool fnsh = false;
		for (int i=0,x=0,j=1; i<n; i++)
		if (a[i] > 0){
			for (;j < n && a[i] >= d[j]; j++){
				if (d[j] - d[i] > l[j])
					a[j] = d[j] + l[j];else 
					a[j] = d[j]*2 - d[i];
				if (a[j] >= D){
					fnsh = true;
					break;
				}
			}
			if ( fnsh ) break;
		}
		if ( fnsh )
			printf("Case #%d: YES\n", cs);
		else 
			printf("Case #%d: NO\n", cs);
	}
	return 0;
}
