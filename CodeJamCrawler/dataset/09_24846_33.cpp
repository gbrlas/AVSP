#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <map>
#include <fstream>
#include <cstdlib>
#include <queue>
#include <bitset>
#include <set>
#include <stack>
#include <utility>
using namespace std;
#define FR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,n) FR(i,0,n)
#define CLR(x,a) memset(x,a,sizeof(x))
#define MP make_pair
#define PB push_back
#define A first
#define B second
#define Len(a) (int)a.length()
#define Sz(a) (int)a.size()
typedef long long LL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
#define MAXN 100
const double Eps=1e-6;
const double Pi=2*acos(0.0);

int main()
{
	freopen("train.in","r",stdin);freopen("train.out","w",stdout);
 	//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	//freopen("packrec.in","r",stdin);freopen("packrec.out","w",stdout);
	int L,D,n;
	scanf("%d%d%d",&L,&D,&n);
	vector<string>a(D);
	FOR(i,D)
	{
		cin>>a[i];
	}
	FOR(k,n)
	{
		string s;
		cin>>s;
		vector<vector<char> >coll(L,vector<char>(26,false));
		int pos=0;
		bool flag=false;
		FOR(i,Len(s))
		{
			if(isalpha(s[i]))
			{
				if(flag)coll[pos][s[i]-97]=true;
				else
				{
					coll[pos][s[i]-97]=true;
					pos++;
				}
			}
			else
			{
				if(s[i]==')')
				{
					pos++;
					flag=false;
				}
				else
					flag=true;
			}
		}
		int cnt=0;
		FOR(i,D)
		{
			bool found=true;
			FOR(j,Len(a[i]))
			{
				if(!coll[j][a[i][j]-97])
				{
					found=false;
					break;
				}
			}
			if(found)cnt++;
		}
		printf("Case #%d: %d\n",k+1,cnt);
	}
	return 0;
}