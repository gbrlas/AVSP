#include <cstdio>
#include <iostream>
using namespace std;

const int maxn=10, maxl=1100;

int n, l, task;
bool fnd[maxn];
int a[maxn];
char s[maxl], t[maxl];
int ret;

void dfs(int o)
{
	if (o==n){
		for ( int i=0; i<l; i+=n )
		for ( int j=i; j<i+n; j++ )	
			t[j] = s[i+a[j-i]];	

		int now=0;
		for (int i = 0; i<l; i++ )
		if ( i==0 || t[i-1]!=t[i] ) 
			now++;
		ret = min( ret, now );
		return;
	}

	for (int i=0; i<n; i++)
	if (!fnd[i]){
		fnd[i] = true; a[o] = i;
		dfs(o + 1);
		fnd[i] = false;
	}
}

int main(){
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%d", &task);
	for (int tk=1; tk<=task; tk++){
		scanf("%d", &n);
		scanf("%s", s);
		ret = l = strlen(s);
		memset(fnd, false, sizeof(fnd));
		dfs(0);
		printf("Case #%d: %d\n", tk, ret);
	}
	return 0;
}
