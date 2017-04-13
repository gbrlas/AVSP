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

long long test ,  i , j, m , k , ii , jj , d;
int p[10000000];
long long n;
vector<long long> v;

int main()
{
	freopen("c:/input.txt" , "r" , stdin);
	freopen("c:/output.txt" , "w" , stdout);
	
	cin>>test;

	for (i = 2; i <= 1000000; i++)
	{
		if (p[i] == 0)
		{
			v.push_back(i);
			k = 2 * i;
			while (k <= 1000000)
			{
				p[k] = 1;
				k += i;
			}
		}
	}

	
	for (long long t = 1 ; t <= test; t++)
	{
		
		cin>>n;
		long long ans =  0;
		for (i = 0; i < v.size(); i++)
		{
			long long x = v[i] * v[i];
			while (x <= n)
			{
				ans++;
				x *= v[i];
			}
		}
		

		cout<<"Case #"<<t<<""<<": ";
		ans += 1;
		if (n == 1)
			ans = 0;
		cout<<ans<<endl;
	}

	return 0;
}