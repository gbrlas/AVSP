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
typedef vector<int> VI;
typedef vector<vector<int> > VII;
typedef vector<string> VS;
typedef pair<int,int> para;

#define FOREACH(i,n) for(__typeof((n).begin()) i=((n).begin());i!=(n).end();++i)
#define REP(a,n) for(int a=0;a<(n);a++)
#define PB push_back
#define ALL(v) v.begin(),v.end()
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define MP make_pair
#define F first
#define S second

const int N = 300;

int t[N];

char s[N];

int main()
{
  int D,n;
  scanf("%d",&D);
  FOR(I,1,D){
    scanf("%d",&n);
    REP(i,n){
      scanf("%s",s);
      int k = 0;
      REP(j,n){
        if(s[j]!='0')
          k = j;
      }
      t[i] = k;
    }
    int wyn = 0;
    REP(i,n){
      int j;
      for(j=i;j<n;j++)
        if(t[j]<=i){
          wyn += j-i;
          break;
        }
      for(int zzz = j;zzz > i; zzz--)
        swap(t[zzz],t[zzz-1]);
    }
    printf("Case #%d: %d\n",I,wyn);
  }
	return 0;
}
