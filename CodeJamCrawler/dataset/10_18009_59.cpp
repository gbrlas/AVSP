/*
ID: BigGuava
PROG: B
LANG: C++
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <ctype.h>
#include <set>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

//#define LOCAL_JUDGE
#define ___SMALL

#pragma warning(disable:4996 4101)

int calc(int a, int b, int I, int M)
{

	if (a==b) return 0;
	if (M==0) return 100000000;
	return ((abs(b-a)-1)/M+1)*I;

}

int main()
{
#ifdef LOCAL_JUDGE
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#else
#ifdef ___SMALL
	freopen("B-small.in","r",stdin);
	freopen("B-small.out","w",stdout);
#else
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
#endif

#endif

	int tot,i,j,k,m,n,a,b,c,d;
	int D,I,M;
	int v[200];
	int cost[200][257];

	scanf("%d",&tot);
	for (a=1;a<=tot;a++) {
		printf("Case #%d: ",a);
		scanf("%d%d%d%d",&D,&I,&M,&n);
		
		for (i=1;i<=n;i++) scanf("%d",&v[i]);

		memset(cost,70,sizeof(cost));

		for (i=0;i<=255;i++) cost[0][i]=I;
		cost[0][256]=0;

		for (i=1;i<=n;i++) {
			for (j=0;j<=255;j++) {
				b=200000000;

				for (d=0;d<=255;d++) {
					k=d-M; if (k<0) k=0;
					for (;k<=255 && k<=d+M;k++) if (b>cost[i-1][d]+abs(v[i]-k)+calc(k,j,I,M)) 
						b=cost[i-1][d]+abs(v[i]-k)+calc(k,j,I,M);					
					if (b>cost[i-1][d]+D+calc(d,j,I,M)) 
						b=cost[i-1][d]+D+calc(d,j,I,M);
				}
				
				
				if (b>cost[i-1][256]+D+I) b=cost[i-1][256]+D+I;
				for (k=0;k<=255;k++)
					if (b>cost[i-1][256]+abs(v[i]-k)+calc(k,j,I,M)) b=cost[i-1][256]+abs(v[i]-k)+calc(k,j,I,M);
				cost[i][j]=b;
			}
			cost[i][256]=cost[i-1][256]+D;
		}
		d=200000000;
		for (j=0;j<=256;j++) if (cost[n][j]<d) d=cost[n][j];
		printf("%d\n",d);
	}

	return 0;
}	

/*

*/