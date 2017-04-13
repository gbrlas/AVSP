
/* Author : Vamsi Kavala */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)	
#define mod 1000000007
#define MAXN 1000010

typedef pair<int,int>   PI;
typedef vector<int> VI;
typedef long long int LL;

int main(){

	int t;
	scanf("%d",&t);
	FOR(test,1,t+1)
	{
		int a,b;
		scanf("%d%d",&a,&b);

		set<PI> S;

		FOR(i,a,b+1)
		{
			ostringstream os;
			os<<i;
			string str=os.str();

			REP(k,str.length()-1)
			{
				char ch=str[str.length()-1];
				str=str.substr(0,str.length()-1);
				str=ch+str;

				istringstream is(str);
				int j;
				is>>j;

				if(j>=a && j<i)
					S.insert(PI(j,i));
			}
		}
		printf("Case #%d: %lld\n",test,(LL)S.size());
	}
	return 0;
}
