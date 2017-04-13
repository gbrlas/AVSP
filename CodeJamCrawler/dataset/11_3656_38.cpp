#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

#define MP make_pair
#define PB push_back

char g[600][600];
int a[600][600];
int s1[600][600],s2[600][600],s[600][600];
int n,m,d;

bool check(int i,int j,int k){
	int sum=s[i+k][j+k]-s[i][j+k]-s[i+k][j]+s[i][j];
	sum-=a[i][j]+a[i+k-1][j]+a[i][j+k-1]+a[i+k-1][j+k-1];
	int t;
	t=s1[i+k][j+k]-s1[i][j+k]-s1[i+k][j]+s1[i][j];
	t-=a[i][j]*i+a[i+k-1][j]*(i+k-1)+a[i][j+k-1]*i+a[i+k-1][j+k-1]*(i+k-1);
	if (t*2!=sum*(i+i+k-1)) return false;
	t=s2[i+k][j+k]-s2[i][j+k]-s2[i+k][j]+s2[i][j];
	t-=a[i][j]*j+a[i+k-1][j]*j+a[i][j+k-1]*(j+k-1)+a[i+k-1][j+k-1]*(j+k-1);
	if (t*2!=sum*(j+j+k-1)) return false;
	return true;
}

int main(){
	int T,ti=0;
	for (scanf("%d",&T);T--;){
		scanf("%d%d%d",&n,&m,&d);
		for (int i=0;i<n;i++) scanf("%s",g[i]);
		for (int i=0;i<n;i++) for (int j=0;j<m;j++) a[i][j]=g[i][j]-'0';
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		int ans=0;
		for (int i=0;i<n;i++)
		for (int j=0;j<m;j++) s1[i+1][j+1]=s1[i+1][j]+s1[i][j+1]-s1[i][j]+a[i][j]*i,
							  s2[i+1][j+1]=s2[i+1][j]+s2[i][j+1]-s2[i][j]+a[i][j]*j,
							  s[i+1][j+1]=s[i+1][j]+s[i][j+1]-s[i][j]+a[i][j];
		for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
		for (int k=3;k+i<=n&&k+j<=m;k++){
			if (k<ans) continue;
			if (check(i,j,k)) ans=k;
		}
		printf("Case #%d: ",++ti);
		if (ans==0) printf("IMPOSSIBLE\n");
		else printf("%d\n",ans);
	}
    return 0;
}
