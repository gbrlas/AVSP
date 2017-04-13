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
#define FOREACH(a,n) for (__typeof(n.begin())a=n.begin();a!=n.end();++a)
#define FOR(i,a,b) for (int i=(a);i<=(b);++i)
#define FORD(i,a,b) for (int i=(a);i>=(b);--i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define ALL(x) x.begin(),x.end()
#define CLR(t) memset(t,0,sizeof(t));

const int D = 19, MOD=10000;
char word[D+1]="welcome to code jam";

int n, res[20];

char buf[10000007];

int main()
{
  scanf("%d\n",&n);
  REP(I,n){
    REP(i,D+1)
      res[i] = 0;
    res[0]=1;
    gets(buf);    
    for(int i=0;buf[i];i++){
      char c = buf[i];
      REP(j,D)
        if(c==word[j]){
          res[j+1] = (res[j+1]+res[j])%MOD;
        }
    }
    printf("Case #%d: %04d\n",I+1,res[D]);
  }
	return 0;
}
