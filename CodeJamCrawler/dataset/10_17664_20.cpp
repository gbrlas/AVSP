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
	queue<int> q;
	queue<int> b;
	q=b;
	FILE *p;
	FILE *o;
	p=fopen("in.in","r");
	o=fopen("ou","w");
	int c;
	int n;
	LL r,k;	
	int tmp;
	fscanf(p,"%i",&n);		
	FOR(1,n,h)
	{
		q=b;
		fscanf(p,"%lli %lli %i",&r,&k,&c);		
		FOR(1,c,v)
		{
			int t;
			fscanf(p,"%i",&t);
			q.push(t);
		}		
		int mo=0;
		for(LL l=1;l<=r;l++)
		{
			int s=0;
			int i=0;			
			while(i<=c-1)
			{
				tmp=q.front();
				s+=tmp;
				if(s<=k)
				{
					q.pop();
					q.push(tmp);
				}
				else
				{
					s-=tmp;
					break;
				}
				i++;
			}
			mo+=s;			
		}
		fprintf(o,"Case #%i: %i\n",h,mo);
	}
	
	return 1;
}
