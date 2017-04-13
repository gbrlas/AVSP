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
#define ___SMALL

#pragma warning(disable:4996 4101)



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

	int tot,i,j,m,n,a;
	__int64 v[4000];
	int step[2000];
	int next[2000];
	__int64 incom[2000];
	__int64 r,k,b,c,d;

	scanf("%d",&tot);
	for (a=1;a<=tot;a++) {
		printf("Case #%d: ",a);
		scanf("%I64d%I64d%d",&r,&k,&n);
		for (i=0;i<n;i++) {
			scanf("%I64d",&v[i]);
			v[i+n]=v[i];
		}

		memset(step,200,sizeof(step));

		b=0;
		step[0]=1;
		next[0]=0;
		incom[0]=0;
		i=1;
		for (;;) {
			c=0;
			for (j=next[i-1];j<n+next[i-1];j++) {
				if (c+v[j]>k) break;
				c+=v[j];
			}
			incom[i]=c+incom[i-1];
			next[i]=j%n;
			if (step[j%n]>=0) {
				b=step[j%n]-1;
				c=i-b;
				if (r>i)
					d=(incom[i]-incom[b])*((r-b)/c)+incom[(r-b)%c+b];
				else 
					d=incom[r];
				printf("%I64d\n",d);
				break;
				
			}
			i++;
			step[j%n]=i;
		}


	}


	return 0;
}	

/*

*/