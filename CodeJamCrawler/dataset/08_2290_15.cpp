#include <iostream>
using namespace std;

const int N = 110;
int a[N][N];
int n, m;

const int b[][2] = {1, 2, 2, 1};
const int MOD =  10007;
void read()
{
//	memset(a, 0, sizeof(a));
	int i, j, k;
	cin>>n>>m>>k;
	for(i=1; i<=n; i++)
	   for(j=1; j<=m; j++)
	       a[i][j] = 0;
	while( k-- )
	{
		cin>>i>>j;
		a[i][j] = -1;
	}
}

int dp()
{
	if( a[1][1] == -1)  { a[1][1] = 1; return a[1][1]; }
	int i, j, k, x, y;

	a[1][1] = 1;

	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++)
			if( a[i][j] != -1)
				for(k=0; k<2; k++)
				{
					x = i + b[k][0];
					y = j + b[k][1];
					if( x >= 1 && x <= n && y>=1 && y<=m && a[x][y] != -1)
						a[x][y] += a[i][j];
					if( a[x][y] >= MOD) a[x][y] %= MOD;
				}
	return a[n][m];
}
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int text, i;
	cin>>text;
	for(i=1; i<=text; i++)
	{
		read();
		cout<<"Case #"<<i<<": "<<dp()<<endl;
	}
	return 0;
}
