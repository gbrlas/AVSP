#include <iostream>
#include <math.h>
using namespace std;
const int maxn=20000;
long long a[maxn],i,j,lcm,gcd,t,n,l,r,k,ans;

int mycmp(const void *i,const void *j)
{
	static long long ii;
	ii=*(long long*)i;
	static long long jj;
	jj=*(long long*)j;
	if (ii<jj) return -1;
	else if (ii==jj) return 0;
	else return 1;
}


long long GCD(long long i,long long j)
{
	static long long k;
	while (j)
	{
		k=i%j;
		i=j;
		j=k;
	}
	return i;
}

long long LCM(long long i,long long j)
{
	i/=GCD(i,j);
	return i*j;
}

int main()
{
	bool flag;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>t;
	for (int count_t=1;count_t<=t;count_t++)
	{
		cin>>n>>l>>r;
		ans=-1;
		for (i=0;i<n;i++) cin>>a[i];
		qsort(a,n,sizeof(long long),mycmp);
		/*for (i=0;i<n;i++)
		{
			gcd=a[i];
			for (j=i+1;j<n;j++) gcd=GCD(gcd,a[j]);
			flag=true;
			for (j=0;(j<i)&&(flag);j++) if (gcd%a[j]!=0) flag=false;
			if (!flag) continue;
			lcm=1;
			for (j=0;j<i;j++) lcm=LCM(lcm,a[j]);
			for (j=lcm;j<=gcd;j++)
				if ((gcd%j==0)&&(j%lcm==0))
					if ((l<=j)&&(j<=r))
						if ((ans==-1)||(ans>j)) ans=j;
		}*/
		for (i=l;i<=r;i++)
		{
			flag=true;
			for (j=0;(j<n)&&(flag);j++)
				if ((i%a[j]!=0)&&(a[j]%i!=0)) flag=false;
			if (flag)
			{
				ans=i;
				break;
			}
		}
		cout<<"Case #"<<count_t<<": ";
		if (ans==-1) cout<<"NO"<<endl;
		else cout<<ans<<endl;
	}
}