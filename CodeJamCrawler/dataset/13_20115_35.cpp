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
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
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

//#define maxn 2010
//#define maxm 30
//const double expp=1e-7;
//#define mm 1000002013LL

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

LL n,p,pp;
LL pre,next;

LL work()
{
	LL rank=0;
	for (int i=1;i<=n;i++)
	{
		if (pre>0)
		{
			rank=rank*2+1;
			pre--;
			if (pre%2==1) pre--,next--;
			pre/=2;
			next/=2;
		}
		else
		{
			rank*=2;
			next--;
			next/=2;
		}
	}
	return rank;
}

LL work2()
{
	LL rank=0;
	for (int i=1;i<=n;i++)
	{
		if (next>0)
		{
			rank=rank*2;
			next--;
			if (pre%2==1) pre--,next--;
			pre/=2;
			next/=2;
		}
		else
		{
			rank=rank*2+1;
			pre--;
			pre/=2;
		}
	}
	return rank;
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
	
	/*n=3;
	for (LL i=0;i<(1<<n);i++)
	{
		pre=i;
		next=(1<<n)-i-1;
		cout<<i<<" "<<pre<<" "<<next<<" ";
		cout<<work()<<endl;
	}*/
	
	int T;
	scanf("%d",&T);
	for (int TT=1;TT<=T;TT++)
	{
		printf("Case #%d: ",TT);
		cin>>n>>pp;
		LL l=0,r=(1<<n)-1;
		p=pp-1;
		while (l<r)
		{
			LL mid=(l+r)/2+1;
			pre=mid;
			next=(1<<n)-mid-1;
			LL rank=work();
			if (rank<=p)
				l=mid;
			else
				r=mid-1;
		}
		cout<<l<<" ";
		
		l=0,r=(1<<n)-1;
		p=pp-1;
		while (l<r)
		{
			LL mid=(l+r)/2+1;
			pre=mid;
			next=(1<<n)-mid-1;
			LL rank=work2();
			if (rank<=p)
				l=mid;
			else
				r=mid-1;
		}
		cout<<l<<endl;	
	}

    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
