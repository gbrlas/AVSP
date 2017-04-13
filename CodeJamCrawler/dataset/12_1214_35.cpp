/* Jai Gupta */
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <deque>
#include <bitset>
#include <cmath>
#include <functional>
#include <set>

using namespace std;

#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define uint unsigned int
#define MAX(a,b)   (((a)>(b))?(a):(b))
#define MIN(a,b)   (((a)<(b))?(a):(b))
#define CMAX(a,b)  if((a)<(b)) a=b
#define CMIN(a,b)  if((a)>(b)) a=b
#define FOR(i,a,b)   for(i=a; i<b; i++)
#define REVI(i,a,b)  for(int i= a ; i >= b ; --i)
#define LET(x,a)     __typeof(a) x(a)
#define IFOR(i,a,b)  for(LET(i,a);i!=(b);++i)
#define EACH(it,v)   IFOR(it,v.begin(),v.end())
#define SWAP(a,b,t)  t=a,a=b,b=t
#define REP(i,n)     for(int i=0; i<n; i++)
#define ll           long long int
#define ull          unsigned long long int
#define gint(t)      scanf("%d", &t);
#define pint(t)      printf("%d\n", t);
#define pb           push_back

#ifdef JAI_ARENA
#define debug(args...) {dbg,args; cerr<<endl;}
#define dline cerr<<endl
#else
#define debug(args...) {};
#endif

typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<vi>      vii;


struct debugger
{
    template<typename T> debugger& operator , (const T& v)
	{
	    cerr<<v<<" ";
	    return *this;
	}
} dbg;


#define BUF 4096
char ibuf[BUF];
int ipt = BUF;
 
int readInt() {
    while (ipt < BUF && ibuf[ipt] < '0') ipt++;
    if (ipt == BUF) {
	fread(ibuf, 1, BUF, stdin);
	ipt = 0;
	while (ipt < BUF && ibuf[ipt] < '0') ipt++;
    }
    int n = 0;
    while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
    if (ipt == BUF) {
	fread(ibuf, 1, BUF, stdin);
	ipt = 0;
	while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
    }
    return n;
}


/* memset(start*, byteVal, numBytes);
 *  memcpy(dst*, src*, numBytes);
 */

int d[10005];
int l[10005];
int maxD[10005];
int D;
int main()
{
    int t; gint(t);
    IFOR(ti, 1, t+1)
    {
	int n; gint(n);
	REP(ni, n)
	{
	    gint(d[ni]); gint(l[ni]);
	    
	}
	gint(D);
	n++;
	d[n-1] = D;
	l[n-1] = D+1;
	memset(maxD, 0, sizeof(int)*n);
	
	maxD[0] = d[0];
	queue<int> uq;
	uq.push(0);
	while(!uq.empty())
	{
	    int lm = uq.front();
	    int myd = maxD[lm];
	    //debug(lm, myd);
	    int sd = d[lm];
	    int p = lm+1;
	    uq.pop();
	    while(p<n)
	    {
		if(d[p] <= sd + myd) {
		    int rd = d[p] - sd;
		    if(rd > l[p]) rd = l[p];
		    if(rd > maxD[p]) {
			uq.push(p);
			maxD[p] = rd;
			//debug("reaching", p, maxD[p], "from", lm);
		    }
		}
		p++;
	    }
	}
	if(maxD[n-1] > 0)
	{
	    printf("Case #%d: YES\n", ti);
	}else  {
	    printf("Case #%d: NO\n", ti);
	}
    }
    return 0;
}
