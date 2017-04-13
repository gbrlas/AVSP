/*
ID: BigGuava
PROG: C
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
	freopen("C-small.in","r",stdin);
	freopen("C-small.out","w",stdout);
#else
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
#endif

#endif

	int tot,i,j,k,m,n,a,b,c,d;

	scanf("%d",&tot);
	for (a=1;a<=tot;a++) {
		printf("Case #%d: ",a);
		scanf("%d",&n);
		d=100000000; k=0; j=0;
		for (i=0;i<n;i++) {
			scanf("%d",&b);
			k^=b;
			j+=b;
			if (b<d) d=b;
		}
		if (k!=0) printf("NO\n"); else printf("%d\n",j-d);
	}

	return 0;
}	

/*

*/