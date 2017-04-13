#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;



int i,  j,  k , n , m , pas , ans;
int a[10000] , u[10000];

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

	   sort(a , a + m);

	   int pas = 1000000000;
		
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

	   printf("Case #%d: %d\n" , tt , pas);
        
    }

    return 0;
}