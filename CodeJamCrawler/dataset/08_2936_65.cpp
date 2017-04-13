#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1001000;
__int64 primes[MAXN];
int np=0;
int r[MAXN],father[MAXN];

int comp(int k)
{
	if (father[k]!=k)
		father[k]=comp(father[k]);
	return father[k];
}
void unite(int a, int b)
{
	a=comp(a);
	b=comp(b);
	if (r[a]>r[b])
		swap(a,b);
	father[a]=b;
	if (r[a]==r[b])
		r[a]++;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	primes[0]=2;
	np=1;
	for (int i=3;i<=1100000;i+=2)
	{
		int ind=0;
		for (int j=0;j<np && primes[j]*primes[j]<=i;j++)
			if (i%primes[j]==0)
			{
				ind=1;
				break;
			}
		if (!ind)
			primes[np++]=i;
	}
	
	int t,it;
	scanf("%d",&t);
	for (it=0;it<t;it++)
	{		
		__int64 a,b,p;
		scanf("%I64d%I64d%I64d",&a,&b,&p);

		if (p>b-a)
		{
			printf("Case #%d: %I64d\n",it+1,b-a+1);
			continue;
		}
		
		for (int i=0;i<=b-a;i++)
		{
			r[i]=1;
			father[i]=i;
		}
		int num=b-a+1;
		int first;
		for (first=0;first<np && primes[first]<p;first++) ;
		for (;first<np;first++)
		{
			__int64 n = primes[first];
			__int64 f = (a+n-1)/n*n;
			for (__int64 j=f+n;j<=b;j+=n)
				if (comp(int(j-a))!=comp(int(f-a)))
				{
					unite(int(j-a),int(f-a));
					num--;
				}
		}
		printf("Case #%d: %I64d\n",it+1,num);
	}
	return 0;
}
