/*
ID: BigGuava
PROG: A
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
//#define ___SMALL

#pragma warning(disable:4996 4101)


	char v[16][256];

void calc(int dep, char * st)
{
	if (*st==0) return;
	if (isalpha(*st)) {
		v[dep][*st]=1;
		calc(dep+1,st+1);
	} else {
		int i;
		for (i=1;isalpha(st[i]);i++) v[dep][st[i]]=1;
		calc(dep+1,st+i+1);
	}
}

int main()
{
#ifdef LOCAL_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#else
#ifdef ___SMALL
	freopen("A-small.in","r",stdin);
	freopen("A-small.out","w",stdout);
#else
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
#endif

#endif

	int tot,i,j,k,m,n,a,b,c,d;
	char s[1000],t[1000];
	char w[6000][32];

	
	scanf("%d%d%d",&m,&n,&tot);

	for (i=0;i<n;i++) scanf("%s",w[i]);

	for (a=1;a<=tot;a++) {
		printf("Case #%d: ",a);
		scanf("%s",s);

		memset(v,0,sizeof(v));
		calc(0,s);

		c=0;
		for (i=0;i<n;i++) {
			for (j=0;j<m;j++) if (!v[j][w[i][j]]) break;
			if (j==m) c++;
		}


		printf("%d\n",c);
	}

	return 0;
}	

/*

*/