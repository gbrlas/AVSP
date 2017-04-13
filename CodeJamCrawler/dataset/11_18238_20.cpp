#define inputLevel 2

#if inputLevel==0
	#define PATH_INP	"test.in"
	#define PATH_OUT	"test.out"

#elif inputLevel==1
	#define PATH_INP	"A-small-attempt0.in"
	#define PATH_OUT	"A-small-attempt0.out"

#elif inputLevel==2
	#define PATH_INP	"A-large.in"
	#define PATH_OUT	"A-large.out"

#elif inputLevel==3
	#define PATH_INP	"A-small-practice.in"
	#define PATH_OUT	"A-small-practice.out"
#endif

#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define fr(i,a,n)		for(int i=(int)(a);i<(int)(n);i++)
#define loop(i,x)		fr(i,0,x)
#define getloop(i,x)	x=geti(); fr(i,0,x)

typedef long long int	int64;
inline int geti(){int n; scanf("%d",&n);return n;}

void solve() // for each case
{
	int N;
	scanf("%d\n",&N);

	int team[N][N+1];
	double match[N],won[N],wp[N],owp[N],oowp[N],rpi[N];
	loop(i,N)
	{
		won[i]=0;
		match[i]=0;
		loop(j,N)
		{
			char ch;
			scanf("%c",&ch);
			team[i][j] = ch=='1' ? 1 : ch=='0' ? 0 : -1;
			if(ch=='1') won[i]++;
			if(ch!='.') match[i]++;
		}
		wp[i] = won[i]/match[i];
		scanf("\n");
	}

	loop(i,N)
	{
		owp[i]=0;
		int opponent=0;
		loop(j,N)
		{
			if(team[i][j]>=0)
			{
				owp[i]+=(won[j]+team[i][j]-1)/(match[j]-1);
				opponent++;
			}
		}
		owp[i] /= opponent;
	}

	loop(i,N)
	{
		oowp[i]=0;
		int opponent=0;
		loop(j,N)
		{
			if(team[i][j]>=0)
			{
				oowp[i]+=owp[j];
				opponent++;
			}
		}
		oowp[i] /= opponent;
	}
	loop(i,N)
	{
		rpi[i] = (wp[i] + 2*owp[i] + oowp[i])/4;
		printf("%.12f\n",rpi[i]);
	}
}

int main() {
    freopen(PATH_INP, "r", stdin);
    freopen(PATH_OUT, "w", stdout);

	int T;
	getloop(Case,T)
	{
		cout << "Case #" << Case+1 << ": " << endl;
		solve();
	}

	return 0;
}
