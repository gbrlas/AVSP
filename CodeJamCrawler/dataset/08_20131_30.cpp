#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <sstream>

using namespace std;

#define LL long long 
#define PII pair<int,int> 
#define VI vector<int> 
#define VPII vector<PII> 
#define eps 1e-9
#define inf int(1000000000)

int test,t;
int A,B,p,i,j,k,ans, a[2000][2000],s[2000],l;
int main()
{
	freopen("c:/input.txt","r",stdin);
	freopen("c:/output.txt","w",stdout);
	cin>>test;
	for ( t = 1; t <= test; t++)
	{	
		cin>>A>>B>>p;
			cout<<"Case #"<<t<<": ";

			for (i = 0; i <= 1000; i++)
				for (j = 0; j <= 1000; j++)
					a[i][j] == 0;

			for (i = A; i <= B; i++) 
			{
				k = i; j = 2;
				while (k > 1)
				{
					while (k % j == 0) 
					{
						a[i][j]++;
						k /= j;
					}
					j++;
				}
				s[i] = i - A;
			}

			while (1)
			{
				int d = 0;
				for (i = A; i <= B; i++)
					for (j = A; j < i; j++)
					{
						if (s[i] != s[j])
						{
							for (k = p; k <= B; k++)
								if (a[i][k] && a[j][k])
								{
									d = 1;
									int c = s[j];
									for (l = A; l <= B; l++)
										if (s[l] == c) s[l] = s[i];
										//break;
								}

						}
					}
					if (d == 0 ) break;
			}


			int used[1001]; ans = 0;
			for (i = 0; i <= 1000; i++) used[i] = 0;
			for (i = A; i <= B; i++)
			{
			
				if (used[s[i]] == 0) ans++;
				used[s[i]] = 1;

			}
			
		cout<<ans<<endl;
	
	}
	return 0;
}