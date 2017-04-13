#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <complex>
#pragma comment(linker, "/STACK:266777216")
using namespace std;

#define assert(f) { if(!(f)) { fprintf(stderr,"Assertion failed: "); fprintf(stderr,#f); fprintf(stderr,"\n"); exit(1); } }

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<double> VD;
typedef pair<double,double> PDD;

const int inf=1000000000;
const LL INF=LL(inf)*inf;
const double eps=1e-9;
const double PI=2*acos(0.0);
#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset((ar),(val),sizeof (ar))
#define MIN(a,b) {if((a)>(b)) (a)=(b);}
#define MAX(a,b) {if((a)<(b)) (a)=(b);}
#define sqr(x) ((x)*(x))
#define X first
#define Y second

clock_t start=clock();

int m,n;
string s[8];
vector<string> t[4];
#define C 111111
int num[C];

int trieSz(const vector<string>& a) {
  if(a.sz==0) return 0;
  set<string> trie;
  for(int i=0;i<a.sz;i++) {
    for(int j=1;j<=a[i].sz;j++)
      trie.insert(a[i].substr(0,j));
  }
  return trie.sz+1;
}

void rec(int i) {
  if(i==m) {
    int cur = 0;
    for(int j=0;j<n;j++)
      cur+=trieSz(t[j]);
    num[cur]++;
    return;
  }
  for(int j=0;j<n;j++) {
    t[j].pb(s[i]);
    rec(i+1);
    t[j].pop_back();
  }
}

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int TST,tst=0;
	for(cin >> TST;TST--;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
    cin >> m >> n;
    int i;
    for(i=0;i<m;i++)
      cin >> s[i];
    fill(num,0);
    rec(0);
    for(i=C-1;!num[i];i--);
    printf("%d %d\n",i,num[i]);
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
