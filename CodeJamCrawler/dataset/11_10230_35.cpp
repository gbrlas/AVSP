#include <iostream>
#include <cstdio>

using namespace std;

int t, n;
char c;
int a[1001][1001];
double p, wp[1001][1001], owp[1001], oowp[1001];
int k, num_win[1001], num_lose[1001];


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> t;
	
	cout.setf(ios::fixed);
	cout.precision(10);
	
	for (int i = 0; i < t; i++)
	{
		scanf("%d\n", &n);
		
		cout << "Case #" << i + 1 << ":\n";
		
		fill(num_win, num_win + 1000, 0);
		fill(num_lose, num_lose + 1000, 0);
		
		for (int j = 0; j < n; j++)
		{
			for (int l = 0; l < n; l++)
			{
				scanf("%c", &c);
				
				if (c == '0')
					a[j][l] = -1;
				if (c == '1')
					a[j][l] = 1;
					
				if (c == '.')
					a[j][l] = 0;
					
				if (a[j][l] == 1)
					num_win[j]++;
				
				if (a[j][l] == -1)
					num_lose[j]++;
			}
			
			scanf("\n");
		}
		
		for (int j = 0; j < n; j++)
		{
			for (int l = 0; l < n; l++)
			{
				if (a[j][l] == 1)
					wp[j][l] = double(num_win[j] - 1)/(num_win[j] + num_lose[j] - 1);
					
				if (a[j][l] == -1)
					wp[j][l] = double(num_win[j])/(num_win[j] + num_lose[j] - 1);
					
				if (a[j][l] == 0)
					wp[j][l] = double(num_win[j])/(num_win[j] + num_lose[j]);
			}
		}
		
		
		for (int j = 0; j < n; j++)
		{
			k = 0;
			p = 0;
			
			for (int l = 0; l < n; l++)
			{
				if (a[j][l] == 0) continue;
				
				k++;
				p = p + wp[l][j];				
			}
			
			owp[j] = double(p)/k;
		}
		
		
		
		for (int j = 0; j < n; j++)
		{
			k = 0;
			p = 0;
			
			for (int l = 0; l < n; l++)
			{
				if (a[j][l] == 0) continue;
				
				k++;
				p = p + owp[l];				
			}
			
			oowp[j] = double(p)/k;
		}
		
		
		for (int j = 0; j < n; j++)
		{
			//cout << wp[j][j] << ' ' << owp[j] << ' ' << oowp[j] << endl;
			cout << wp[j][j] * 0.25 + owp[j] * 0.5 + 0.25 * oowp[j] << endl;
		}
			
	}
	
	return 0;
}
