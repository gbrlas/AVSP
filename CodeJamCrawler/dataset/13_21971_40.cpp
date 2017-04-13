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
using namespace std;

#define millun 1000000
#define svdsize 100000003

long long svd[svdsize];
char str[100];

bool pal(long long x)
{
	memset(str,0,sizeof str);

	long long cnt=0;
	while(x)
	{
		long long tmp=x%10;
		str[cnt]='0'+tmp;
		x/=10;
		cnt++;
	}

	--cnt;

	for(long long i=0; i < cnt; i++,cnt--)
		if(str[i]!=str[cnt])
			return false;

	return true;
}

void pre()
{
	memset(svd,-1,sizeof svd);

	svd[0]=0;

	long long cnt=0;
	for(long long i=1; i < 10000003; i++)
	{
		long long sq=i*i;
		bool cnted=false;

		if(pal(i) && pal(sq))
			cnt++,cnted=true;

		if((sq/millun) < svdsize && svd[sq/millun]==-1)//sq%millun==0)
		{
			if(sq%millun != 0)
			{
				if(cnted)
					svd[sq/millun]=cnt-1;
				else
					svd[sq/millun]=cnt;
			}
			else
				svd[sq/millun]=cnt;

			//cout<<sq/millun<<": "<<svd[sq/millun]<<endl;
		}
	}

	int cur=-1;
	for(int i=0; i < svdsize; i++)
	{
		if(svd[i]==-1)
			svd[i]=cur;

		//cout<<i<<": "<<svd[i]<<endl;

		if(cur==-1 || svd[i]!=cur)
			cur=svd[i];
	}
}

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("out.txt","w", stdout);

	pre();

	long long n;
	cin>>n;

	for(long long ccase=1; ccase <= n; ccase++)
	{
		long long a,b;
		cin>>a>>b;

		a--;
		long long cnta=svd[a/millun],cntb=svd[b/millun];
		for(long long i=((a/millun)*millun)+1; i <= a; i++)
		{
			long long sqrti=sqrt((double) i);

			if(sqrti*sqrti == i && pal(i) && pal(sqrti))
				cnta++;
		}

		for(long long i=((b/millun)*millun)+1; i <= b; i++)
		{
			long long sqrti=sqrt((double) i);

			if(sqrti*sqrti == i && pal(i) && pal(sqrti))
				cntb++;
		}

		cout<<"Case #"<<ccase<<": "<<cntb-cnta<<endl;
	}
}