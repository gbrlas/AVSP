#include <iostream>
#include <vector>
using namespace std;
void solve(int num)
{
	int n;
	cin>>n;
	vector<vector<char> > a(n,vector<char>(n));
	vector<int> sum(n),cnt(n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='1')sum[i]++;
			if(a[i][j]=='0' || a[i][j]=='1')cnt[i]++;
		}
	long double wp[n],owp[n],oowp[n];
	for(int i=0;i<n;i++)wp[i]=(long double)(sum[i])/cnt[i];
	for(int i=0;i<n;i++)
	{
		long double osum=0;
		for(int j=0;j<n;j++)
			if(a[i][j]=='0' || a[i][j]=='1')
			{
				osum+=(long double)(sum[j]-(a[j][i]-'0'))/(cnt[j]-1);
			}
		owp[i]=osum/cnt[i];
	}
	for(int i=0;i<n;i++)
	{
		long double osum=0;
		for(int j=0;j<n;j++)
			if(a[i][j]=='0' || a[i][j]=='1')osum+=owp[j];
		oowp[i]=osum/cnt[i];
	}
	cout<<"Case #"<<num<<":\n";
	for(int i=0;i<n;i++)
		cout<<(0.25*wp[i]+0.5*owp[i]+0.25*oowp[i])<<'\n';
}
int main()
{
	int t;
	cin>>t;
	cout.precision(9);
	for(int i=0;i<t;i++)solve(i+1);
}
