#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <string.h>
#define pb push_back
#define mp make_pair
#define SS(a,b) scanf("%d%d",&a,&b);
#define S(a) scanf("%d",&a);
#define SSL(a,b) scanf("%lld%lld",&a,&b);
#define SL(a) scanf("%lld",&a);
#define SSS(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define GI ({int t;scanf("%d",&t);t;})
#define GL ({ll t;scanf("%lld",&t);t;})
#define MAXN 500000
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define REP(i,n) FOR(i,0,n)
#define INPUT freopen("input.txt","r",stdin);
#define OUTPUT freopen("output.txt","w",stdout);
#define disvec(v) { for(int vec_index=0;vec_index<v.size();vec_index++) cout<<v[vec_index]<<" "; cout<<endl;}
using namespace std;
typedef  long long LL;
typedef  long long ll;
int visited[300],visited1[300];
int main(){
	INPUT;
	OUTPUT;
	string a="ejp mysljylc kd kxveddknmc re jsicpdrysi";
	a+="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	a+="de kr kd eoya kw aej tysr re ujdr lkgc jv";
	string b="our language is impossible to understand";
	b+="there are twenty six factorial possibilities";
	b+="so it is okay if you want to just give up";
	set<char>s;
	map<char,char>M;
	REP(i,a.length()){
		M[a[i]]=b[i];
	}
	M['z']='q';M['q']='z';
	string input;
	int t=GI;getchar();
	for(int ca=1;ca<=t;ca++){
		getline(cin,input,'\n');
		REP(i,input.length())input[i]=M[input[i]];
		cout<<"Case #"<<ca<<": "<<input<<endl;
	}
	GI;
	return 0;
}
