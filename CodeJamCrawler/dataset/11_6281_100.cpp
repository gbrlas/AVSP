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

#define PB push_back
#define MP make_pair

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



int main()
{
 	freopen("A.in","r",stdin);
 	freopen("C.out","w",stdout);
	int T,i,j,l,n,k,p,q;
	cin>>T; 
	for (l=1;l<=T;l++)
	{
		cin>>n;
		vector<int> v;
		q=0;
		REP(i,n) {cin>>p;v.push_back(p);q^=p;}
		if (q!=0) printf("Case #%d: NO\n",l);
		else
		{
			sort(v.begin(),v.end());
			int ans=0;
			FOR(i,1,n-1) ans+=v[i];
			printf("Case #%d: ",l);cout<<ans<<endl;
		}
	}
	return 0;
}


