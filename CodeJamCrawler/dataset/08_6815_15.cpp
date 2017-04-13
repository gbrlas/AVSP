#include	<cstdio>
#include	<iostream>
#include	<vector>
#include	<string>
#include	<conio.h>
#include	<windows.h>
#include	<assert.h>
#include	<algorithm>

using namespace std;

int nodetype[10001];
int change[10001];
int leaf[10001];
int n,n2;
int ans;
int m,v,x,y,z;

#define INF 10000000

int saiki(int num,int req)
{
	if(num>=(m-1)/2+1)
	{
		if(leaf[num]==req)return 0;
		else			return INF;
	}

	int rtn=INF;

	int a1=saiki(num*2,1);
	int a0=saiki(num*2,0);
	int b1=saiki(num*2+1,1);
	int b0=saiki(num*2+1,0);

	if(nodetype[num]==1 && req==1)
	{
		rtn=min(rtn,a1+b1);
	}
	if(nodetype[num]==1 && req==0)
	{
		rtn=min(rtn,min(a0,b0));
	}
	if(nodetype[num]==0 && req==1)
	{
		rtn=min(rtn,min(a1,b1));
	}
	if(nodetype[num]==0 && req==0)
	{
		rtn=min(rtn,a0+b0);
	}

	if(change[num]==1)
	{
		if(nodetype[num]==1 && req==1)
		{
			rtn=min(rtn,min(a1,b1)+1);
		}
		if(nodetype[num]==1 && req==0)
		{
			rtn=min(rtn,a0+b0+1);
		}
		if(nodetype[num]==0 && req==1)
		{
			rtn=min(rtn,a1+b1+1);
		}
		if(nodetype[num]==0 && req==0)
		{
			rtn=min(rtn,min(a0,b0)+1);
		}
	}
	return rtn;
}

int main()
{
	cin >> n;
	for(n2=0;n2<n;n2++)
	{
		memset(nodetype,-1,sizeof(nodetype));
		memset(change,-1,sizeof(change));
		memset(leaf,-1,sizeof(leaf));
		ans=0;
		cin >> m >> v;
		for(x=1;x<(int)(m-1)/2 + 1;x++)
		{
			cin >> nodetype[x] >> change[x];
		}
		for(x=1;x<(int)(m+1)/2 + 1;x++)
		{
			cin >> leaf[x+(m-1)/2];
		}

		ans=saiki(1,v);
		
		if(ans>=INF)
		{
			cout << "Case #" << n2+1 << ": " << "IMPOSSIBLE" << endl;
		}
		else
		{
			cout << "Case #" << n2+1 << ": " << ans << endl;
		}
	}
	return 0;
}