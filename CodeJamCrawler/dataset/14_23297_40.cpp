#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int a[10010], b[10010];
map<int,int> pp;
int n;
int pos[10010];

int main(){
	int test=0;
	scanf("%d", &test);
	for (int T=1; T<=test; ++T){
		printf("Case #%d: ", T);
		scanf("%d", &n);
		pp.clear();
		for (int i=0; i<n; ++i){
			scanf("%d", a+i); b[i]=a[i];
		}
		sort(b,b+n);
		for (int i=0; i<n; ++i)
			pp[b[i]]=i;
		for (int i=0; i<n; ++i){
			//printf("%d %d\n", pp[a[i]], a[i]);
			pos[pp[a[i]]]=i;
			a[i]=pp[a[i]];
		}
		int up=0, right=n-1, ans=0;
		for (int i=0; i<n; ++i){
			int t=pos[i];
			/*for (int i=0; i<n; ++i) printf("%d ", a[i]);
			printf("\n");*/
			if (t-up<right-t){
				for (int j=t-1; j>=up; --j){
					int tt=a[j]; a[j]=a[j+1]; a[j+1]=tt;
					++pos[a[j+1]];
				}
				ans+=t-up; ++up;
			} else {
				for (int j=t; j<right; ++j){
					int tt=a[j]; a[j]=a[j+1]; a[j+1]=tt;
					--pos[a[j]];
				}
				ans+=right-t; --right;
			}
		}
		printf("%d\n", ans);
	}
}
