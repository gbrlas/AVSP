#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	for (int iT=1; iT<=T; ++iT) {
		int n,x,ans,s[10000];
		bool v[10000]={};
		scanf("%d%d",&n,&x);
		ans=n;
		for (int i=0; i<n; ++i) {
			scanf("%d",&s[i]);
		}
		sort(s, s+n);
		for (int i=0; i<n; ++i) {
			if (v[i]) {
				continue;
			}
			int t=x-s[i];
			for (int j=n-1; j>i; --j) {
				if (v[j]) {
					continue;
				}
				if (s[j]<=t) {
					v[j]=1;
					--ans;
					break;
				}
			}
		}
		printf("Case #%d: %d\n",iT,ans);
	}
    return 0;
}