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
#define ___SMALL

#pragma warning(disable:4996 4101)


void patch(int &a, int b)
{
	if (a<0 || a>b) a=b;
}

int cmp_int(const void *a, const void *b)
{
	return *(int *)a-*(int *)b;
}

int main()
{
#ifdef LOCAL_JUDGE
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
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
	char s[100][100],t[100][100];
	int p[4][2]={{1,0},{0,1},{-1,1},{1,1}};
	bool bflag, rflag;
	
	scanf("%d",&tot);
	for (a=1;a<=tot;a++) {
		printf("Case #%d: ",a);
		
		memset(s,'.',sizeof(s));
		memset(t,'.',sizeof(t));

		scanf("%d%d",&n,&k);
		for (i=1;i<=n;i++) scanf("%s",&s[i][1]);
		for (i=n;i>=1;i--) for (j=n,b=n;j>=1;j--) if (isalpha(s[i][j])) {
			t[b][n+1-i]=s[i][j];
			b--;
		}

		bflag=rflag=false;
		for (i=1;i<=n;i++) for (j=1;j<=n;j++) if (isalpha(t[i][j])) for (b=0;b<4;b++) {
			c=i; d=j;
			for (m=1;;m++) {
				c+=p[b][0];
				d+=p[b][1];
				if (t[c][d]!=t[i][j]) break;
			}
			if (m>=k) if (t[i][j]=='R') rflag=true; else if (t[i][j]=='B') bflag=true;
		}

		if (rflag && bflag) printf("Both\n");
		else if (!rflag && bflag) printf("Blue\n");
		else if (rflag && !bflag) printf("Red\n");
		else if (!rflag && !bflag) printf("Neither\n");
	}

	return 0;
}	


/*

*/