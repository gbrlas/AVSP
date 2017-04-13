#include <iostream>
using namespace std;

int a[100][100];

bool check(int n,int m)
{
	bool visited[2];
	int cnt;
	for(int i=0;i<n;i++)
	{
		cnt=0;
		visited[0]=visited[1]=false;
		for(int j=0;j<m;j++)
			if(!visited[a[i][j]-1])
			{
				visited[a[i][j]-1]=true;
				cnt++;
			}
		if(cnt==2)
			for(int j=0;j<m;j++)
				if(a[i][j]==1)
				{
					for(int k=0;k<n;k++)
						if(a[k][j]==2)
							return false;
				}
	}
	return true;
}

int main()
{
	int T,n,m;
	bool ans;
	cin>>T;
	for(int loop=1;loop<=T;loop++)
	{
		cin>>n>>m;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>a[i][j];
		ans=check(n,m);
		if(ans)
			cout<<"Case #"<<loop<<": YES"<<endl;
		else
			cout<<"Case #"<<loop<<": NO"<<endl;
	}
	return 0;
}