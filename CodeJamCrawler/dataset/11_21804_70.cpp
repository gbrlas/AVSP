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

int test ,  i , j,  n, k , c , d;
char u[300][300] , bad[300][300];
int a[10000];
int main()
{
	freopen("c:/input.txt" , "r" , stdin);
	freopen("c:/output.txt" , "w" , stdout);
	
	cin>>test;
	
	for (int t = 1 ; t <= test; t++)
	{
		cin>>n;
		int sum = 0;
		int x = 0;
		for (i = 0; i < n; i++)
		{
			cin>>a[i];
			sum += a[i];
			x ^= a[i];
		}

		sort(a , a + n);

		cout<<"Case #"<<t<<""<<": ";

		if (x != 0)
			cout<<"NO\n"; else
			cout<<sum - a[0]<<endl;
		
	}

	return 0;
}