//#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cctype>
#define N 110

using namespace std;

bool a[N][N],b[N][N];
int i,j,k,l,o,p,n,m;
int i_0,i_1,j_0,j_1;

int main(){
	int T=0;
	for (scanf("%d",&o);o--;){
		scanf("%d",&n);
		memset(a,false,sizeof(a));
		for (;n--;){
			scanf("%d%d%d%d",&i_0,&j_0,&i_1,&j_1);
			for (i=i_0;i<=i_1;i++)
			for (j=j_0;j<=j_1;j++) a[i][j]=true;
		}
		int z=0;
		for (;;){
			for (i=0;i<N;i++){
				for (j=0;j<N;j++) if (a[i][j]) break;
				if (a[i][j]) break;
			}
			if (i==N) break;
			z++;
			memcpy(b,a,sizeof(a));
			for (i=0;i<N;i++)
			for (j=0;j<N;j++){
				if (i==0||j==0) a[i][j]=false;
				else {
					if (b[i][j]){
						if (b[i-1][j]==0&&b[i][j-1]==0) a[i][j]=false;
						else a[i][j]=true;
					}
					else {
						if (b[i-1][j]==1&&b[i][j-1]==1) a[i][j]=true;
						else a[i][j]=false;
					}
				}
			}
		}
		printf("Case #%d: %d\n",++T,z);
	}
	return 0;
}
