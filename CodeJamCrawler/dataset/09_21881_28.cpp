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

const int N = 107;

int D,n;
double x[N], y[N], r[N];

double dist(int i, int j){
  return (sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))+r[i]+r[j])/2.;
}

int main()
{
  scanf("%d",&D);
  FOR(I,1,D){
    scanf("%d",&n);
    REP(i,n)
      scanf("%lf %lf %lf",&x[i], &y[i], &r[i]);
    double res = 0.;
    if(n==1)
      res = r[0];
    else if(n==2)    {
      res = max(r[0],r[1]); 
    }
    else if(n==3){
      res = max(dist(0,1), r[2]);
      res = min(res, max(dist(1,2), r[0]));
      res = min(res, max(dist(0,2), r[1]));
    }
    printf("Case #%d: %.7lf\n",I,res);
  }
	return 0;
}
