//#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cctype>

using namespace std;

int a[2048];
int b[2048];
int f[2048][12];
int i,j,k,l,o,p,n,m,N;

int main(){
	int T=0;
	for (scanf("%d",&o);o--;){
		scanf("%d",&n);
		N=(1<<n);
		for (i=N;i<N*2;i++){
			scanf("%d",&a[i]);
			for (j=0;j<=a[i];j++) f[i][j]=0;
			for (j=a[i]+1;j<12;j++) f[i][j]=-1;
		}
		j=N;
		for (i=n-1;i>=0;i--){
			for (k=j/2;k<j;k++) scanf("%d",&b[k]);
			j/=2;
		}
		for (i=N-1;i>0;i--){
			f[i][11]=-1;
			for (j=10;j>=0;j--){
				f[i][j]=-1;
				if (f[i][j+1]!=-1) f[i][j]=f[i][j+1];
				if (f[i*2][j]!=-1&&f[i*2+1][j]!=-1) if (f[i][j]==-1||f[i][j]>b[i]+f[i*2][j]+f[i*2+1][j]) f[i][j]=f[i*2][j]+f[i*2+1][j]+b[i];
				if (f[i*2][j+1]!=-1&&f[i*2+1][j+1]!=-1) if (f[i][j]==-1||f[i][j]>f[i*2][j+1]+f[i*2+1][j+1]) f[i][j]=f[i*2][j+1]+f[i*2+1][j+1];
			}
		}
		int ans=-1;
		for (i=0;i<12;i++){
			if (f[1][i]==-1) continue;
			if (ans==-1||ans>f[1][i]) ans=f[1][i];
		}
		printf("Case #%d: %d\n",++T,ans);
	}
	return 0;
}
