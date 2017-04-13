#include <iostream>
using namespace std;
const int maxn=200;
char a[maxn][maxn];
int t,n,m,i,j,k,flag;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>t;
	for (int count_t=1;count_t<=t;count_t++)
	{
		cin>>n>>m;
		for (i=0;i<n;i++)
			for (j=0;j<m;j++) cin>>a[i][j];
		flag=1;
		for (i=0;(i<n)&&(flag);i++)
			for (j=0;(j<m)&&(flag);j++)
				if (a[i][j]=='#')
					if ((i==n-1)||(j==m-1)) flag=0;
					else if ((a[i][j+1]!='#')||(a[i+1][j]!='#')||(a[i+1][j+1]!='#')) flag=0;
					else
					{
						a[i][j]=a[i+1][j+1]='/';
						a[i+1][j]=a[i][j+1]='\\';
					}
		cout<<"Case #"<<count_t<<":"<<endl;
		if (flag)
		for (i=0;i<n;i++)
		{
			for (j=0;j<m;j++) cout<<a[i][j];
			cout<<endl;
		}
		else cout<<"Impossible"<<endl;
	}
}