#include<stdio.h>
#include<set>
#include<string>
#include<iostream>

using namespace std;

char s[8][11];
string ss[8];
int n,m;
int u[8];
int mm,mt;
set<string> cur[5];

void check()
{
	int i,j;
	for (i=0;i<m;i++)
		cur[i].clear();
	for (i=0;i<n;i++)
	{
		for (j=0;j<ss[i].size();j++)
			cur[u[i]].insert(ss[i].substr(0,j+1));
	}
	int sum=0;
	for (i=0;i<m;i++)
	{
		if (cur[i].size()==0) return;
		sum=sum+cur[i].size();
	}
	if (sum>mm)
	{
		mm=sum;
		mt=0;
	}
	if (sum==mm) mt++;
}

void dfs(int x)
{
	int i;
	if (x==n) check();
	else
	{
		for (i=0;i<m;i++)
		{
			u[x]=i;
			dfs(x+1);
		}
	}
}

int main()
{
	int t,p;
	int i;
	freopen("D-small-attempt2.in","r",stdin);
	freopen("D-small-attempt2.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d%d",&n,&m);
		for (i=0;i<n;i++)
		{
			//scanf("%s",s[i]);
			//ss[i]=toString(s[i]);
			cin>>ss[i];
		}
		mm=0;
		mt=0;
		dfs(0);
		printf("Case #%d: %d %d\n",p,mm+m,mt);
	}
	return 0;
}
