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
int p[10000] , px[10000];

int main()
{
	freopen("c:/input.txt" , "r" , stdin);
	freopen("c:/output.txt" , "w" , stdout);
	
	cin>>test;

	for  (i = 2; i <= 1000; i++)
		{
			int d = 0;

			for (j = 2; j * j <= i; j++)
				if (i % j == 0)
					d = 1;

			if (d == 0)
				p[i] = 1;
		}

		for (i = 2; i <= 1000; i++)
		{
			if (p[i])
			{
				k = i;
				while (k <= 1000)
				{
					px[k] = 1;
					k = k * i;
				}
			}
		}

		px[1] = 1;
	
	for (int t = 1 ; t <= test; t++)
	{
		
		cin>>n;
		
		int ans = 0;
		for (i = 0; i <= n; i++)
		{
			ans += px[i] - p[i];
		}
		cout<<"Case #"<<t<<""<<": ";
		if (n == 1)
			ans = 0;
		cout<<ans<<endl;
	}

	return 0;
}