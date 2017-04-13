#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;


#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define FORIT(a,aa) for(a=aa.begin();a!=aa.end();++a)
#define split(str) {vs.clear();istringstream sss(str);while(sss>>(str))vs.push_back(str);}

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<char,char> PCC;

ll gcd(ll a,ll b)
{
	return a==0?b:gcd(b%a,a);
}


int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	ll T,i,j,cs,k;

	cin>>T; 
	for (cs=1;cs<=T;cs++)
	{
		ll n,pd,pg,d;
		cin>>n>>pd>>pg;
		d=100/gcd(pd,100);
		if ((pg==0&&pd>0)||(pg==100&&pd<100)||d>n) printf("Case #%d: Broken\n",cs);
		else printf("Case #%d: Possible\n",cs);
	}
	return 0;
}


