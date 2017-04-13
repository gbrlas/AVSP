#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int b[300][300] , a[600][600] , ans;

int l , m , n , i , j , nom , jj ;
string s1 = "welcome to code jam" , s;


int main()
{
	freopen("c:/input.txt" , "r" , stdin);
	freopen("c:/output.txt" , "w" , stdout);
	
	int t;
	cin>>t;
	getline(cin , s);
	m = s1.size();
	for (int tt = 1; tt <= t; tt++)
	{
		getline(cin , s);
		n = s.size();
		
		for (i = 0; i < n; i++)
			for (j = 0; j <= m; j++)
				a[i][j] = 0;

		a[0][0] = 1;

		for (l = 0; l < m; l++)
		{
			for (i = 0; i < n; i++)
				for (j = i; j < n; j++)
					if (s[j] == s1[l] && a[i][l] > 0)
					{
						a[j][l+1] += a[i][l];
						a[j][l+1] %= 100000;
					}
		}

		ans = 0;
		for (i = 0; i < n; i++)
			ans += a[i][m];

		ans %= 100000;
		string pas = "";
		while (ans != 0)
		{
			pas = char(ans % 10 + '0') + pas;
			ans /= 10;
		}

		while (pas.size() < 4) pas = "0" + pas;
		cout<<"Case #"<<tt<<": "<<pas<<endl;
		
	}


	
	
	return 0;
}