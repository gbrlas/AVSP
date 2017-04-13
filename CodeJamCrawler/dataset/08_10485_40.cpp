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
bool sef[SIZE];
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

int main()
{

	freopen("in.in","rt",stdin);
	freopen("out.out","wt",stdout);
	long long i,j,x;
	long long A,B,P;
	int TC;
	cin>>TC;
	int d=1;
	for(i=2;i<=SIZE;i+=d,d=2)
	{
		if(!sef[i])
			for(j=i+i;j<=SIZE;j+=i)
				sef[j]=true;
	}
	for(int tc=1;tc<=TC;tc++)
	{
		memset(rank,0,sizeof(rank));
		for(i=0;i<SIZE;i++)
			p[i]=i;
		m.clear();
		cin>>A>>B>>P;
		cmp = B-A+1;
		/*for(i=A;i<=B;i++){
			fact(i,i-A);
			//if(i%10000 == 0)
			cerr<<i<<endl;
		}*/
		for(i=P;i<=SIZE && i<=B;i++)
		{
			if(!sef[i])
			{
				j = ((A+i-1)/i)*i;
				//while(j<A) j+=i;
				x = j;

				j+=i;
				for(;j<=B;j+=i)
					merg(x-A,j-A);
			}
		}
		/*int x;
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
*/
		cout<<"Case #"<<tc<<": "<<cmp<<endl;
	}
	return 0;
}
