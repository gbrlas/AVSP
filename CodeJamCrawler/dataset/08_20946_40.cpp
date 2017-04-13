#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
#define MAX 2010

int t,T;
vector < int > like[MAX];
vector < int > unlike[MAX];
int res[15];
int n,m;
bool check()
{
	int i,j;
	for (i=0;i<m;i++)
	{
		bool ok=false;
		for (j=0;j<like[i].size();j++)
			if (res[like[i][j]-1]==1)
				ok=true;
		for (j=0;j<unlike[i].size();j++)
			if (res[unlike[i][j]-1]==0)
				ok=true;
		if (!ok)
			return false;
	}
	return true;
}

bool Run()
{
	int ch,i;
	for (ch=0;ch<1<<n;ch++)
	{
		memset(res,0,sizeof(res));
		int a=ch;i=0;
		while (a>0)
		{
			if (a&1)
				res[i]=1;
			i++;a>>=1;
		}			
		if (check())
			return true;
	}
	return false;
}

int main()
{
	freopen("b-small-attempt0.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (t=1;t<=T;t++)
	{
		int i,j;
		int num,a,b;
		scanf("%d%d",&n,&m);
		for (i=0;i<m;i++)
		{
			like[i].clear();
			unlike[i].clear();
			scanf("%d",&num);
			for (j=0;j<num;j++)
			{
				scanf("%d%d",&a,&b);
				if (b==0)
					unlike[i].push_back(a);
				else
					like[i].push_back(a);
			}
		}
		printf("Case #%d: ",t);
		if (Run())
		{
			for (i=0;i<n;i++)
				printf("%d ",res[i]);
		}
		else
			printf("IMPOSSIBLE");
		printf("\n");
	}

	return 0;
}