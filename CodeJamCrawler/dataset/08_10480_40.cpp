#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>

using namespace std;
const int SIZE = 1000005;

int rank[SIZE];
int p[SIZE];
int cmp;
int find( int x)
{
	if( p[x] == x) return x;
	return p[x] = find(p[x]);
}
void merg(int x,int y)
{
	int px = find(x);
	int py = find(y);

	if( px == py) return;
	cmp--;
	if( rank[py] == rank[px] ){
		p[px] = py;
		rank[py]++;
		return;
	}
	if(rank[py]<rank[px]){ p[py] = px; return; }

	p[px] = py;
}

//set<int> prims[SIZE];
map<int, queue<int> > m;
void fact(long long x,int ind)
{
	int d = 1;
	long long i;
	for( i=2;i*i<=x;i+=d,d=2)
	{
		if( x%i == 0 )
		{
			while(x%i==0)
				x/=i;
			//			prims[ind].insert(i);
			m[i].push(ind);
		}
		if( i*i == x) break;
		if( i>= SIZE ) break;
	}
	if( x!=1 && i*i>x)
		m[x].push(ind);
	//prims[ind].insert(x);
}

int main()
{
	freopen("in.in","rt",stdin);
	freopen("out.out","wt",stdout);
	long long i;
	long long A,B,P;
	int TC;
	cin>>TC;
	for(int tc=1;tc<=TC;tc++)
	{
		memset(rank,0,sizeof(rank));
		for(i=0;i<SIZE;i++)
			p[i]=i;
		m.clear();
		cin>>A>>B>>P;
		cmp = B-A+1;
		for(i=A;i<=B;i++)
			fact(i,i-A);
		int x;
		map<int, queue<int> >::iterator it = m.lower_bound(P);
		for(;it!=m.end();it++)
		{
			x = it->second.front();
			it->second.pop();
			while(!it->second.empty())
			{
				merg(x,it->second.front());
				it->second.pop();
			}
		}

		cout<<"Case #"<<tc<<": "<<cmp<<endl;
	}
	return 0;
}
