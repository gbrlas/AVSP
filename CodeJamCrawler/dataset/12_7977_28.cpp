#include <cstdio>
#include <iostream>

int t, n;
int v[1001][1001];
bool solved[1001];
int ans[1001][1001];
bool flag;

void solve(int i)
{
	int j, k;
	//cout<<"["<<i<<"]";
	
	if(flag)
		return;
	
	if (solved[i])
		return;
		
	for(j=1; j<=n; j++)
	{
		if(v[i][j] == 1)
		{
			solve(j);
			if(flag)
				return;
			
			for(k=1; k<=n; k++)
   		{
   			ans[i][k] = ans[i][k] + ans[j][k];
   			
   			if(ans[i][k] > 1)
   			{
   				flag = true;
   				solved[i] = true;
   				return;
   			}	
   		}
   	}				
	}
	solved[i] = true;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
		
	int i, j, p, m;

	cin>>t;
	for(int tc=1; tc<=t; tc++)
	{
		cin>>n;
		
		for(i=1; i<=n; i++)
		{
			solved[i] = false;
			for(j=1; j<=n; j++)
			{
				v[i][j] = 0;
				ans[i][j] = 0;
			}
		}
		
		for(i=1; i<=n; i++)
		{
			cin>>m;
			for(j=1; j<=m; j++)
			{
				cin>>p;
				v[i][p] = 1;
				ans[i][p] = 1;
			}
		}
		
		flag = false;
		
		for(i=1; i<=n; i++)
		{
			solve(i);
			if(flag)
				break;
		
		}
		
		if(flag)
			cout<<"Case #"<<tc<<": Yes"<<endl;
		else
			cout<<"Case #"<<tc<<": No"<<endl;

		/*	
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
				cout<<ans[i][j]<<" ";
			cout<<endl;
		}
		*/
	}
	
	return 0;
}