#define _CRT_SECURE_NO_DEPRECATE

#pragma comment(linker,"/STACK:260108864")

#include <iostream>
#include <ctime>
#include <cstdio>
#include <memory>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <utility>
#include <iterator>
#include <bitset>
#include <sstream>
#include <numeric>

#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
#define LL long long
#define ULL unsigned LL
#define VI vector<int>
#define X first
#define Y second
#define sz(_v) ((int)_v.size())
#define all(_v) (_v).begin(),(_v).end()
#define FOR(i,a,b) for (int i(a); i<=(b); ++i)
#define rep(i,a) FOR(i,1,a)
#define rept(i,a) FOR(i,0,(int)(a)-1)
#define x1 X1
#define y1 Y1
#define sqr(a) ((a)*(a))
#define C(a) memset((a),0,sizeof (a))
#define MS(a,x) memset((a),(x),sizeof (a))
#define INF 2000000000
#define PI 3.141592653589
#define eps 0.00000001
#define MOD 1000000007
#define PRIME 1000003

using namespace std;

string s[3]={"ejp mysljylc kd kxveddknmc re jsicpdrysi",
			 "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
			 "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
string res[3]={"our language is impossible to understand",
			   "there are twenty six factorial possibilities",
			   "so it is okay if you want to just give up"};

map<char,char> code;

int main()
{
#ifndef ONLINE_JUDGE
	{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}
#endif
	rept(i,3)
	{
		rept(j,s[i].length())
		{
			if (s[i][j]!=' ') code[s[i][j]]=res[i][j];
		}
	}
	code['q']='z';
	code['z']='q';
	int tst;
	scanf("%d\n",&tst);
	rept(t,tst)
	{
		string s;
		getline(cin,s);
		rept(i,s.length()) if (s[i]!=' ') s[i]=code[s[i]];
		cout<<"Case #"<<t+1<<": "<<s<<endl;
	}
	return 0;
}