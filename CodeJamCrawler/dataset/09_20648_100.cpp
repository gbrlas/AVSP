#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;



int i,  j,  k , n , m , pas , ans;
int a[10000] , u[10000];
int dp[200][200];

int solve(int le , int ri)
{
	int i;
	if (dp[le][ri] != 1000000000)
		return dp[le][ri];

	if (le > ri) return 0;

	for (i = le+1; i < ri; i++)
	{
		dp[le][ri] = min(dp[le][ri] , a[ri] - a[le] - 2 + solve(le,i) + solve(i,ri));
	}

	if (le + 1 >= ri)
		return dp[le][ri] = 0;

	return dp[le][ri];
}

int main()
{
    freopen("d:/input.txt" , "r" , stdin);
    freopen("d:/output.txt" , "w" , stdout);

	int t;
    cin>>t;
	int i;
    for (int tt = 1; tt <= t; tt++)
    {
       cin>>n>>m;
	   for (i = 0; i < m; i++)
		   cin>>a[i];
		
	   a[m++] = 0;
	   a[m++] = n+1;
	   

	   sort(a , a + m);

	   int pas = 1000000000;
		for (i = 0; i <= m; i++)
			for (j = 0; j <= m; j++)
				dp[i][j] = 1000000000;

	   pas = solve(0 , m-1);

	   /*
	   do
	   {
		   ans = 0;
		   for (i = 1; i <= n; i++)
		   {
			   u[i] = 0;
		   }

		   for (i = 0; i < m; i++)
		   {
			   u[a[i]] = 1;
			   j = a[i]-1;
			   while (j >= 1 && u[j] == 0)
			   {
				   ans++;
				   j--;
			   }
			   j = a[i]+1;
			   while (j <= n && u[j] == 0)
			   {
				   ans++;
				   j++;
			   }
		   }

		   pas = min(pas , ans);

		
	   } while (next_permutation(a , a + m));
	   */

	   printf("Case #%d: %d\n" , tt , pas);
        
    }

    return 0;
}