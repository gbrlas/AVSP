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

typedef pair<char,char> PCC;


int main()
{
 	freopen("A.in","r",stdin);
 	freopen("B.out","w",stdout);
	int T,i,j,l,n,k,p,q;
	cin>>T; 
	for (l=1;l<=T;l++)
	{
		set<PCC> opp;
		map<PCC,char> com;
		int c;
		cin>>c;
		string s,now="";
		REP(i,c) 
		{
			cin>>s;
			com[PCC(s[0],s[1])]=s[2];
			com[PCC(s[1],s[0])]=s[2];
		}
		cin>>c;
		REP(i,c)
		{
			cin>>s;
			opp.insert(PCC(s[0],s[1]));
			opp.insert(PCC(s[1],s[0]));
		}
		cin>>n;
		cin>>s;
		REP(i,n)
		{
			
			if (now.size()==0) { now=s[i];continue;}
			char c1,c2;
			c1=s[i]; c2=now[now.size()-1];
			if (com.find(PCC(c1,c2))!=com.end()) { now[now.size()-1]=com[PCC(c1,c2)]; continue;}
			REP(j,now.size())
			{
				if (opp.find(PCC(c1,now[j]))!=opp.end()) { now="";break;}
			}
			if (now.size()) now+=c1;
		}
			
		printf("Case #%d: [",l);
		if (now.size())
		{
			cout<<now[0];
			FOR(i,1,now.size()-1)
			{
				cout<<", "<<now[i];
			}
		}
		cout<<"]\n";
	}
	return 0;
}


