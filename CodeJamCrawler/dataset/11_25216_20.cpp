#include <iostream>
using namespace std;
const int maxn=100;
char a[maxn][maxn];
double wp[maxn],wp1[maxn][maxn],owp[maxn],oowp[maxn],sum,m;
int i,j,k,n,t;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>t;
	for (int count_t=1;count_t<=t;++count_t)
	{
		cin>>n;
		for (i=0;i<n;i++) 
			for (j=0;j<n;j++) cin>>a[i][j];
		for (i=0;i<n;i++)
		{
			sum=m=0;
			for (j=0;j<n;j++)
				if (a[i][j]=='1')
				{
					sum+=1;
					++m;
				} else
				if (a[i][j]=='0') m=m+1;
			if (m==0) m=1;
			wp[i]=sum/m;
			for (j=0;j<n;j++)
				if (a[i][j]!='.')
					if (m==1) wp1[i][j]=0;
					else wp1[i][j]=(sum-((a[i][j]=='1')?1:0))/(m-1);
				else wp1[i][j]=wp[i];
		}
		for (i=0;i<n;i++)
		{
			sum=m=0;
			for (j=0;j<n;j++)
				if (a[i][j]!='.')
				{
					sum+=wp1[j][i];
					++m;
				}
			if (m==0) m=1;
			owp[i]=sum/m;
		}
		for (i=0;i<n;i++)
		{
			sum=m=0;
			for (j=0;j<n;j++)
				if (a[i][j]!='.')
				{
					sum+=owp[j];
					++m;
				}
			if (m==0) m=1;
			oowp[i]=sum/m;
		}
		cout<<"Case #"<<count_t<<":"<<endl;
		for (i=0;i<n;i++) cout<<wp[i]*0.25+owp[i]*0.5+oowp[i]*0.25<<endl;
	}
}