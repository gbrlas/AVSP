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

int sum[105];
int n,s,p;

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
	rept(t,tst)
	{
		printf("Case #%d: ",t+1);
		scanf("%d%d%d",&n,&s,&p);
		rept(i,n) scanf("%d",sum+i);
		int moreThanPCanBeSurprise(0);
		int moreThanPCantBeSurprise(0);
		int canBeMoreIfSurprise(0);
		int lessCanBeSurprise(0);
		int lessCantBeSurprise(0);
		int moreThanCanBeSurptiseOnlyIfLess(0);
		rept(i,n)
		{
			bool S(false);
			bool SAP(false);
			bool P(false);
			rept(a1,11)
			{
				FOR(a2,a1,10)
				{
					FOR(a3,a2,10)
					{
						if (a1+a2+a3!=sum[i]) continue;
						if (a3-a1>2) continue;
						if (a3>=p && a3-a1==2) SAP=true;
						else if (a3>=p) P=true;
						else if (a3<p && a3-a1==2) S=true;
					}
				}
			}
			if (P && SAP) moreThanPCanBeSurprise++;
			else if (P && !SAP && !S) moreThanPCantBeSurprise++;
			else if (P && !SAP && S) moreThanCanBeSurptiseOnlyIfLess++;
			else if (!P && SAP) canBeMoreIfSurprise++;
			else if (S) lessCanBeSurprise++;
			else lessCantBeSurprise++;
		}
		if (canBeMoreIfSurprise>=s)
			printf("%d\n",moreThanCanBeSurptiseOnlyIfLess+moreThanPCanBeSurprise+moreThanPCantBeSurprise+s);
		else if (s<=canBeMoreIfSurprise+moreThanPCanBeSurprise+lessCanBeSurprise)
			printf("%d\n",moreThanCanBeSurptiseOnlyIfLess+moreThanPCanBeSurprise+moreThanPCantBeSurprise+canBeMoreIfSurprise);
		else if (s<=canBeMoreIfSurprise+moreThanPCanBeSurprise+lessCanBeSurprise+moreThanCanBeSurptiseOnlyIfLess)
			printf("%d\n",moreThanPCanBeSurprise+moreThanPCantBeSurprise+(canBeMoreIfSurprise+moreThanPCanBeSurprise+lessCanBeSurprise+moreThanCanBeSurptiseOnlyIfLess-s));
	}
	return 0;
}