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
	char s[1000];
	int last_pos[2],rec_move[2];

	scanf("%d",&tot);
	for (a=1;a<=tot;a++) {
		printf("Case #%d: ",a);
		last_pos[0]=last_pos[1]=1;
		rec_move[0]=rec_move[1]=0;

		d=0;
		scanf("%d",&m);
		while (m--) {
			scanf("%s%d",s,&b);
			if (s[0]=='B') c=0; else c=1;
			k=abs(b-last_pos[c]);
			if (rec_move[c]>0) {
				if (k>=rec_move[c]) {
					d+=k-rec_move[c] + 1;
					rec_move[1-c]+=k-rec_move[c] + 1;
					rec_move[c]=0;
				
				} else {
					rec_move[c]=0;
					rec_move[1-c]+=1;
					d+=1;
				}
			} else {
				d+=k+1;
				rec_move[1-c]+=k + 1;
			}
			last_pos[c]=b;


		}
		printf("%d\n",d);
	}

	return 0;
}	

/*

*/