#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

#define VI vector<int>
#define PII pair<int,int>
#define f0(i,n) for(i = 0; i < n; i++)
#define eps 1e-9
#define MP make_pair


using namespace std;

double x[1000] , y[1000] , r[1000];
int i , j , k , n , m , p;

double dis(double x , double y , double xx , double yy)
{
	return sqrt( (x - xx)*(x - xx) + (y - yy)*(y - yy) );
}

double solve(int i , int j , int k)
{
	return max(r[i] , (dis(x[j] , y[j] , x[k] , y[k]) + r[j] + r[k]) / 2.0);
}

int main()
{
	freopen("d:/input.txt" , "r" , stdin);
	freopen("d:/output.txt" , "w" , stdout);
	int t;
	cin>>t;
	for (int tt = 0; tt < t; tt++)
	{
		cin>>n;
		for (i = 0; i < n; i++)
			cin>>x[i]>>y[i]>>r[i];

		

		cout<<"Case #"<<tt+1<<": ";
		if (n == 1)
		{
			printf("%.6lf\n" , r[0]);
		} else
			if (n == 2)
			{
				printf("%.6lf\n" , max(r[0] , r[1]));
			} else
				if (n == 3)
				{
					double ans = 1000000000;
					ans = min(ans , solve(0 , 1 , 2));
					ans = min(ans , solve(1 , 0 , 2));
					ans = min(ans , solve(2 , 0 , 1));
					
					printf("%.6lf\n" , ans);
				}


	}
	return 0;
}