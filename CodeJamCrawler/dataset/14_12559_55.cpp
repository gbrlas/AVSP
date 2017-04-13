#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>

using namespace std;

#define ll long long
#define inf 2000000000
#define mod 1000000007
#define vv vector<int>
#define pp pair<int,int>
#define vvp vector<pp>
#define pb push_back
#define st set<int>
#define mp map<string,int>
#define pr(cn,x) ((cn).find(x)!=(cn).end()) 
#define tr(cn,it) for(typeof((cn).begin()) it=(cn).begin();it!=(cn).end();it++)

int main()
{
	int tc,r1,r2,i,j,k,c,ans;
	scanf("%d",&tc);
	for(k=1;k<=tc;k++)
	{
		int ar1[5][5],ar2[5][5];
		scanf("%d",&r1);
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			scanf("%d",&ar1[i][j]);
		}
		scanf("%d",&r2);
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			scanf("%d",&ar2[i][j]);
		}
		c=0;
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(ar1[r1-1][i]==ar2[r2-1][j])
				{
					c++; ans=ar1[r1-1][i];
					break;
				}
			}
		}
		if(!c)
		printf("Case #%d: Volunteer cheated!\n",k);
		else if(c>1)
		printf("Case #%d: Bad magician!\n",k);
		else
		printf("Case #%d: %d\n",k,ans);
	}
	return 0;
}
