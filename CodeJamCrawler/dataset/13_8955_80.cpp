/* fAnSKyer */
/* 11-02-2010 */
/* replace DT lattice*/
/* Useage: */
/* Directory E:\FeatureProcessor */


#pragma warning (disable:4786) 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int s[200][200],st[200][200];
int f[200];
int g[200];
int n,m,t;
int check(int x)
{
	char c[50];
	sprintf(c,"%d",x);
	int l=strlen(c);
	for (int i=0;i<l;i++)
	{
		if (c[i]!=c[l-i-1]) return 0;
	}
	return 1;
}
int main(int argc,char* argv[])
{
	char name[500],ch[500];	
	int i,j,v,cnt=0,temp;
	int cas, ans=1;
	/* read the dictionary */
	freopen("C-small-attempt0.in","r",stdin); //B-small-attempt0.in
	freopen("output.txt","w",stdout);
	scanf("%d",&cas);
	for(t=0;t<cas;t++)
	{
		//memset(s,0,sizeof(s));
		scanf("%d %d",&n,&m);
		printf("Case #%d: ",t+1);
		ans=0;
		for (i=n;i<=m;i++)
		{
			v = (double)sqrt((double)i);
			if (v*v!=i) continue;
			if (check(i)==1 && check(v)==1) ans++;
		}
			
		printf("%d\n",ans);
	}
}
