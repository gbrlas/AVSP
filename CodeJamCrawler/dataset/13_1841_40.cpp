#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <complex>
#include <cctype>
#include <ctime>
using namespace std;

//Commonly used macros
#define GI              ({int t;scanf("%d",&t);t;})
#define GL              ({LL t;scanf("%lld",&t);t;})
#define GD              ({double t;scanf("%lf",&t);t;})
#define FOREACH(i,a)    for(typeof((a).begin()) i=(a).begin();i!=(a).end();i++)
#define SZ(a)           (int)(a.size())
#define ALL(a)          (a).begin(),(a).end()
#define SORT(a)         sort(ALL(a));
#define REVERSE(a)      reverse(ALL(a))
#define UNIQUE(a)       SORT(a),(a).resize(unique(ALL(a))-(a).begin())
#define IN(a,b)         ((b).find(a)!=(b).end())
#define fill(x,a)       memset(x, a, sizeof(x))
#define abs(a)          ((a)<0?-(a):(a))
#define maX(a,b)        ((a)>(b)?(a):(b))
#define miN(a,b)        ((a)<(b)?(a):(b))
#define checkbit(n,b)   ((n>>b)&1)
#define INDEX(arr,ind)	(lower_bound(all(arr),ind)-arr.begin())
#define FREOPEN 			freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)

//Main code begins here
char a[5][5];
int xc[5], oc[5], xr[5], orr[5], tr[5], tc[5];
int xd1, od1, td1;
int xd2, od2, td2;
bool curr;

bool diag1(int i, int j)
{
	if(i == j) return true;
	return false;
}

bool diag2(int i, int j)
{
	if(i+j == 3) return true;
	return false;
}

string solve(void)
{
	if(xd1 + td1 == 4) return "X won";
	if(xd2 + td2 == 4) return "X won";
	if(od1 + td1 == 4) return "O won";
	if(od2 + td2 == 4) return "O won";

	for(int ind = 0; ind < 4; ++ind)
	{
		if((xr[ind] + tr[ind]) == 4) return "X won";
		if((xc[ind] + tc[ind]) == 4) return "X won";
		if((orr[ind] + tr[ind]) == 4) return "O won";
		if((oc[ind] + tc[ind]) == 4) return "O won";
	}
	if(curr == true) return "Game has not completed";
	return "Draw";
}

int main()
{
	freopen("inp.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int kase = GI;

	for(int t = 1; t < kase + 1; ++t)
	{
		curr = false;
		fill(xc,0); fill(oc,0); fill(xr,0); fill(orr,0);
		fill(tr,0); fill(tc,0);
		xd1 = 0; od1 = 0; td1 = 0;
		xd2 = 0; od2 = 0; td2 = 0;
		for(int i = 0; i < 4; ++i)
		{
			for(int j = 0; j < 4; ++j)
			{
				cin>>a[i][j];
				if(a[i][j] == '.') curr = true;
				else if(a[i][j] == 'X') {xr[i]++; xc[j]++; if(diag1(i,j)) xd1++; if(diag2(i,j)) xd2++;}
				else if(a[i][j] == 'O') {orr[i]++; oc[j]++; if(diag1(i,j)) od1++; if(diag2(i,j)) od2++;}
				else if(a[i][j] == 'T') {tr[i]++; tc[j]++; if(diag1(i,j)) td1++; if(diag2(i,j)) td2++;}
			}
		}
		string ret = solve();
		cout<<"Case #"<<t<<": "<<ret<<endl;
    }

	return 0;
}
