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
	freopen("B-small.in","r",stdin);
	freopen("B-small.out","w",stdout);
#else
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
#endif

#endif

	int tot,i,j,k,m,n,a,b,c,d;
	char s[1000],t[1000],r[1000];
	map<string,string> comb;
	char oppo[256][256];
	

	
	scanf("%d",&tot);
	for (a=1;a<=tot;a++) {
		printf("Case #%d: ",a);
		comb.clear();
		memset(oppo,0,sizeof(oppo));
		
		scanf("%d",&c);
		while (c--) {
			scanf("%s",s);
			t[0]=s[2]; t[1]=0;
			s[2]=0;
			comb[string(s)]=string(t);
			t[5]=s[0]; s[0]=s[1];s[1]=t[5];
			comb[string(s)]=string(t);
		}

		scanf("%d",&c);
		while (c--) {
			scanf("%s",s);
			oppo[s[0]][s[1]]=1;
			oppo[s[1]][s[0]]=1;
		}

		scanf("%d%s",&c,r);
		i=0;
		for (d=0;d<c;d++) {
			s[i]=r[d];
			if (i>=1) {
				t[0]=s[i-1];
				t[1]=s[i];
				t[2]=0;
				if (comb.find(string(t))!=comb.end()) {
					s[i-1] = comb[string(t)].c_str()[0];
					goto bz_1;
				}
				for (j=i-1;j>=0;j--) if (oppo[s[j]][s[i]]) {
					i=0;
					goto bz_1;
				}
			}
			i++;
bz_1:
			i=i;
		}

		printf("[");
		for (j=0;j<i;j++) {
			if (j>0) printf(", ");
			printf("%c",s[j]);
		}
		printf("]\n");
	}

	return 0;
}	

/*

*/