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
	freopen("A.out","w",stdout);
	int T,i,j,l,n,k,p,q;

	cin>>T; 
	for (l=1;l<=T;l++)
	{
		vector<int> orange,blue;
		int o=1,b=1;
		string s="";
		cin>>n;
		char c;
		REP(i,n)
		{
			cin>>c>>p;
			s+=c;
			if (c=='O') { orange.push_back(abs(p-o));o=p;}
			else { blue.push_back(abs(p-b));b=p;}
		}
		int ans=0;
		o=b=0;
		int time=0;
		int lasto,lastb;
		lasto=lastb=0;
		REP(i,n)
		{
			if (s[i]=='O')
			{
				if (orange[o]<=time-lasto)
				{
					time+=1;
					lasto=time;
					o++;
				}
				else
				{
					time=lasto+orange[o]+1;
					lasto=time;
					o++;
				}
			}
			else
			{
				if (blue[b]<=time-lastb)
				{
					time+=1;
					lastb=time;
					b++;
				}
				else
				{
					time=lastb+blue[b]+1;
					lastb=time;
					b++;
				}
			}
		}
		printf("Case #%d: ",l);cout<<time<<endl;
	}
	return 0;
}


