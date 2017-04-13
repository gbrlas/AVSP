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
	

	gets(s);
	sscanf(s,"%d",&tot);
	for (a=1;a<=tot;a++) {
		printf("Case #%d: ",a);
		gets(s);
		sscanf(s,"%d%d",&n,&k);

		d=(1<<n)-1;
		
		if (d==(k&d)) printf("ON\n"); else  printf("OFF\n");
	}

	return 0;
}	

/*

*/