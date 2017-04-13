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
#include <hash_set>

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

int pw10[10];

int main()
{
#ifndef ONLINE_JUDGE
	{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}
#endif
	int tst;
	scanf("%d",&tst);
	pw10[0]=1;
	rept(i,9) pw10[i+1]=pw10[i]*10;
	rept(t,tst)
	{
		int A,B;
		scanf("%d%d",&A,&B);
		int pw(0);
		while (pw10[pw]<=A) ++pw;
		--pw;
		int res(0);
		vector< pii > st;
		FOR(i,A,B)
		{
			rept(j,pw)
			{
				int last=i%pw10[j+1];
				int number=i/pw10[j+1]+last*pw10[pw-j];
				if (number>=A && number<=B && number!=i) st.pb(mp(min(number,i),max(number,i)));
			}
		}
		sort(all(st));
		st.resize(unique(all(st))-st.begin());
		printf("Case #%d: %d\n",t+1,sz(st));
	}
	return 0;
}