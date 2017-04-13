#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 2000;

int task, n, l[maxn], p[maxn], a[maxn];

bool comp(int i, int j){
	int S1 = p[j]*l[i]+l[j];
	int S2 = p[i]*l[j]+l[i];
	return ( S1<S2 || S1==S2 && i<j );
}

int main(){
	freopen("A-small-attempt1.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d", &task);
	for (int cs=1; cs<=task; cs++){
		scanf("%d", &n);
		for (int i=0; i<n; i++){
			scanf("%d", l+i);
		}
		for (int i=0; i<n; i++){
			scanf("%d", p+i);
			a[i] = i;
		}

		sort( a, a+n, comp );

		printf("Case #%d:", cs);
		for (int i=0; i<n; i++)
			printf(" %d", a[i]);
		printf("\n");
	}
	return 0;
}
