#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int b[100][300];
string a[10000] , s;
int l , m , n , i , j , nom , jj;

int main()
{
	freopen("c:/input.txt" , "r" , stdin);
	freopen("c:/output.txt" , "w" , stdout);
	cin>>l>>n>>m;
	for (i = 0; i < n; i++)
	{
		cin>>a[i];
	}

	for (j = 0; j < m; j++)
	{
		cin>>s;
		for (i = 0; i < l; i++)
			for (jj = 'a'; jj <= 'z'; jj++)
				b[i][jj] = 0;

		i = 0;
		nom = 0;
		while (i < s.size())
		{
			if (s[i] == '(')
			{
				i++;
				while (s[i] != ')')
				{
					b[nom][s[i]] = 1;
					i++;
				}
				nom++;
				i++;
			} else
			{
				b[nom++][s[i]] = 1;
				i++;
			}
		}

		int ans = 0;
		for (i = 0; i < n; i++)
		{
			int d = 0;
			
			for (jj = 0; jj < a[i].size(); jj++)
			{
				if (b[jj][a[i][jj]] == 0) d = 1;
			}

			if (d == 0)
				ans++;
		}
		
		cout<<"Case #"<<j+1<<": "<<ans<<endl;
	}
	return 0;
}