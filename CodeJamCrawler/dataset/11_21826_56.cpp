#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;

#define VI vector<int>
#define PII pair<int,int>
#define MP make_pair

int test ,  i , j, n , m , k , ii , jj , d;
double tm;
string a[1000];
int b[1000][1000];

int main()
{
	freopen("c:/input.txt" , "r" , stdin);
	freopen("c:/output.txt" , "w" , stdout);
	
	cin>>test;
	
	for (int t = 1 ; t <= test; t++)
	{
		cin>>n>>m>>d;
		
		for (i = 0; i < n; i++)
			cin>>a[i];

		int ans = 0;
		for (k = 3; k <= min(n,  m); k++)
		{
			k = k;
			for (i = 0; i <= n - k; i++)
				for (j = 0; j <= m - k; j++)
				{
					for (ii = i; ii < i + k; ii++)
						for (jj = j; jj < j + k; jj++)
							b[ii - i][jj - j] = d + a[ii][jj] - '0';


					b[0][k-1] = b[k-1][0] = b[0][0] = b[k-1][k-1] = 0;
					/*
					if (k == 5 && i == 1 && j == 1)
					{
						for (ii = 0; ii < k; ii++)
						{
							for (jj = 0; jj < k; jj++)
								cout<<b[ii][jj]<<" ";

							cout<<endl;
						}
					}
					*/

					int xx = 0 , yy = 0;
					for (ii = 0; ii < k; ii++)
						for (jj = 0; jj < k; jj++)
						{
							xx +=  (k -  2*ii - 1) * b[ii][jj];
							yy +=  (k -  2*jj - 1) * b[ii][jj];
						}

					if (xx == 0 && yy == 0)
					{
						ans = max(ans , k);
					}

				}
		}

		cout<<"Case #"<<t<<""<<": ";

		if (ans == 0)
		{
			cout<<"IMPOSSIBLE\n";
		} else
		cout<<ans<<endl;
	}

	return 0;
}