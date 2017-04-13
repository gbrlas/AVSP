#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <cstring>
#include <cctype>
#include <queue>
#include <list>
#include <cstdlib>
#include <cmath>
#include <deque>
using namespace std;

typedef long long LL;
typedef pair<int,int> para;
typedef vector<int> VI;
typedef vector<vector<int> > VII;
typedef vector<string> VS;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define fore(a,n) for(typeof(n.begin())a=n.begin();a!=n.end();++a)
#define REP(a,n) for(int a=0;a<(n);a++)
#define ALL(x) x.begin(),x.end()

const int N = 107;
map<string,int> sl;
int j,D,n,q,zap[1077],st[N];
char cs[N];
string s;

int main()
{
	scanf("%d",&D);
	for(int I=1;I<=D;I++){
		sl.clear();
		scanf("%d\n",&n);
		REP(i,n){
			gets(cs);
			s=cs;
			sl[s]=i+1;
		}
		scanf("%d\n",&q);
		REP(i,q){
			gets(cs);
			s=cs;
			zap[i]=sl[s];
		}
		int w=1,l=0;
		memset(st,0,sizeof(st));		
		REP(i,q){
			if(st[zap[i]]!=w){
				l++;
			}
			if(l==n){
				w++;
				l=1;
			}
			st[zap[i]]=w;
		}
		printf("Case #%d: %d\n",I,--w);
	}
	return 0;
}
