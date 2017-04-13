#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <stack>
#include <cmath>

#define pb push_back
#define pob pop_back

#define sz size()
#define fin(t) (int)t.sz-1

#define all(v) v.begin(),v.end()
#define forall(v,i) for(int i=0;i<=fin(v);i++)
#define rforall(v,i) for(int i=fin(v);i>=0;i--)

#define WR(v)  cout<<v
#define WRL(v) cout<<v<<endl
#define print(t) forall(t,k) if(k!=fin(t)) { WR(t[k]); WR(","); } else WRL(t[k]);
#define print2(t) forall(t,k)  forall(t[k],j) \
		if(j!=fin(t[k])) { WR(t[k][j]); WR(","); } else WRL(t[k][j]);
#define LL long long
#define VS vector<string>
#define VI vector<int> 
#define VD vector<double> 
#define VVD vector<VD > 
#define VVS vector<VS > 
#define VVI vector<VI >
#define FOR(a,b,i) for(int i=a;i<=b;i++)
#define RFOR(a,b,i) for(int i=a;i>=b;i--)

using namespace std;

int main()
{
	VI a(200,0);
	VI z(200,0);
	int m;
	FILE *pt;
	FILE *ou;
	
	pt=fopen("in.in","r");
	ou=fopen("ou.ou","w");
	
	fscanf(pt,"%i",&m);
	int n,k;
	FOR(0,m-1,r)
	{
		fscanf(pt,"%i %i",&n,&k);
		a=z;
		int i=0;
		bool f=true;
		FOR(1,k,j)
		{
			i=0;		
			f=true;
			do
			{
				if(!a[i])
				{
					a[i]=1;
					f=false;
				}
				else
					a[i]=0;
				i++;
			}while(i<=n+1 && f);
		}
		i=0;
		while(1)
		{
			if(!a[i])
				break;	
			i++;			
		}
		string re;
		if(i>=n)
			re="ON";
		else
			re="OFF";
		fprintf(ou,"Case #%i: %s\n",r+1,re.c_str());			
	}
	return 1;
}
