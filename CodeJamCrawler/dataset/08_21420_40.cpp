#include<cstdio>
#include<vector>
#include<map>
using namespace std;

long long p;

const int T=1001000;
bool h[T];
vector<long long>P;
void sito()
{
    for(int i=2; i<T; i++) h[i]=true;
    for(int i=2; i<T; i++)
    {
	if(h[i])
	{
	    P.push_back(i);
	    for(int k=2*i; k<T; k+=i) h[i]=false;
	}
    }
}

void rozloz(long long a, map<long long, int>&s)
{
    for(long long d=0; P[d]*P[d]<=a; d++)
    {
	if(a%P[d]==0)
	{
	    while(a%P[d]==0) a/=P[d];
	    if(P[d]>=p)
	    s[P[d]]=0;
	}
    }
    if(a>=p) s[a]=0;
}

vector<vector<int> >v;
int s[1000001];
int rep(int a)
{
    if(s[a]<0) return a;
    return s[a]=rep(s[a]);
}

void polacz(int a, int b)
{
    if(s[a]<s[b]) //a wieksze
    {
	s[b]=a;
    }
    else if(s[b]<s[a]) //b wieksze
    {
	s[a]=b;
    }
    else
    {
	s[b]=a; s[a]--;
    }
}

main()
{
    sito();
    int c,cs=0;
    scanf("%d",&c);
    long long a,b;
    map<long long, int> primes;
    while(c--)
    {
	primes.clear();
	scanf("%lld %lld %lld",&a,&b,&p);
	for(long long i=a; i<=b; i++)
	{
	    rozloz(i,primes);
	}
	int akt=0;
	for(map<long long,int>::iterator it=primes.begin(); it!=primes.end(); it++) {it->second=akt++;}
	
	v.clear();
	for(int i=0; i<akt; i++) v.push_back(vector<int>());
	
	for(int i=0; i<akt; i++) v[i].clear();
	for(long long i=a; i<=b; i++)
	{
	    long long temp=i;
	    for(int d=0; P[d]*P[d]<=temp; d++)
	    {
		if(temp%P[d]==0)
		{
		    while(temp%P[d]==0) temp/=P[d];
		    if(P[d]>=p)
		    {
			v[ primes[P[d]] ].push_back(i-a);
		    }
		}
	    }
	    if(temp>=p) v[ primes[temp] ].push_back(i-a);
	}
	int res=b-a+1;
	for(int i=0; i<=res; i++) s[i]=-1;
	for(int i=0; i<akt; i++)
	{
	    for(int j=1; j<v[i].size(); j++)
	    {
		int a=rep(v[i][j]), b=rep(v[i][j-1]);
		if(a!=b)
		{
		    res--;
		    polacz(a,b);
		}
	    }
	}
//	printf("akt=%d\n",akt);
	printf("Case #%d: %d\n",++cs,res);
    }
}
