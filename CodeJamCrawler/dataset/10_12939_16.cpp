#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define two(n) (1<<(n))

struct Match
{
	int c;
	int v;
	bool operator <(const Match &s) const
	{
		if(c!=s.c)
			return c<s.c;
		else
			return v>s.v;
	}
};

Match mm[5000];


int match[5000];
int price[20][5000];
int n;

int mark[10000];

int mymax(int a,int b)
{
	return a>b?a:b;
}

int cc[1000];
int c=0;

int solve()
{
	int i,j,k;
	memset(mark,0,sizeof(mark));
	

	for(i=0;i<two(n);i++)
	{
		mm[i].v=i;
		mm[i].c=n-match[i];
	}
	sort(mm,mm+two(n));
	
	for(i=two(n)-1;i>=0;i--)
	{
		k=two(n)+mm[i].v;
		j=mm[i].c;
		k=k/2;
		c=0;
		while(k>=1)
		{
			cc[c++]=k;
			k=k/2;
		}
		for(k=c-1;k>=0 && j>0;k--)
		{
			if(mark[cc[k]]==0)
			{
			//	printf("%d\n",cc[k]);
				mark[cc[k]]=1;
			//	j--;
			}
			j--;
			
		}
	}
	int ans=0;
	for(i=0;i<5000;i++)
	{
		if(mark[i]==1)
			ans++;
	}
	return ans;


}


int main()
{
	freopen("B-small-attempt2.in","r",stdin);
	freopen("b_small_2.out","w",stdout);

	int cases;
	int icases=1;
	int j,i;
	
	scanf("%d",&cases);
	while(icases<=cases)
	{
		scanf("%d",&n);
		for(i=0;i<two(n);i++)
			scanf("%d",&match[i]);
		for(i=1;i<=n;i++)
		{
			for(j=0;j<two(n-i);j++)
				scanf("%d",&price[i][j]);
		}

		int ans=solve();

		printf("Case #%d: %d\n",icases++,ans);

	}
	return 0;
}