#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int b[300][300] , a[300][300] , ans[300][300] , num , pas;
int p[4][2] = {{-1 , 0},{0 , -1},{0 , 1},{1 , 0}};

int l , m , n , i , j , nom , jj;

void rec(int x , int  y)
{
	int i , xx , yy , mn = 100000 , nom = -1;
	if (ans[x][y] > 0)
	{
		pas = ans[x][y];
		return;
	}
	for (i = 0; i < 4; i++)
	{
		xx = x + p[i][0];
		yy = y + p[i][1];
		if (xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] < mn)
		{
			mn = a[xx][yy];
			nom = i;
		}
	}

	if (mn < a[x][y])
	{
		rec(x + p[nom][0] , y + p[nom][1]); 
		ans[x][y] = pas ;
	} else
	{
		if (ans[x][y] == 0)
			ans[x][y] = ++num;
		pas = num;
	}
}

int main()
{
	freopen("c:/input.txt" , "r" , stdin);
	freopen("c:/output.txt" , "w" , stdout);
	
	int t;
	cin>>t;

	for (int tt = 1; tt <= t; tt++)
	{
		cin>>n>>m;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				cin>>a[i][j];

		num = 0;
		for (i =0; i < n; i++)
			for (j = 0; j < m; j++)
			{
				ans[i][j] = 0;
			}


		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (ans[i][j] == 0)
					rec(i , j);
			}
		}

		cout<<"Case #"<<tt<<":"<<endl;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m - 1; j++)
				cout<<char(ans[i][j] + 'a' - 1)<<" ";

			cout<<char(ans[i][m-1] + 'a' - 1)<<endl;
		}
	}


	
	
	return 0;
}