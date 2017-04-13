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
typedef vector<int>		vi;
typedef vector<string>	vs;
typedef pair<int,int>	pii;
typedef map<string,int>	msi;

const double EPS	= 1E-9;
const int	 INF	= 1000000000;
const int64  INF64	= (int64)1E18;
const double PI		= 3.1415926535897932384626433832795;

char buf[100005]={0};

inline int min(int a,int b){return a<=b?a:b;}
inline int max(int a,int b){return a>=b?a:b;}
template<class T> void vsort(vector<T>v){sort(v.begin(),v.end());}
inline int geti(){int n; scanf("%d",&n);return n;}
inline char getc(){char c; scanf("%c",&c);return c;}
inline double getf(){double f; scanf("%lf",&f);return f;}
inline long getl(){long l; scanf("%ld",&l);return l;}
inline int64 getll(){int64 ll; scanf("%Ld",&ll);return ll;}
inline char* gets(){scanf("%s",buf);return buf;}
inline void swap(int *a, int *b)
{
	int t;
	t  = *a;
	*a = *b;
	*b = t;
}
int gcd(int a, int b)
{
	int t;
	if(a<b){
		t = a;
		a = b;
		b = t;
	}
	while(b>0)
	{
		t = a%b;
		a = b;
		b = t;
	}
	return a;
}

int indexof(char *str,char ch){
	int i=0;
	while(*str)
		if(*str++==ch)
			return i;
		else i++;
	return -1;
}

void solve() // for each case
{
	int possible = true;

	long int N;
	int Pd,Pg;
	scanf("%ld",&N);
	scanf("%d",&Pd);
	scanf("%d",&Pg);

	int gcdD = gcd(100,Pd);
	int gcdG = gcd(100,Pg);

	int winD = Pd/gcdD;
	int winG = Pg/gcdG;

	int lostD = (100-Pd)/gcdD;
	int lostG = (100-Pg)/gcdG;

	//fprintf(stderr,"N:%3d Pd:%3d Pg:%3d D:%d+%d\tG:%d+%d\n", N,Pd,Pg,winD,lostD,winG,lostG);

	if( (winD+lostD > N)
		|| (lostD!=0 && lostG == 0)
		|| (winD!=0 && winG==0) )
		possible = false;

	printf(possible?"Possible\n":"Broken\n");
}

#define inputLevel 1

#if inputLevel==0
	#define PATH_INP	"test.in"
	#define PATH_OUT	"test.out"
#elif inputLevel==1
	#define PATH_INP	"A-small-attempt1.in"
	#define PATH_OUT	"A-small-attempt1.out"
#else
	#define PATH_INP	"A-large-attempt0.in"
	#define PATH_OUT	"A-large-attempt0.out"
#endif

int main() {
    freopen(PATH_INP, "r", stdin);
    freopen(PATH_OUT, "w", stdout);

	int T;
	getloop(Case,T)
	{
		cout << "Case #" << Case+1 << ": ";
		solve();
	}

	return 0;
}
