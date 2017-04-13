#include <iostream>
#include <math.h>
using namespace std;
const int maxn=1000000;
bool a[maxn];
int p[maxn];
double p1[maxn];
long long i,j,k,n,m,t;
double tmp;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	p[0]=0;
	for (i=2;i<maxn;i++)
		if (!a[i])
		{
			j=i+i;
			p[++p[0]]=i;
			p1[p[0]]=log((double) i);
			while (j<maxn)
			{
				a[j]=true;
				j+=i;
			}
		}
	cin>>t;
	for (int count_t=1;count_t<=t;count_t++)
	{
		cin>>n;
		if (n==1) m=0;
		else m=1;
		tmp=log((double)n);
		for (i=1;(i<=p[0])&&(n>p[i]);i++)
			m+=int(tmp/p1[i]+1e-10)-1;
		cout<<"Case #"<<count_t<<": "<<m<<endl;
	}
}