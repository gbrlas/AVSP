#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;


#define PII pair<long long,long long>
#define MP make_pair
#define VI vector<int>
#define eps 1e-9
#define inf 1000000007

string a[200];
int t , n , m , i , j ;

int main()
{
	freopen("c:/input.txt","r",stdin);
	freopen("c:/output.txt","w",stdout);
	cin>>t;
	for (int tt = 1; tt <= t; tt++)
	{
		cin>>n>>m;
		for (i = 0; i < n; i++)
			cin>>a[i];

		for (i = 0; i < n-1; i++)
		{
			for (j = 0; j < m-1; j++)
			{
				if (a[i][j] == '#' && a[i+1][j] == '#' && a[i][j+1] == '#' && a[i+1][j+1] == '#')
				{
					a[i][j] = a[i+1][j+1] = '/';
					a[i+1][j] = a[i][j+1] = '\\';
				}
			}
		}

		int d = 0;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				if (a[i][j] == '#')
					d = 1;

		cout<<"Case #"<<tt<<":\n";
		if (d==1)
		{
			cout<<"Impossible\n";
		} else
		{
			for (i = 0; i < n; i++)
				cout<<a[i]<<endl;
		}
	}
	return 0;
}



