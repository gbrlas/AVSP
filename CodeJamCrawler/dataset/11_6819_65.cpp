#include <iostream>
#include <vector>
using namespace std;
void solve(long long num)
{
	long long l,t,n,c;
	cin>>l>>t>>n>>c;
	long long d[n];
	long long ld[c];
	for(long long i=0;i<c;i++)
		cin>>ld[i];
	long long nld=0;
	for(long long i=0;i<n;i++)
	{
		d[i]=ld[nld];
		nld++;
		nld%=c;
	}
	vector<vector<long long> > a(n+1,vector<long long>(l+1));
	a[0][0]=0;
	for(long long i=1;i<=n;i++)
		for(long long j=0;j<=min(i,l);j++)
		{
			if(j==0)a[i][j]=a[i-1][j]+d[i-1]*2;
			else a[i][j]=a[i][j-1];
			if(j<i)a[i][j]=min(a[i][j],a[i-1][j]+d[i-1]*2);
			if(a[i][j]>=t && j>0)
			{
				a[i][j]=min(a[i][j],a[i-1][j-1]+
							max(0ll,t-a[i-1][j-1])+
							d[i-1]-max(0ll,t-a[i-1][j-1])/2);
			}
		}
	cout<<fixed;
	cout.precision(0);
	cout<<"Case #"<<num<<": "<<a[n][l]<<'\n';
}
int main()
{
	long long t;
	cin>>t;
	for(long long i=0;i<t;i++)
		solve(i+1);
	return 0;
}
