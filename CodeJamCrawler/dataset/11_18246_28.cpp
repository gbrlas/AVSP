#define inputLevel 1

#if inputLevel==0
#define PATH_INP	"test.in"
#define PATH_OUT	"test.out"

#elif inputLevel==1
#define PATH_INP	"C-small-attempt0.in"
#define PATH_OUT	"C-small-attempt0.out"

#elif inputLevel==2
#define PATH_INP	"C-large.in"
#define PATH_OUT	"C-large.out"

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

typedef long int int64;

inline int geti()
{
    int n;
    scanf("%d",&n);
    return n;
}

int N,result;
int64 L,H,x[10000]= {0};

int64 gcd(int64 a,int64 b )
{
    int64 c;
    if(a<b)
    {
        c = a;
        a = b;
        b = c;
    }
    while ( b>0 )
    {
        a %= b;
        c  = a;
        a  = b;
        b  = c;
    }
    return a;
}

int64 lcm(int64 a,int64 b)
{
    int64 g = gcd(a,b);
    return a*(b/g);
}


void solve() // for each case
{
    bool can;
    scanf("%d%ld%ld\n",&N,&L,&H);

    for(int i=0; i<N; i++)
        scanf("%ld",&x[i]);

    for(result=L; result<=H; result++)
    {
        can=true;
        for(int i=0; i<N; i++)
        {
            int64 g = gcd(x[i],result);
            if(g!=x[i] && g!=result)
            {
                can = false;
                break;
            }
        }
        if(can) break;
    }

    if(can)
        cout << result << endl;
    else
        cout << "NO" << endl;
}

int main()
{
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
