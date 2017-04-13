#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int limit;
int a[1010];
int n;

int main(){
	int test=0;
	scanf("%d", &test);
	for (int T=1; T<=test; ++T){
		printf("Case #%d: ", T);
		scanf("%d%d", &n,&limit);
		for (int i=0; i<n; ++i)
			scanf("%d", a+i);
		sort(a,a+n);
		int ans=0, j=n-1;
		for (int i=0; i<n; ++i){
			if (a[i]==0) continue;
			while (j>i && a[i]+a[j]>limit) --j;
			if (j>i){
				a[j]=0; --j;
			}
			++ans;
		}
		printf("%d\n", ans);
	}
}
