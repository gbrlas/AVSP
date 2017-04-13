#include<iostream>
#include<vector>
#include<sstream>
#include<cmath>
#include<string>
#include<set>
#include<algorithm>
#include<fstream>
#include<numeric>
using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define all(a) a.begin(),a.end()

#define INF 1e6;
vector<int> pris;
int mask;
int n,q;
int memo[500];
int dfs(int mask)
{
	if(memo[mask]!=-1) return memo[mask];
	if(mask == pow(2,double(q))-1) return 0;
	int final=INF;
	FOR(i,0,q)
	{
		if( (mask & (1<<i))!= 0) 
			continue;
		int low=0;
		int high=n+1;
		FOR(j,0,q)
		{
			if(  ( mask & (1<<j) ) != 0 )
			{
				int cur=pris[j];
				if(pris[j] < pris[i])
				{
					if(pris[j]>low) low=pris[j];
				}
				if(pris[j] > pris[i] )
				{
					if(pris[j]<high) high=pris[j];
				}
			}
		}
		int cost=high-low+1-3;
		int ctr=cost+dfs(mask|(1<<i));
		if(ctr<final)
			final=ctr;
	}
	//cout<<final<<endl;
	memo[mask]=final;
	return final;
}

int main()
{
	ifstream fin("C:\\C.in");
	ofstream fout("C:\\C.out");
	int t;
	fin>>t;
	FOR(k,0,t)
	{
		memset(memo,-1,sizeof(memo));
		fin>>n>>q;
		pris.clear();
		FOR(i,0,q)
		{
			int temp;
			fin>>temp;
			pris.push_back(temp);
		}
		sort(all(pris));
		mask=0;
		int ans=dfs(0);
		fout<<"Case #"<<k+1<<": "<<ans<<endl;
	}
}
