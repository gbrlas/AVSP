#include <iostream>
#include <vector>
using namespace std;
void solve(int num)
{
	int r,c;
	cin>>r>>c;
	char a[r][c];
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			cin>>a[i][j];
	bool broken=false;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(a[i][j]=='#')
			{
				if(j==c-1 || a[i][j+1]!='#' || i==r-1 || a[i+1][j]!='#' || a[i+1][j+1]!='#')
				{
					broken=true;
					break;
				}
				a[i][j]='/';
				a[i][j+1]='\\';
				a[i+1][j]='\\';
				a[i+1][j+1]='/';
			}
		}
		if(broken)break;
	}
	cout<<"Case #"<<num<<":\n";
	if(broken)cout<<"Impossible\n";
	else
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
				cout<<a[i][j];
			cout<<'\n';
		}
}
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)solve(i+1);
	return 0;
}
