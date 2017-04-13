#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

#define VI vector<int>
#define PII pair<int,int>
#define f0(i,n) for(i = 0; i < n; i++)
#define eps 1e-9
#define MP make_pair


using namespace std;

int a[200][200] , g[200][200] , u[1000000] , d[1000000];
int i , j , k , n , m , p;



int main()
{
	freopen("d:/input.txt" , "r" , stdin);
	freopen("d:/output.txt" , "w" , stdout);
	int t;
	cin>>t;
	for (int tt = 0; tt < t; tt++)
	{
		cin>>n>>k;
		for (i = 0; i < n; i++)
			for (j = 0; j < k; j++)
				cin>>a[i][j];
		
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				g[i][j] = 0;
		
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (i == j) continue;
				for (int kk = 0; kk < k; kk++)
					if (a[i][kk] == a[j][kk])
					{
						g[i][j] = 1; break;
					} else
						if (kk > 0)
						if (a[i][kk-1] >= a[j][kk-1] && a[i][kk] <= a[j][kk] || a[i][kk-1] <= a[j][kk-1] && a[i][kk] >= a[j][kk])
						{
							g[i][j] = 1; break;
						}
			}
		}

		d[0] = 0;
		for (i = 1; i <= (1<<n); i++)
			d[i] = 1000;

		for (i = 0; i < (1<<n); i++)
		{
			u[i] = 0;
			for (j = 0; j < n; j++)
				if ((i & (1<<j)) > 0)
				{
					for (k = 0; k < n; k++)
					{
						if ((i & (1<<k)) > 0)
						{
							if (g[j][k] == 1)
							{
								u[i] = 1;  break;
							}
						}
					}
				}

		}

		for (i = 0; i < (1<<n); i++)
		{
			j = ((1<<n) - 1) ^ i;

			int s = j;
			while (s > 0) 
			{
				if (u[s] == 0)
				{
					d[i | s] = min(d[i | s] , d[i] + 1);
				}
				s = (s-1) & j;
			}

		}
		

		cout<<"Case #"<<tt+1<<": ";
		cout<<d[(1<<n) - 1]<<endl;


	}
	return 0;
}