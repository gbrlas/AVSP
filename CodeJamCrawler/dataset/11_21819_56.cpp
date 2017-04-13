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

int test ,  i , j, k , c , d;
int s , r , n , x;
double tm;
int a[10000];

int main()
{
	freopen("c:/input.txt" , "r" , stdin);
	freopen("c:/output.txt" , "w" , stdout);
	
	cin>>test;
	
	for (int t = 1 ; t <= test; t++)
	{
		for (i = 0; i <= 100; i++)
			a[i] = 0;
		cin>>x>>s>>r>>tm>>n;
		int sum = 0;
		for (i = 0; i < n; i++)
		{
			int xx , yy , zz;
			cin>>xx>>yy>>zz;
			a[zz] += yy - xx;
			sum += yy - xx;
		}
		a[0] += x - sum;

		double ans = 0;
		for (i = 0; i <= 100; i++)
		{
			double k = a[i];
			if (tm == 0)
			{
				ans += k / (i + s);
			} else
			{
				double tt = k / (i + r);
				if (tm >= tt)
				{
					ans += tt;
					tm -= tt;
				} else
				{
					
					ans += tm;
					
					k -= tm * (i + r);
					ans += k / (i + s);
					tm = 0;
				}
			}

		}


		cout<<"Case #"<<t<<""<<": ";
		printf("%.7lf\n" , ans);
	}

	return 0;
}