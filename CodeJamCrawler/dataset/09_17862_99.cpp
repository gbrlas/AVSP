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
using namespace std;

//#define LOCAL_JUDGE
//#define ___SMALL

#pragma warning(disable:4996 4101)


void patch(int &a, int b)
{
	if (a<0 || a>b) a=b;
}


int main()
{
#ifdef LOCAL_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#else
#ifdef ___SMALL
	freopen("B-small.in","r",stdin);
	freopen("B-small.out","w",stdout);
#else
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
#endif

#endif

	int tot,i,j,k,m,n,a,b,c,d,e,f;
	int v[120][120];
	char out[120][120], in[120][120][4];
	const int p[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
	char res[300];

	scanf("%d",&tot);
	for (a=1;a<=tot;a++) {
		printf("Case #%d:\n",a);
		
		scanf("%d%d",&n,&m);
		memset(v,120,sizeof(v));
		for (i=1;i<=n;i++) for (j=1;j<=m;j++) scanf("%d",&v[i][j]);
		
		memset(out,200,sizeof(out));
		memset(in,0,sizeof(in));
		
		for (i=1;i<=n;i++) for (j=1;j<=m;j++) {
			b=v[i][j]; e=-1;
			for (k=0;k<4;k++) {
				c=i+p[k][0];
				d=j+p[k][1];
				if (v[c][d]<b) {
					b=v[c][d];
					e=k;
				}
			}
			if (b<v[i][j]) {
				out[i][j]=e;
				in[i+p[e][0]][j+p[e][1]][3-e]=1;
			}
		}

		int dep=0;
		memset(v,200,sizeof(v));
		for (i=1;i<=n;i++) for (j=1;j<=m;j++) if (out[i][j]<0) {
			// a sink
			int bfs[120000][2];

			bfs[0][0]=i;
			bfs[0][1]=j;
			v[i][j]=dep;

			e=0; f=1;
			while (e<f) {
				for (k=0;k<4;k++) if (in[bfs[e][0]][bfs[e][1]][k]) {
					c=bfs[e][0]+p[k][0];
					d=bfs[e][1]+p[k][1];
					if (v[c][d]<0) {
						v[c][d]=dep;
						bfs[f][0]=c;
						bfs[f][1]=d;
						f++;
					}
				}
				e++;
			}
			dep++;
		}

		dep='a';
		memset(res,200,sizeof(res));
		for (i=1;i<=n;i++) {
			for (j=1;j<=m;j++) {
				if (res[v[i][j]]<0) {
					res[v[i][j]]=dep;
					dep++;
				}
				if (j!=1) printf(" ");
				printf("%c",res[v[i][j]]);
			}
			printf("\n");
		}		
	}

	return 0;
}	

/*

*/